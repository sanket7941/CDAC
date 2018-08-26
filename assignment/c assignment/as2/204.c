// 4. Write a program to find maximum of two numbers using
// a. If – else
// b. conditional operator.
#include<stdio.h>
void main()
{
  int a,b;
  printf("enter the  number 1\n" );
  scanf("%d",&a);
  printf("enter the  number 2\n" );
  scanf("%d",&b);
  /*
  if(a==b)
    printf("%d and %d are eqal",a,b);
    else if(a<b)
    printf("%d is smaller then %d ",a,b);
  else
    printf("%d is greter then %d ",a,b);
*/
// ******************* using conditional oprator*****************
  (a==b)?printf("\n%d and %d are eqal",a,b):(a<b)?printf("\n%d is smaller then %d ",a,b):printf("\n%d is greter then %d ",a,b);
}
