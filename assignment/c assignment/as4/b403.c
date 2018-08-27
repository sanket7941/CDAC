//3.Write a function to calculate GCD of given numbers using recursion.
#include<stdio.h>
int GCD(int no1, int no2);
void main()
{
  int no1,no2,ans;
  printf("Enter two number");
  scanf("%d%d",&no1,&no2);
  ans=GCD(no1,no2);
  printf("\n%d",ans);
}
int GCD(int no1,int no2)
{
  if (no2 != 0)
       return GCD(no2, no1%no2);
    else
       return no1;
}
