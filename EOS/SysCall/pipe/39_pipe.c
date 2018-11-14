#include <stdio.h>
#include <unistd.h>

int main()
{
	int ret, arr[2];
	char buf1[32], buf2[32];

	ret = pipe(arr);
	if(ret < 0)
	{
		perror("pipe() failed");
		_exit(1);
	}

	printf("enter a message : ");
	fgets(buf1, sizeof(buf1), stdin);

	write(arr[1], buf1, sizeof(buf1));
	printf("written into pipe : %s\n", buf1);

	read(arr[0], buf2, sizeof(buf2));
	printf("read from pipe : %s\n", buf2);

	close(arr[1]);
	close(arr[0]);
	return 0;
}
