//  10. Write function to check whether given year is leap or not. Write another function to print
// number of days in given month.

#include<stdio.h>
void leap(int y);
void main()
{
  int y,i,j;
  printf("enter the year");
  scanf("%d",&y );

  leap(y);
}

void leap(int y)
{
  if(y/400==0)
  printf("%d is leap year",y);
    else if(y/4==0 && y/100!=0)
      printf("%d is leap year",y);
    else
    printf("%d is not leap year",y);
}
