/*4. Write a program to print following pattern.
a. Using multiple printf statements
b. Using single printf statement
*
**
***
****
*****

// B
#include<stdio.h>
void main()
{
 int i,j;

 for(i=0;i<=5;i++)
{	 for(j=0;j<i;j++)
{
		 printf(" * ");
}
printf("\n");
}
}
*/
// A
#include<stdio.h>
  void main()
 {
printf("*\n");
printf("* *\n");
printf("* * *\n");
printf("* * * *\n");
printf("* * * * *\n");
 }
