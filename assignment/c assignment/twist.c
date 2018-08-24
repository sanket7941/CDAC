//11.
/*
#include<stdio.h>
int main(int  argc, char *argv[], char *envp[])
{
	printf("\t\t\t%c - %d \n", 'A', 'A');
	return 0;
}
*/
/*
//12.
#include<stdio.h>
int main(void)
{
	int i = 0;

	for (i = 0; i<20; i++)
	{
		switch (i)
		{
			case 0:i += 5;
			case 1:i += 2;
			case 5:i += 5;
			default: i += 4;
                        break;   // continue
		}
		printf("%5d", i);
	}
	printf("\n");
	return 0;
}*/
  // code

//13.
/*
#include<stdio.h>
int main(void)
{
	int i = 0;

	for (i = 0; i<20; i++)
	{
		switch (i)
		{
			case 0:i += 5; break;
			case 1:i += 2; break;
			case 5:i += 5; break;
			default: i += 4;break;
		}
		printf("%5d", i);
	}
	printf("\n");
	return 0;
}
*/



//14
/*
#include<stdio.h>
int main(void)
{
	char ch = 'A';
	while (ch <= 'F')
	{
		switch (ch)
		{
			case 'A':
			case 'B':
			case 'C':
			case 'D': ch++;	break;
			case 'E':
			case 'F': ch++;
			default: ;
		}
		printf("%5c", ch);
	}
	printf("\n");
	return 0;
}
*/

//15.
/*
#include<stdio.h>
int main(void)
{
	char ch = 'A';
	while (ch <= 'F')
	{
		switch (ch)
		{
			case 'A'	:
			case 'B':
			case 'C':
			case 'D':	ch++;	continue;
			case 'E':
			case 'F':	ch++;
		}
		printf("%5c\n", ch);
	}
	return 0;
}
*/


/*
//16. #include<stdio.h>
int main(void)
{
	int x = 0;
	for (;;)
	{
		if (x++ == 6)
			break;
		continue;
	}
	printf("\t\tx=%d\n", x);
	return 0;
}
*/



//17.
#include<stdio.h>
int main(void)
{
	int x = 0;
	for (;;)
	{
		if (x++ == 6)
		continue;
    break;
	}
	printf("\t\tx=%d\n", x);
	return 0;
	}
