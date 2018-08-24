/*3. Print the ASCII value of user entered character in decimal, hex, octal 
 * format and also print the
 * character for user entered ASCII value
 */
#include<stdio.h>

void main()
{
	char x,y;
	printf("enter the caracter");
	scanf("%c",&x);

	printf("ASCII Decimal value for %c is %d\n",x,x);
	
	printf("ASCII HEX value for%c is %x\n",x,x);

	printf("ASCII OCATAL value for %c is %o\n",x,x);
    
	printf("enter the ASCII value\n");
	scanf("%d",&y);

	printf("Character for %d is %c",y,y);
}

