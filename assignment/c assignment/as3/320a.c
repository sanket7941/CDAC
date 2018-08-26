// 20. Write a program to display
// a. Prime numbers between 1 to 100
// b. Armstrong Numbers between 1 to 500s
#include<stdio.h>
void main()
{
  int i,j,LR,HR;
  printf("Enter the range ");
  scanf("%d %d",&LR,&HR);
  for(i=LR; i<=HR; i++)
	{
		for(j=2; j<i;j++)
		{
			if(i%j==0)
				break;
		}
		if(j==i)
				printf("%d\n", i);
  }
}
