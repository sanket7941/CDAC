// 3. Write a function to reverse the array elements.
#include<stdio.h>
int ReadArray(int mat1[],int s);
int PrintArray(int *a,int s);
int RevArray(int *a,int s);
void main()
{
  int s;
  int mat1[10],mat2[10];

  printf("Enter the size of array\n");
  scanf("%d",&s);
  ReadArray(mat1,s);
  printf("data in matrix\n");
  PrintArray(mat1,s);
  printf("reverse  matrix\n");
  RevArray(mat1,s);
  PrintArray(mat1,s);


}
int ReadArray(int *a,int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    scanf("%d",a+i);
  }
  return;
}
int PrintArray(int *a,int s)
{
  int i;
  for(i=0;i<s;i++)
  {
    printf("%d \n",*(a+i));
  }
return;
}

int RevArray(int *a,int s)
{
  int i,temp=0;
  int c = s - 1;
  for(i=0;i<c;i++)
  {

    temp=a[i];
    a[i]=a[c];
    a[c]=temp;
    c--;

  }
  return;
}
