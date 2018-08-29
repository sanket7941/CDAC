// 7. Write a function to sort the array using selection or bubble sort.
#include<stdio.h>
void main()
{
  int mat[10];
  int i,j,s;
  int temp;
  printf("enter the size of matrix");
  scanf("%d",&s);
  printf("enter the values::");
  for(i=0;i<s;i++)
  {
    scanf("%d",&mat[i]);
  }
  printf("\n the data of matrix is");
  for(i=0;i<s;i++)
  {
    printf("%3d",mat[i]);
  }
  for(i=0;i<s;i++)
  {
    for(j=(i+1);j<s;j++)
    {
      if(mat[i]>mat[j])
      {

        temp=mat[i];
        mat[i]=mat[j];
        mat[j]=temp;
      }
    }
  }
  printf("\n the data of sorted matrix is");
  for(i=0;i<s;i++)
  {
    printf("%3d",mat[i]);
  }

}
