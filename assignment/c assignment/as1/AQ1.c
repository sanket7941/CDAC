/*
. Write a program to Accept two numbers and
a. find its sum.
b. find its difference.
c. find its product.
Test the program using different integral data type signed/unsigned char/int/long.
First test the result using small values. Then test the same program using large values.
Observe the results.*/
#include<stdio.h>
void main()
{
  int x,y;
  printf("enter two number");
  scanf("%d%d",&x,&y);

  int sum=x+y;
  printf("sum of %d and %d = %d\n",x,y,sum );

  int diff=x-y;
  printf("difference of %d and %d = %d\n",x,y,diff );
  int pro =x*y;
  printf("product of %d and %d = %d\n",x,y,pro );

}
