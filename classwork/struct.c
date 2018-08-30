// structure basics
#include<stdio.h>
struct food
{
int price;
char name[30];
float rating;
};

void main()
 {
  struct food f1={100,"vadapav",8.6};

  printf("food name:%s\n",f1.name);
  printf("price:%d\n",f1.price);
  printf("rating:%.2f\n",f1.rating);

}
