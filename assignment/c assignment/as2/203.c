// 3. Write a program to accept number and check whether the number is +ve, -ve and zero.
#include<stdio.h>
void main()
{
  int a;
  printf("enter the number\n" );
  scanf("%d",&a);
  if(a==0)
    printf("%d is zero",a);
    else if(a<0)
    printf("%d is negative number",a);
  else
    printf("%d is positive number",a);
}
