// 6. Write a program to accept a number and print all factors excluding the number
// Input: 24
// Output: all factors: 1, 2, 3, 4, 6, 8, 12
#include<stdio.h>
void main()
{
  int x,fact,i;
  printf("Enter the number");
  scanf("%d",&x);
  for(i=1;i<x;i++)
  {
    if(x%i==0)
    {
        printf("%3d",i);
    }

  }
  printf("\n",i);
}
