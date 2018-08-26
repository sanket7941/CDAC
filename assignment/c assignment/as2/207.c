/*
7. Write a program to display number of days in the given year. Check condition for leap year. A
year is a leap year if it is divisible by 4 but not by 100, except that years divisible by 400 are leap
years.
a. Without using logical operators
b. Using logical operators
c. Conditional operator
*/
#include<stdio.h>
void main()
{
  int y;
  printf("enter the year");
  scanf("%d",&y);
// b. Using logical operators
  if(y%400==0)
    printf("%d is leap year\n",y );
    else if((y%100!=0) && (y%4==0))
      printf("%d is leap year\n",y );
    else
    printf("%d is not a leap year\n",y );

// c. Conditional operator
(y%400==0)?printf("366 days\n"):((y%100!=0) && (y%4==0))?printf("366 days\n"):printf(" 365 days\n");
}
