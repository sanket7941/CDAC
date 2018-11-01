#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

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


#endif /* EMPLOYEE_H_ */
