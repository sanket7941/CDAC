// structureadstruct basics with function
#include<stdio.h>
struct food
{
int price;
char name[30];
float rating;
};
void readstruct(struct food *f1);
void displaystruct(struct food *f1);

// *******************************88
void main()
 {
   struct food f;
   readstruct(&f);
   displaystruct(&f);
}

void readstruct(struct food *f1)
{
  printf("food name: \n");
  scanf("%s",&f1->name );
  printf("price: \n");
  scanf("%d",&f1->price );
  printf("rating: \n");
  scanf("%f",&f1->rating );
}
void displaystruct(struct food *f1)
{
  printf("food name:%s\n",f1->name);
  printf("price:%d\n",f1->price);
  printf("rating:%.2f\n",f1->rating);
  printf("size of struct %d",(sizeof(f1)));
}
