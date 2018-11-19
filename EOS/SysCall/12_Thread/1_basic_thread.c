#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include <stdlib.h>

void *print( void *val)
{
  printf("Cause you're a sky, 'cause you're a sky full of stars  \n" );
  sleep(1);
  printf("'m gonna give you my heart  \n");
  sleep(1);
  printf(" 'Cause you're a sky, 'cause you're a sky full of stars \n");
  sleep(1);
  printf("Cause you light up the path \n");
  sleep(1);
  printf(" I don't care, go on and tear me apart\n");
  sleep(1);
  printf("I don't care if you do ooh ooh \n");
  return 0;
  sleep(1);
}

 int main(int argc, char const *argv[]) {
  pthread_t thread_id;
  printf("before thread\n");
  pthread_create(&thread_id,NULL,print,NULL);
  pthread_join(thread_id,NULL);
  printf("After thread\n" );

  return 0;
}
