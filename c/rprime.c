//range of prime prime

#include<stdio.h>
void main()
{
  int LR,HR,i,j;
  printf("Enter the range ");
  scanf("%d %d",&LR,&HR);
  for(i=LR; i<HR ;i++)
  {
    for(j=2;j<i;j++)
    {
      if(i%j!=0)
        printf("%2d",i);
    }
  }
    //(flag==0)?printf("%d number is prime \n",x):printf("%d number is not prime\n",x);
}
