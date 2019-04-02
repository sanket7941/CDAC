#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main()
{
	char buf[64];
	int fd, ret,sw;


	do {
		printf("press 1 for Send data \n");
		printf("press 2 for Read data \n");
		scanf("%d",&sw);

		switch (sw)
		{
			case 0 :    break;
			case 1 :		/**************** write data *************/
				    fd = open("/dev/uart0", O_WRONLY |O_TRUNC );
				    if(fd < 0)
				    {
					    perror("open() failed");
					    _exit(1);
				    }
				    //printf("Enter the data you want to send over UART\n");
				    //fgets(buf, 64, stdin);
				    strcpy(buf,"Data from PC");
				    ret = write(fd, buf, 64);
				    printf("ret value = %d\n",ret);
				    printf("data written.\n");
				    getchar();

				    break;
			case 2:		/************* read data ******************/
				    fd = open("/dev/uart0", O_RDONLY | O_TRUNC );
				    if(fd < 0)
				    {
					    perror("open() failed");
					    _exit(1);
				    }

				    ret=read(fd, buf, 64);
				    printf("ret value = %d\n",ret);
				    buf[64] = '\0';
				    printf("Read data from buffer=> %s.\n", buf);
				    getchar();
				    break;

			default: printf("enter valid data\n" );

		}
	}	while(sw != 0);

	close(fd);
	return 0;
}
