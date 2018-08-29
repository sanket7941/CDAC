// 2d matrix add mul and substraction
#include<stdio.h>
int read(int mat[][3],int r ,int c);
int print(int mat[][3],int r ,int c);
int sum(int mat[][3],int mat1[][3],int mat2[][3]);
int sub(int mat[][3],int mat1[][3],int mat2[][3]);
int mul(int mat[][3],int mat1[][3],int mat2[][3]);
void main()
{
int i,j,k;
int mat[3][3],mat1[3][3],mat2[3][3];
printf("enter the value mat 1");
read(mat,3,3);
print(mat,3,3);
printf("enter the value mat 2");
read(mat1,3,3);
print(mat1,3,3);
printf("addition of matrix mat 1 and mat2 are:\n");
sum(mat,mat1,mat2);
print(mat2,3,3);
printf("substraction of matrix mat 1 and mat2 are:\n");
sub(mat,mat1,mat2);
print(mat2,3,3);
printf("multiplication of matrix mat 1 and mat2 are:\n");
mul(mat,mat1,mat2);
print(mat2,3,3);

}

// *******read array
int read(int mat[][3],int r ,int c)
{
  int i,j;
  for ( i = 0; i < r; i++)
   {
    for ( j = 0; j < c; j++)
     {
       scanf("%d",&mat[i][j]);
      }
  }
}
// *********print array
int print(int mat[][3],int r ,int c)
{
  int i,j;
  for ( i = 0; i < r; i++)
   {
    for ( j = 0; j < c; j++)
     {
       printf("%5d", *(*(mat+i)+j));
      }
      printf("\n");
  }
}
// Addition

int sum(int mat[][3],int mat1[][3],int mat2[][3])
{
  int i,j;
  for ( i = 0; i < 3; i++)
   {
    for ( j = 0; j < 3; j++)
     {
       *(*(mat2+i)+j)=*(*(mat+i)+j)+*(*(mat1+i)+j);
      }
  }
}
// substraction
int sub(int mat[][3],int mat1[][3],int mat2[][3])
{
  int i,j;
  for ( i = 0; i < 3; i++)
   {
    for ( j = 0; j < 3; j++)
     {
       *(*(mat2+i)+j)=*(*(mat+i)+j)-*(*(mat1+i)+j);
      }
    }
}
// multiplication
int mul(int mat[][3],int mat1[][3],int mat2[][3])
{
  int i,j,k;
  for ( i = 0; i < 3; i++)
   {
    for ( j = 0; j < 3; j++)
     {
       for ( k = 0; k < 3; k++)
        {
          //mat2[i][j] += mat[i][k]*mat1[k][j];
           *(*(mat2+i)+j)+=*(*(mat+i)+k) * *(*(mat1+k)+j);
        }

      }
    }

}
