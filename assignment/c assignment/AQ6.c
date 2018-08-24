/*6. Write a program to accept an integer value and print its table.*/

#include<stdio.h>

void main()
{
int x,i=1;
printf("Enter the value");
scanf("%d",&x);

while(i<=10)
{
	int table=i*x;
	printf("%d \n",table);
	i++;

}
}
