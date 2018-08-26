/*Write a program to accept a 4 digit number and
a. Display face value of each decimal digit
b. Display place value of each decimal digit
c. Display no in reverse order by changing decimal place values
If user enters a 4 digit number 9361 output should be
a. 9       3       6    1
b. 9361 = 9 000 + 300 + 60 + 9
c. 1639
*/
#include<stdio.h>
void main()
{
  int x,x1,x2,face,rem,rev;
  printf("enter the 4digit number\n");
  scanf("%d",&x);
  x1=x2=x;

// reverse the number

  while(x2!=0)
  {
    rem=x2%10;
    rev=rev*10+rem;
    x2=x2/10;
  }
  printf("%d",rev);

}
