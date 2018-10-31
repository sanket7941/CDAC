#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
int sum ,num1=10,num2=20;
sum=num1+num2;

printf("sum of num1::%d + num2::%d = %d\n",num1,num2,sum );

}
