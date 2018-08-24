/*
 * 2.
 * Write a program to accept a number and print the number in character, decimal, octal and hex
 * formats.
 */
#include<stdio.h>

void main()
{
	int x;

	printf("enter the number\n");
	scanf("%d",&x);
	 
	printf("character %c \n",x);

	printf(" decimal %d \n",x);

	printf(" octal %o \n",x);

	printf("hex %x \n",x);
}

