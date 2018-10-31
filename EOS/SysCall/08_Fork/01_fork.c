#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void child_task(int ch)
{
	int i;
	for(i=0; i<5; i++)
	{
		printf("porga %d (%d,%d) : %d\n", ch, getpid(), getppid(), i);
		sleep(1);
	}
}

int main(void)
{
	int porga1,porga2,porga3,s;

	printf("parent\n PID=%d PPID =%d \n",getpid(),getppid() );
	porga1 = fork();

	if (porga1 == 0)
	{
		printf("PID=%d PPID =%d \n",getpid(),getppid() );
		porga2 = fork();
		if(porga2 == 0)
		{
			printf("PID=%d PPID =%d \n",getpid(),getppid() );
			porga3 = fork();
			if(porga3 == 0)
			{
				child_task(3);
				printf("PID=%d PPID =%d \n",getpid(),getppid() );
				_exit(0);
			}// child 3
			child_task(2);
			waitpid (porga3 , &s , 0);
			printf("porga 3 maran pavlaaa :( %d \n",WEXITSTATUS(s));
			_exit(0);
		}//child 2
		child_task(1);
	waitpid (porga2 , &s , 0);
	printf("porga 2 maran pavlaaa :( %d \n",WEXITSTATUS(s));
	_exit(0);
} //child 1
	waitpid (porga1 , &s , 0);
	printf("porga 1 maran pavlaaa :( %d \n",WEXITSTATUS(s));

return 0;
}
