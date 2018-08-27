//1.Write a function to calculate factorial of a given number using recursion.
#include<stdio.h>
int fact(int x);
void main()
{
  int x;
  printf("enter the number");
  scanf("%d",&x);
  printf("the factorial of %d are:",x);
  fact(x);
}
int fact(int x)
{
  int ans;
  if (x!=0)
  {
    printf("%3d ",x);
    if(x>1){
    printf(" * " );}
    ans=(fact(x-1));

  }

}
