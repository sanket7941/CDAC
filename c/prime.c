//fctors of prime

#include<stdio.h>
void main()
{
  int x,i,flag=0;
  printf("Enter the number");
  scanf("%d",&x);
  for(i=2; i<x ;i++)
  {
    if(x%i==0)
      flag++;
    }
    (flag==0)?printf("%d number is prime \n",x):printf("%d number is not prime\n",x);
}
