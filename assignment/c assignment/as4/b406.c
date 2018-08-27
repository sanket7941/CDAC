//b6.write a function to print a given number in hexadecimal format.
#include<stdio.h>
void HEX(int no1);
void main()
{
  int no1,ans;
  printf("Enter the number");
  scanf("%d",&no1);
  HEX(no1);
  //printf("\n%d",ans);
}
void HEX(int no1)
{
  printf("the hexadecimal of %d is:%x\n",no1,no1);
//  return 0;
}
