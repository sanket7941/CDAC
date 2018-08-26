//2. Write a function to calculate power.

#include<stdio.h>
int power(int a,int b);
void main()
{
	int a,b,ans;
	printf("Enter the number");
	scanf("%d",&a);
  printf("Enter the power");
  scanf("%d",&b);

  ans=power(a,b);
	printf("the ans of %d^%d =%d ",a,b,ans);
}


int power(int a, int b)
{
  int ans=1,i=1;
  while(i<=b)
  {
    ans*=a;
		i++;

  }

return ans;
}
