/*
        1 1
      2 1 1 2
    3 2 1 1 2 3
  4 3 2 1 1 2 3 4
*/
#include<stdio.h>
void main()
{
  int q=5;
  //printf("enter the number");
  //scanf("%d",&q);
  int i,j,k;
  // First loop*******************************************
  for(i=0;i<=q;i++)
    {
      for(j=q;j>i;j--)
      {
        printf("   ");
      }
      for(j=i;j>=1;j--)
      {
        printf("%2d ",j);
      }
      for(k=2;k<=i;k++)
      {
        printf("%2d ",k);
      }

      printf("\n");
    }
    // Second loop*************************************
    for(i=q;i>=1;i--)
      {
        for(j=q;j>i;j--)
        {
          printf("   ");
        }
        for(j=i;j>=1;j--)
        {
          printf("%2d ",j);
        }
        for(k=2;k<=i;k++)
        {
          printf("%2d ",k);
        }

        printf("\n");
      }
}
