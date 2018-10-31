#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
int ret ,s ,err;

printf("parent\n");

ret = fork();

if(ret == 0)
{
	err = execl("./sum","sum",NULL);
	printf("%d\n",err );
}

waitpid(ret ,&s,0);

return 0;
}
