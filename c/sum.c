//sumation of the number

#include<stdio.h>
int main()
{
  int x,i,sum;
  printf("Enter the number");
  scanf("%d",&x);
  for(i=0;i<=x;i++)
  {
    sum+= i;
    printf("%d\n",sum);
  }

}
