/*1.Write a program to accept a character and a number, and print the character number times
Input:
Character: *
Number: 6
Output:
******
*/
#include<stdio.h>
void main()
{
	int a,i=0;
	printf("enter the number");
	scanf("%d",&a);
	while(i<a)
	{
		printf(" * ");
		i++;
	}
  
}
