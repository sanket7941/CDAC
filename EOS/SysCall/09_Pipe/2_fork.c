#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSG 30

int main()
{
	char buff[MSG];

	int p[2],pid,nbytes;

	if((pid =fork()) == 0)
	{

		write(p[1]," khaike PAN banarasss wallllaaa!!!",MSG);
		
	}


	read(p[0],buff,MSG);

	printf("the msg recived is \n");
	printf("%s \n ",buff);

	return 0;
}

	
