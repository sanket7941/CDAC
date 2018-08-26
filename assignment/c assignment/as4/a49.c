/*
9. Write a function to indicate whether given number is prime or it.
   Write aither function to print prime numbers in the given range.
*/
#include<stdio.h>
void prime(int x);
void primerange(int LR,int HR);
void main()
{
  int x,LR,HR;
//  printf("Enter the number");
//  scanf("%d",&x);
  //prime(x);
  printf("Enter the range ");
  scanf("%d %d",&LR,&HR);
  primerange(LR,HR);
}
//*********************** function ***********************************
void prime(int x)
{
  int i,flag=0;

  for(i=2; i<x ;i++)
  {
    if(x%i==0)
      flag++;
    }
    (flag==0)?printf("%d number is prime \n",x):printf("%d number is it prime\n",x);
}

void primerange(int LR,int HR)
{
  int i,j,flag=0;
  for(i=LR; i<=HR; i++)
	{
		for(j=2; j<i;j++)
		{
			if(i%j==0)
				break;
		}
		if(j==i)
				printf("%d\n", i);
	}
}
