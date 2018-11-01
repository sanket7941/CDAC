#include<stdio.h>
#include"Employee.h"
int MenuOperations()
{
	int choice;
	printf("\n 1. Add New Employee  \n 2. Print All Employees \n 0. Exit ");
	printf("\n Enter Your Choice :: ");
	scanf("%d", &choice);
	return choice;
}
void ReadEmpDataFromTextFile()
{
	FILE *fpEmpRead=NULL;
	int cnt=0;
	struct emp e1;
	if ( (fpEmpRead= fopen("EMPINFO","rb"))==NULL)
		printf("\n unable to read from file");
	else
	{

		//fprintf(stdout,"\n EmpNo EmpName Sal  \n");
		// read 1st record from text file
		/*fscanf(fpEmpRead,"\n%d\t%s\t%f", &e1.empno, e1.name, &e1.sal);*/

		// read data from binary file
		/*cnt=fread(&e1, sizeof(struct emp), 1, fpEmpRead);
		PrintEmpInfo(&e1);*/

		// read all records
		/*cnt=0;
		fprintf(stdout,"\n EmpNo   EmpName     Sal  \n");
		while(fscanf(fpEmpRead,"\n%d\t%s\t%f", &e1.empno, e1.name, &e1.sal)!=EOF)
		{
			cnt++;
			PrintEmpInfo(&e1);
		}*/
		// read all records
		cnt=0;
		fprintf(stdout,"\n EmpNo   EmpName     Sal  \n");
		while(fread(&e1, sizeof(struct emp), 1, fpEmpRead))
		{
			cnt++;
			PrintEmpInfo(&e1);
		}


		fcloseall();

		printf("\n %d records read from file", cnt);
	}

}
void WriteEmpDataToTextFile()
{
	FILE *fpEmpWrite=NULL;
	struct emp e1;

	if ( (fpEmpWrite= fopen("EMPINFO","ab"))==NULL)
		printf("\n unable to write into file");
	else
	{
		printf("\n Enter Emp Info ::");
		AcceptEmpInfo(&e1);
		// to write data in text file
		//fprintf(fpEmpWrite,"\n%d\t%s\t%f", e1.empno, e1.name, e1.sal);
		// to write data in binary files
		fwrite(&e1, sizeof(struct emp),1,fpEmpWrite);


		fcloseall();
		printf("\n record added to file");
	}
		return;
}
void AcceptEmpInfo(struct emp *e)
{
	fprintf(stdout,"\n Enter EmpNo ::");
	fscanf(stdin,"%d", &e->empno);

	fprintf(stdout,"\n Enter EmpName ::");
	fscanf(stdin,"%s", e->name);
	do
	{
		fprintf(stdout,"\n Enter EmpSal ::");
		fscanf(stdin,"%f", &e->sal);

	}while(e->sal<0);
	return;
}


void PrintEmpInfo(const struct emp *e)
{
	fprintf(stdout,"\n %-6d %-10s %-6.2f", e->empno, e->name, e->sal);
	return;
}
