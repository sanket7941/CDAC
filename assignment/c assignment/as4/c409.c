//8.Write a function to swap two numbers.
#include<stdio.h>
int SWAP(int *a,int *b);
void main()
{
  int a,b;
  printf("enter 2 number\n");
  scanf("%d %d",&a,&b);

  printf("before a=%d b=%d \n",a,b);
  SWAP(&a,&b);
  printf("after a=%d b=%d \n",a,b);
}
int SWAP(int *a,int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return ;
}
