//write a function to calculate power using recursion.
#include<stdio.h>
int power(int no, int p);
void main()
{
  int a,p,ans;
  printf("Enter the number and power");
  scanf("%d%d",&a,&p);
  ans=power(a,p);
  printf("\n%d",ans);
}


int power(int no, int p)
{
  if(p!=0)
  {
    return (no*power(no,(p-1)));
  }
  else
    return 1;
}
