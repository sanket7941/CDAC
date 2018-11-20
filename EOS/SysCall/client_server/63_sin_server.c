#include "63_sin.h"
// sudo systemctl status firewalld.service
int main() // server
{
	int lsfd, fd, ret;
	struct sockaddr_in svr_addr, cli_addr;
	socklen_t len = sizeof(cli_addr);
	char buf[64];

	lsfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lsfd < 0)
	{
		perror("server:socket() failed");
		_exit(1);
	}
	printf("server: listening socket is ready...\n");

	memset(&svr_addr, 0, sizeof(svr_addr));
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(SVR_PORT);
	inet_aton(SVR_IP, &svr_addr.sin_addr);
	ret = bind(lsfd, (struct sockaddr*)&svr_addr, sizeof(svr_addr));
	if(ret < 0)
	{
		perror("server:bind() failed");
		_exit(1);
	}
	printf("server: listening socket addr assigned...\n");

	listen(lsfd, 5);

	memset(&cli_addr, 0, sizeof(cli_addr));
	fd = accept(lsfd, (struct sockaddr*)&cli_addr, &len);
	if(fd < 0)
	{
		perror("server:accept() failed");
		_exit(1);
	}
	printf("server: client connection is accepted...\n");

	do {
		read(fd, buf, sizeof(buf));
		printf("client: %s", buf);

		printf("server: ");
		fgets(buf, sizeof(buf), stdin);
		write(fd, buf, strlen(buf)+1);
	} while(strcmp(buf, "bye\n") != 0);

	close(fd);
	printf("server: good bye!\n");

	shutdown(lsfd, SHUT_RDWR);

	return 0;
}
