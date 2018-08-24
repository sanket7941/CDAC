// factors
#include<stdio.h>
void main()
{
  int x,fact,i;
  printf("Enter the number");
  scanf("%d",&x);
  for(i=2;i<=x;i++)
  {
    if(x%i==0)
    {
        printf("%3d",i);
    }
  }
}
