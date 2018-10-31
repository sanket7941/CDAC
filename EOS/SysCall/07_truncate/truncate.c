#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc , char *argv[])
{
	int num = atoi(argv[2]);
	
	truncate(argv[1],num);
	printf("\n the number is %d \n",num);
	return 0;
}

