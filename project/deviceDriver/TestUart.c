#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char buf[64];
	int fd, ret,sw;

	printf("press 1 for write data \npress 2 for read data");
	scanf("%d",&sw);
	switch (sw)
	 {
		case 1 :		/**************** write data *************/
								fd = open("/dev/uart0", O_WRONLY);
								if(fd < 0)
								{
									perror("open() failed");
									_exit(1);
								}

								strcpy(buf,"sanket was hear");
								ret = write(fd, buf, 15);
								printf("ret value = %d\n",ret);
								printf("data written.\n");
								getchar();
								// break;
		case 2:		/************* read data ******************/
								fd = open("/dev/uart0", O_RDONLY);
								if(fd < 0)
								{
									perror("open() failed");
									_exit(1);
								}

								ret=read(fd, buf, 15);
								printf("ret value = %d\n",ret);
								buf[15] = '\0';
								printf("Read data from buffer=> %s.\n", buf);
								getchar();
								break;
		default: printf("enter valid data\n" );

	 }

	close(fd);
	return 0;
}
