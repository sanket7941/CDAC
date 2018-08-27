#include<stdio.h>
int fact(int x);
void main()
{

  /*
  n==row number
  r==col number
  */
  int row,col,n,r,ans,k;
  printf("enter the number row ");
  scanf("%d",&row);
  // printf("enter the number col");
  // scanf("%d",&col);
  for(n=0;n<=row;n++)
  {
    for(k=n;k<=row;k++)
    {
      printf("  ");
    }
    for(r=0d;r<=row ;r++)
    {
      ans=((fact(n))/(fact(r)*(fact(n-r))));
      printf("%3d ",ans);
    }
    printf(" \n ");
  }
}
int fact(int x)
{
  int i=1,fact=1;
  for( i=1;i<=x;i++)
  {
    fact=fact*i;
  }
  return fact;
}
