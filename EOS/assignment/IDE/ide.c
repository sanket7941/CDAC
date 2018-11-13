#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int GCC,OP,EX,s;
	printf("IDE started!!!\n");
	GCC = fork();
	if ( GCC == 0)
	{
		GCC = execl("/usr/bin/gcc", "gcc", "-c",argv[1],argv[2],NULL);
		if(GCC < 0)
		{
			perror("exec() failed");
			_exit(1);
		}
  }
  waitpid(GCC, &s, 0);
    OP = fork();
    if (OP == 0)
    {
      OP = execl("/usr/bin/gcc", "gcc","-o","program","Main.o","Employee.o",NULL);
      if(OP < 0)
  		{
  			perror("obj creation  failed");
  			_exit(1);
  		}

    }
    waitpid(OP, &s , 0);
    EX = fork();
    if(EX==0)
    {
      EX = execl("./program","program",NULL);
      if(EX < 0)
      {
        perror("Excution  failed");
        _exit(1);
      }
    }
    waitpid(EX, &s, 0);

	printf("parent finished!\n");
	return 0;
}
