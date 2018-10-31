#include<stdio.h>
#include<unistd.h>

int main(void)
{
	int x;

	x= fork();

	if(x == 0)
	{
		printf("chaild is noughty \n");
	}
	else
	{
		printf("parents are shy\n");
	}
	return 0;
}
