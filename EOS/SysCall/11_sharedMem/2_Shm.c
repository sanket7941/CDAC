#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 0x2809

typedef struct data
{
  int cnt;
}data_t;

int shmid;

data_t *ptr;

void sigint_handler(int sig) // handler
{
	shmctl(shmid, IPC_RMID, NULL);
	_exit(0);
}

int main ()
{
  int pid, i, s, ret;
  struct sigaction sa;

  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = sigint_handler;
  ret = sigaction(SIGINT, &sa, NULL);
  if(ret < 0)
  {
    perror("sigaction() faile");
    _exit(1);
  }

  // creat shmid

  shmid = shmget(KEY,sizeof(data_t),IPC_CREAT | 0600);
  if(shmid < 0)
	{
		perror("shmget() failed");
		_exit(2);
	}

  // get pointer to shm region

  ptr = shmat(shmid,NULL,0);
  if(ptr == (void*)-1)
	{
		perror("shmat() failed");
		_exit(3);
	}

  //init the count
  ptr->cnt = 0;

  pid =fork();
  if(pid == 0)
  {
    for(i=0; i<10; i++)
		{
			ptr->cnt++;
			printf("child : %d\n", ptr->cnt);
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
			ptr->cnt--;
			printf("parent : %d\n", ptr->cnt);
			sleep(1);
		}
		waitpid(pid, &s, 0);
		printf("final count : %d\n", ptr->cnt);
		// release ptr of shm rgn
		shmdt(ptr);
		// delete shm
		ret = shmctl(shmid, IPC_RMID, NULL);
	}
  return 0;
}
