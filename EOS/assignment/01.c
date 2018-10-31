#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#pragma pack(1)
struct emp
{
	int empno;
	char name[10];
	float sal;
};
void AcceptEmpInfo(struct emp *e);
void PrintEmpInfo(const struct emp *e);
void WriteEmpDataToTextFile();
void ReadEmpDataFromTextFile();
int MenuOperations();
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
	src = open(argv[1],O_RDONLY);//read file
  // to print the file on terminal
  while ((cnt= read(src,buff,sizeof(buff)))>0)
   {    write(1,buff,cnt);    }

	// FILE *fpEmpRead=NULL;
	int cnt;
	struct emp e1;
	if(argc != 1)
	{
		write(1, "no sourse file ", 20);
		// fprintf(stderr, "syntax: %s <src file>\n", argv[0]);
		_exit(1);
	}
	else
	{
		// read 1st record
		//fprintf(stdout,"\n EmpNo EmpName Sal  \n");
		/*fscanf(fpEmpRead,"\n%d\t%s\t%f", &e1.empno, e1.name, &e1.sal);
		PrintEmpInfo(&e1);*/

		// read all records
		cnt=0;
		write(1,"\n EmpNo   EmpName     Sal  \n", 30);
		while ((cnt= read(src,buff,sizeof(buff)))>0)
	   {
	    write(1,buff,cnt);
	    }
		/* fprintf(stdout,"\n EmpNo   EmpName     Sal  \n");
		while(fscanf(fpEmpRead,"\n%d\t%s\t%f", &e1.empno, e1.name, &e1.sal)!=EOF)
		{
			cnt++;
			PrintEmpInfo(&e1);
		}*/
		close(src);

		printf("\n %d records read from file", cnt);
	}

}
void WriteEmpDataToTextFile()
{
	FILE *fpEmpWrite=NULL;
	struct emp e1;

	if ( (fpEmpWrite= fopen("EMPINFO.txt","a"))==NULL)
		printf("\n unable to wiite into file");
	else
	{
		printf("\n Enter Emp Info ::");
		AcceptEmpInfo(&e1);
		fprintf(fpEmpWrite,"\n%d\t%s\t%f", e1.empno, e1.name, e1.sal);
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
