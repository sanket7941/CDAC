 // mutex  using semaphore

 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <signal.h>
 #include <string.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <sys/sem.h>
 
#define SHM_KEY	0x2809
#define SEM_KEY	0x1506

typedef union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
}semun_t;

typedef struct data
{
	int cnt;
}data_t;

int shmid, semid;
data_t *ptr;

void sigint_handler(int sig)
{
	semctl(semid, 0, IPC_RMID);
	_exit(0);
}

int main()
{
	int pid, i, s, ret;
	struct sigaction sa;
	semun_t su;
	struct sembuf sops[1];

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0)
	{
		perror("sigaction() faile");
		_exit(1);
	}

	// create sema with single counter.
	semid = semget(SEM_KEY, 1, IPC_CREAT | 0600);
	if(semid < 0)
	{
		perror("semget() failed");
		_exit(4);
	}

	// init sema cntr to "1".
	su.val = 1;
	ret = semctl(semid, 0, SETVAL, su);
	if(ret < 0)
	{
		perror("semctl() failed");
		semctl(semid, 0, IPC_RMID);
		_exit(2);
	}

	// create shm.
	shmid = shmget(SHM_KEY, sizeof(data_t), IPC_CREAT | 0600);
	if(shmid < 0)
	{
		perror("shmget() failed");
		semctl(semid, 0, IPC_RMID);
		_exit(2);
	}

	// get ptr to shm rgn
	ptr = shmat(shmid, NULL, 0);
	if(ptr == (void*)-1)
	{
		perror("shmat() failed");
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, 0, IPC_RMID);
		_exit(3);
	}

	// init the count
	ptr->cnt = 0;

	// mark shm for deletion
	ret = shmctl(shmid, IPC_RMID, NULL);

	pid = fork();
	if(pid == 0)
	{ // child -- incr count
		for(i=0; i<10; i++)
		{
			// P(s);
			sops[0].sem_num = 0;
			sops[0].sem_op = -1;
			sops[0].sem_flg = 0;
			ret = semop(semid, sops, 1);
			// ...

			ptr->cnt++;
			printf("child : %d\n", ptr->cnt);

			// V(s);
			sops[0].sem_num = 0;
			sops[0].sem_op = +1;
			sops[0].sem_flg = 0;
			ret = semop(semid, sops, 1);
			// ...

			sleep(1);
		}
		// release ptr of shm rgn
		shmdt(ptr);
		_exit(0);
	}
	else
	{ // parent -- decr count
		for(i=0; i<10; i++)
		{
			// P(s);
			sops[0].sem_num = 0;
			sops[0].sem_op = -1;
			sops[0].sem_flg = 0;
			ret = semop(semid, sops, 1);
			// ...

			ptr->cnt--;
			printf("parent : %d\n", ptr->cnt);

			// V(s);
			sops[0].sem_num = 0;
			sops[0].sem_op = +1;
			sops[0].sem_flg = 0;
			ret = semop(semid, sops, 1);
			// ...

			sleep(1);
		}
		waitpid(pid, &s, 0);
		printf("final count : %d\n", ptr->cnt);
		// release ptr of shm rgn
		shmdt(ptr);
		semctl(semid, 0, IPC_RMID);
	}
	return 0;
}
