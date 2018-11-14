#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int ret, arr[2], pid, s;
	char buf1[32], buf2[32];

	ret = pipe(arr);
	if(ret < 0)
	{
		perror("pipe() failed");
		_exit(1);
	}

	pid = fork();
	if(pid == 0)
	{ // child -- writer
		close(arr[0]);

		printf("child: enter a message : ");
		fgets(buf1, sizeof(buf1), stdin);

		write(arr[1], buf1, sizeof(buf1));
		printf("child: written into pipe : %s\n", buf1);
	
		close(arr[1]);
	}
	else
	{ // parent -- reader
		close(arr[1]);

		printf("parent: waiting for message...\n");

		read(arr[0], buf2, sizeof(buf2));
		printf("parent: read from pipe : %s\n", buf2);
		
		waitpid(pid, &s, 0);
		close(arr[0]);
	}

	return 0;
}
