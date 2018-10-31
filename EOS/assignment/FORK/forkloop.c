#include<stdio.h>
#include<unistd.h>

int main(void)
{
	int ret ,i;

	ret= fork();

	if(ret == 0)
	{	// child process
		for(i=0; i<3; i++)
			printf("child : %d\n", i);
			exit(1);
	}
	else
	{	// parent process
		for(i=0; i<3; i++)
			printf("parent : %d\n", i);
	}
	printf("1program finished!\n");
	printf("2program finished!\n");
	printf("3program finished!\n");
	printf("4program finished!\n");
	printf("5program finished!\n");
	printf("6program finished!\n");
	printf("7program finished!\n");

		
		
		
		
		return 0;
}

