/* int rhis program we are performing basic pip opration
 *
 */

#include <stdio.h>
#include <unistd.h>


#define MSG 20
int main()
{

	char buff[MSG];

	int p[2],i;

	if(pipe(p) < 0)
		{ 
			_exit(0);
		}

	// write message in pipe
	
	write(p[1],"mi huun DON ",MSG);

	// read message from pipe

	read(p[0],buff,MSG);

	printf("the message=%s",buff);

	return 0;
}


