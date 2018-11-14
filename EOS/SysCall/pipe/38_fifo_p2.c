#include "38_fifo.h"

//p2 -- reader
int main()
{
	int fd;
	char str[32];
	printf("p2: program started!\n");
	fd = open(FIFO_PATH, O_RDONLY);
	if(fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	printf("p2: waiting for message...\n");

	read(fd, str, sizeof(str));
	printf("p2: message received : %s.\n", str);

	close(fd);
	return 0;
}

