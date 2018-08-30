#include <stdio.h>
#pragma pack(1)
struct emp
{
	int empno;
	char name[10];
	float sal;

};// slack bytes
void AcceptEmpInfo(struct emp e);
void PrintEmpInfo(struct emp e);
int main(void)
{
	struct emp e1;

	printf("\n Enter Emp Info ::");
	AcceptEmpInfo(e1);

	printf("\n Emp Info from main function:: \n");
	PrintEmpInfo(e1);

	return 0;
}
void AcceptEmpInfo(struct emp e)
{
	printf("\n Enter EmpNo ::");
	scanf("%d", &e.empno);

	printf("\n Enter EmpName ::");
	scanf("%s", e.name);

	do
	{
		printf("\n Enter EmpSal ::");
		scanf("%f", &e.sal);

	}while(e.sal<0);

	printf("\n Print from AcceptEmpInfo Function \n");
	PrintEmpInfo(e);
	return;
}
void PrintEmpInfo(struct emp e)
{
	printf("\n EmpNo EmpName Sal  \n");
	printf("\n %-6d [%u] %-10s %-6.2f", e.empno,&e.empno, e.name, e.sal);
	return;
}
