/*13. Write a program to display n terms of Fibonacci series
 * Input: 6
 * Output: 1, 1, 2, 3, 5, 8
 */

#include<stdio.h>
void main()
{
	int pre=0,x,i,pst=1;
	printf("enter the number");
	scanf("%d",&x);

	for( i=1;i<x;i++)
	{

		i=pre+i;
		pre=i;
		printf("%3d",pst);
	}

}
