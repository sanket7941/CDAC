/*
  this program will write the on the shared memory
*/

#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
  key_t key =ftok("shm",65);

int shmid = shmget(key,1024,0666|IPC_CREAT );

char *str = (char*) shmat(shmid,(void*)0,0);

printf("Write Data\n");

gets(str);

printf("Data written in memory: %s\n",str);

    //detach from shared memory
    shmdt(str);

    return 0;
}
