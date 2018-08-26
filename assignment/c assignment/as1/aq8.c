//8. Write a program to accept three integer numbers and find its average.
#include<stdio.h>
void main()
{
  int x,x1,x2,avg;
  printf("enter the 3 number\n");
  scanf("%d %d %d",&x,&x1,&x2);
  avg=(x+x1+x2)/3;
  printf(" the avrage of  3 number %3d %3d %3d =%3d\n",x,x1,x2,avg);
  
}
