// 4. Write a program to find factorial of given number.
// Input: 5
// Output: 1 * 2 * 3 * 4 * 5 = 120
#include<stdio.h>
int main()
{
  int x,i,fact=1;
  printf("enter the number");
  scanf("%d",&x);

  for( i =1;i<=x;i++)
  {
    fact=fact*i;
    printf("%d",i);
    if(i<x)
      printf(" * ");
  }
  printf(" = %d",fact);

}
