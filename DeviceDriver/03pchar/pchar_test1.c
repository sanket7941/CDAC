#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char buf[1024];
	int fd, ret;

	fd = open("/dev/pchar0", O_WRONLY);
	if(fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	strcpy(buf, "Hello");
	write(fd, buf, 5);
	printf("Hello written.\n");
	getchar();

	strcpy(buf, "DESD");
	write(fd, buf, 4);
	printf("DESD written.\n");
	getchar();
	
	strcpy(buf, "Bye");
	write(fd, buf, 3);
	printf("Bye written.\n");
	getchar();

	memset(buf, 'A', sizeof(buf));
	ret = write(fd, buf, 512);
	printf("A *512 times written & return value = %d.\n", ret);
	getchar();

	strcpy(buf, "Xyz");
	ret = write(fd, buf, 3);
	printf("Xyz written & return value = %d.\n", ret);
	getchar();
	
	close(fd);
	return 0;
}
