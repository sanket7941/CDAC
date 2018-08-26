// 6. Write a program to accept a 5 digit number and check whether it is a numeric palindrome.
#include<stdio.h>
void main()
{
  int x1,x2,rem,rev;
  printf("enter the 5 digit number\n");
  scanf("%d",&x1);
  x2=x1;

// reverse the number

  while(x2!=0)
  {
    rem=x2%10;
    rev=rev*10+rem;
    x2=x2/10;
  }
  if(x1==rev)
  printf("%d is palindrome\n",x1);
  else
  printf("%d is not a palindrome\n",x1 );
}
