//1. Write a function to calculate factorial of a given number.

#include<stdio.h>
int fact(int a);
void main()
{
	int x,ans;
	printf("Enter the number");
	scanf("%d",&x);
	fact(x);
}

int fact(int a)
{
  int i,fact=1;
  for( i =1;i<=a;i++)
  {
      fact=fact*i;//printf("\n %d",fact);
  }
 printf("the factorial of number %d is : %d",a,fact);
}
