#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define SEM_KEY 0x2405

typedef union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
}semun_t;

void sunbeam()
{
	char *s = "Hola it's wonderfull day :)\n";
	int i;
	for(i=0; s[i]!='\0'; i++)
	{
		putchar(s[i]);
		fflush(stdout);
		sleep(1);
	}
}

void infotech()
{
	char *s = "Who cares let's sleep -_-\n";
	int i;
	for(i=0; s[i]!='\0'; i++)
	{
		putchar(s[i]);
		fflush(stdout);
		sleep(1);
	}
}

int main()
{
	int s, pid, semid, ret;
	semun_t su;
	struct sembuf sops[1];

	// create sem with single counter
	semid = semget(SEM_KEY, 1, IPC_CREAT | 0600);
	if(semid < 0)
	{
		perror("semget() failed");
		_exit(1);
	}

	// init sem to 0 : s=0
	su.val = 0;
	ret = semctl(semid, 0, SETVAL, su);
	// err check ...

	pid = fork();
	if(pid == 0)
	{
		// P(s);
		sops[0].sem_num = 0;
		sops[0].sem_op = -1;
		sops[0].sem_flg = 0;
		ret = semop(semid, sops, 1);
		// err check ...

		infotech();
		_exit(0);
	}
	else
	{
		sunbeam();
		// V(s);
		sops[0].sem_num = 0;
		sops[0].sem_op = +1;
		sops[0].sem_flg = 0;
		ret = semop(semid, sops, 1);

		// err check ...
		waitpid(pid, &s, 0);
		// destroy semaphore
		semctl(semid, 0, IPC_RMID);
	}
	return 0;
}
