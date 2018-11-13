#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

	char *ptr;
	ptr = strtok(argv, ",.");
	printf("Token = %s\n", ptr);
	do
	{
		ptr = strtok(NULL, ",.");
		printf("Token = %s\n", ptr);
	}while(ptr != NULL);
	return 0;
}w
