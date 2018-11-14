#include "38_fifo.h"

//p1 -- writer
int main()
{
	int fd;
	char str[32];
	printf("p1: program started!\n");
	fd = open(FIFO_PATH, O_WRONLY);
	if(fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	printf("p1: enter a message : ");
	fgets(str, sizeof(str), stdin);

	write(fd, str, sizeof(str));
	printf("p1: message sent.\n");

	close(fd);
	return 0;
}

