// 1. Write a program to accept marks of five subjects,
 // calculate its total and average.
#include<stdio.h>
void main()
{
  int marks[5];
  int i,total,avg;

  printf("Enter 5 sub marks\n");
  for(i=0;i<5;i++)
  {
    scanf("%d",&marks[i]);
  }
  for(i=0;i<5;i++)
  {
    total+=marks[i];
  }
  avg=total/5;
  printf("total marks ::%3d\n",total);
  printf("average marks:: %3d\n",avg);
}
