// 4. Write a function to calculate maximum of the array elements. Write another function to
// calculate maximum of the array elements.

#include<stdio.h>
int ReadArray(int *a,int s);
int PrintArray(int *a,int s);
int MaxArray(int *a,int s);
int MinArray(int *a,int s);
int SWAP(int *a,int *b);
void main()
{
  int s,max,min;
  int mat1[10],mat2[10];

  printf("Enter the size of array\n");
  scanf("%d",&s);
  ReadArray(mat1,s);
  printf("data in matrix\n");
  PrintArray(mat1,s);

  max=MaxArray(mat1,s);
  printf("\n maximum number in array is ::%d",max);
  //PrintArray(mat1,s);


}
int ReadArray(int *a,int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    scanf("%d",(a+i));
  }
}
int PrintArray(int *a,int s)
{
int i;
for(i=0;i<s;i++)
{
  printf("\n%d",*(a+i));
}
}

int MaxArray(int *a,int s)
{
  int max, i;
	for(i=1,max=*(a+0); i<s; i++)
	{
		if ( max<*(a+i))
			max= *(a+i);
	}
	return max;
}
int MinArray(int *a,int s)
{
  int min, i;
	for(i=1,min=*(a+0); i<s; i++)
	{
		if ( min>*(a+i))
			min= *(a+i);
	}
	return min;
}
int SWAP(int *a,int *b)
{
  int temp;
  temp=*a;
  *b=*a;
  *a=temp;
}
