#include<stdio.h>
int GCD(int n1, int n2);
int main()
{
	int i,n1,n2,ans;
	printf("enter 2 numbers");
	scanf("%d %d",&n1,&n2);

	for(i=1;i<=n1||i<= n2;i++)
		{
			if(n1%i==0 && n2%i==0)
		{
			ans=i;
		}
		}
		printf("GCD :: %d",ans);
return 0;
}

int GCD(int n1, int n2)
{
	for(i=1;i<=n1||i<= n2;i++)
		{
			if(n1%i==0 && n2%i==0)
		{
			ans=i;
		}
	}
}
