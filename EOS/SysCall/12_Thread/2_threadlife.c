#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *Del(void *val)
 {
   int i;
   for (i = 0; i < 100; i++)
   {
     printf("F1:: %d\n",i);
    sleep(1);
   }

 }
 void *Dal(void *val)
  {
    int i;
    for (i = 0; i < 100; i++)
    {
      printf("F2::%d\n",i);
     sleep(1);
    }

  }

 int main()
 {
   printf("programm started\n" );

   pthread_t T1,T2;
   int i;
   pthread_create(&T1,NULL,Del,NULL);
   pthread_create(&T2,NULL,Dal,NULL);
   for (i = 0; i < 100; i++)
   {
     printf("F2::%d\n",i);
    sleep(1);
   }

   sleep(3);
   printf("Program ended\n");

   pthread_attr_destroy(&T1);
   pthread_attr_destroy(&T2);
   return 0;

 }
