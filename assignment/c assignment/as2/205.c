// Write a program to find maximum of three numbers using
// a. If – else
// b. conditional operator.
#include<stdio.h>
void main()
{
  int a,b,c;
  printf("enter the  number 1\n" );
  scanf("%d",&a);
  printf("enter the  number 2\n" );
  scanf("%d",&b);
  printf("enter the  number 2\n" );
  scanf("%d",&c);

  if(a==b && b==c)
    printf("%d , %d and %d are eqal",a,b,c);
    else if(a>b && a>c)
    printf("%d isgretor then %d and %d ",a,b,c);
    else if(b>a && b>c)
    printf("%d isgretor then %d and %d ",b,a,c);
  else
  printf("%d isgretor then %d and %d ",c,a,b);

// ******************* using conditional oprator*****************
  // (a==b)?printf("\n%d and %d are eqal",a,b):(a<b)?printf("\n%d is smaller then %d ",a,b):printf("\n%d is greter then %d ",a,b);
}
