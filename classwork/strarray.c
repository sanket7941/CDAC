// struct basics with function
#include<stdio.h>
#define SIZE 3
struct price
{
  int USD,INR;
};

struct food // Structure define
{
char name[30];
float rating;
struct price p;
};

void readstruct(struct food *f1);
 void displaystruct(struct food *f1);
void sort(struct food *f1,int s);
// ************main*******************88
void main()
 {
   struct food f[SIZE];
   struct price x;
   int i;
   for ( i = 0; i < SIZE; i++)
    {
      readstruct(&f[i]);
      //displaystruct(&f[i]);
    }
   for ( i = 0; i < SIZE; i++)
    {
      printf("\n**********************************\n");
      displaystruct(&f[i]);
    }
    printf("#####################################\n" );
  /*  sort(f,SIZE);

    for ( i = 0; i < SIZE; i++){
     printf("\n**********************************\n");
     displaystruct(&f[i]);
   }*/
}
// read structure
void readstruct(struct food *f1)
{
  printf("\n**********************************\n");
  printf("food name: \n");
  scanf("%s",&f1->name );
  printf("price:in INR \n");
  scanf("%d",&f1->p.INR);
  printf("price:in USD \n");
  scanf("%d",&f1->p.USD);
  printf("rating: \n");
  scanf("%f",&f1->rating );
}
// print structure
void displaystruct(struct food *f1)
{
  printf("food name:%s\n",f1->name);
  printf("price:INR%d\n",f1->p.INR);
  printf("price:USD%d\n",f1->p.USD);
  printf("rating:%.2f\n",f1->rating);
  //printf("size of struct %d",(sizeof(f1)));
}
void sort(struct food *f1,int s)
{
  struct food temp;
  int i,j;
  for ( i = 0; i < s; i++)
  {
      for ( j = i+1; j < s; j++)
       {
         if(f1[i].rating < f1[j].rating)
         {
           temp=f1[i];
           f1[i]=f1[j];
           f1[j]=temp;
         }
       }
   }
 }
