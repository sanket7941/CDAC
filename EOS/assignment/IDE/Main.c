#include <stdio.h>
#include <stdlib.h>
#include"Employee.h"
//#include"Employee.h"
int main(void)
{
	int choice;
	do
	{
		choice=MenuOperations();
		switch(choice)
		{
			default : printf("\n Invalid choice:: ");
					 continue;
			case 1:// add new record
					WriteEmpDataToTextFile();
					break;
			case 2:// print all emp
					ReadEmpDataFromTextFile();
					break;
			case 0: exit(0);
		}

		printf("\n Enter 1 to continue or o to exit");
		scanf("%d", &choice);

	}while(choice!=0);



	return 0;
}
