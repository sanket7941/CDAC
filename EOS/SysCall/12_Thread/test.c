#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* func1(void *param)
{
	int i;
	for(i=0; i<10; i++)
	{
		printf("fn1 : %d\n", i);
		sleep(1);
	}
	return NULL;
}

void* func2(void *param)
{
	int i;
	for(i=0; i<10; i++)
	{
		printf("fn2 : %d\n", i);
		sleep(1);
	}
	return NULL;
}

int main()
{
	int i, ret;
	pthread_t t1, t2;
	pthread_attr_t a1, a2;

	pthread_attr_init(&a1); // init to default attributes
	pthread_attr_setscope(&a1, PTHREAD_SCOPE_PROCESS);
	ret = pthread_create(&t1, &a1, func1, NULL);

	pthread_attr_init(&a2); // init to default attributes
	pthread_attr_setscope(&a2, PTHREAD_SCOPE_PROCESS);
	ret = pthread_create(&t2, &a2, func2, NULL);

	for(i=0; i<10; i++)
	{
		printf("main: %d\n", i);
		sleep(1);
	}

	pthread_attr_destroy(&a1);
	pthread_attr_destroy(&a2);
	return 0;
}
