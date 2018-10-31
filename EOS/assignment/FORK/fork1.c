#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	// #if 0
	static x = 1;
	int ret = fork();

	// printf(" ret = %d\n",ret);
	if (ret == 0) {		printf("Child has x = %d\n", ++x); sleep(1); }
	else {	printf("Parent has x = %d\n", x++); sleep(1);}
	// printf(" ans = %d\n",x);

	// #endif
	return 0;

}
