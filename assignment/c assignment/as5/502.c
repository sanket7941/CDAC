// 2. Write a function to accept array elements from the user. Write another function to print array
// elements. Re-use these functions in rest of the assignments wherever required.
#include<stdio.h>
int ReadArray(int mat1[],int s);
int PrintArray(int *a,int s);
void main()
{
  int s;
  int mat1[10],mat2[10];

  printf("Enter the size of array\n");
  scanf("%d",&s);
  ReadArray(mat1,s);
  printf("data in matrix\n");
  PrintArray(mat1,s);
  //printf("total marks ::%3d\n",total);
  //printf("average marks:: %3d\n",avg);
}
int ReadArray(int *a,int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    scanf("%d",a+i);
  }
}
int PrintArray(int *a,int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    printf("%d \n",*(a+i));
  }
}
