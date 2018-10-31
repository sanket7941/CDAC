#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char  *argv[])
{
	if(argv !=2)
	{
  mkdir(argv[1],0777);
	}
  return 0;
}
