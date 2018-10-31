#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
	int i;
	for(i=0; envp[i]!=NULL; i++)
	{
		printf("child : %s\n", envp[i]);
		sleep(1);
	}
	return 0;
}
