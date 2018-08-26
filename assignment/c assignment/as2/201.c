// 1. Write a program to accept two numbers and display division of the two numbers. Check for
// divide by zero error. If divider is zero then display appropriate error message.

#include<stdio.h>
void main()
{
  double x1,x2,ans;
  printf("Enter any 2 numbers");
  scanf("%lf %lf",&x1,&x2);
  if(x2==0)
    printf("Error cannot divide by 0");
  else
    {
      ans=x1/x2;
      printf("%3lf / %3lf = %3lf",x1,x2,ans);
    }
}
