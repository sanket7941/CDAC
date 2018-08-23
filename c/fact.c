// factorial no

#include<stdio.h>
int main()
{
  int x,i,fact;
  printf("enter the number");
  scanf("%d",&x);

  for( i =1;i<x;i++)
  {
    fact=fact*i;
  }
  printf("the factorial of number %d is : %d",x,fact);
}
