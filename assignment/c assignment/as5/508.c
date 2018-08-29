// 8. Write a function to search the given number into the array using linear search and return the
// index of the element. If element is not found it should return -1.
#include<stdio.h>
int read(int mat[],int s);
int print(int mat[],int s);
int linear(int mat[] ,int s);
int Search(int mat[],int s,int key);
void main()
{
  int mat[10];
  int i,j,s,key;
  int temp;
  printf("enter the size of array");
  scanf("%d",&s);
  printf("enter the values::");
  read(mat,s);
  printf("\n the data of matrix is");
  print(mat,s);
  //linear(mat,s);
  printf("\n enter the element to search");
  scanf("%d",&key);
  Search(mat,s,key);
  //printf("\n the data of sorted matrix is");
  //print(mat,s);
return;
}
// ****************************************************************?
int Search(int mat[] ,int s,int key)
{
  int i,j,temp,place=0;
  for(i=0;i<s;i++)
  {
      if(mat[i]==key)
      {
         temp=1;
         place=i;
         break;
      }
  }

  if(temp==1)
  {
    printf("\n%d is found  at place %d",key,place);
  }
  else
  {
    printf("\n%d is not found in Array",key);
  }
}


int read(int mat[],int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    scanf("%d",&mat[i]);
  }

}

int print(int mat[],int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    printf("%3d",mat[i]);
  }
}

int linear(int mat[] ,int s)
{
  int i,j,temp;
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
}
