// Write a function to calculate sum and product into a single function.
// a. Using global variables (for result)
#include <stdio.h>
void SumProd(int n1, int n2, int *ps, int *pp);
int main(void)
{
  int no1, no2,sum,prod;
  printf("enter the 2 numbers");
  scanf("%d %d",&no1,&no2);

	SumProd(no1, no2, &sum , &prod);
	printf("\n %d + %d = %d", no1, no2, sum);
	printf("\n %d * %d = %d", no1, no2, prod);

	return 0;
}
void SumProd(int n1, int n2, int *ps, int *pp)
{
	*ps = n1 + n2;
	*pp =  n1 * n2;
	return;
}
