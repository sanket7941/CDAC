/*
8. Write a program that will calculate the price for a quantity entered from the keyboard, given
that the unit price is Rs 5 and there is a discount of 10 percent for quantities over 30 and a 15
percent discount for quantities over 50.
*/
#include<stdio.h>
void main()
{
  int y,TotalCost,price,discount;
  printf("enter the quantity");
  scanf("%d",&y);

  price=y*5;
  discount=(price/100);

  if(y>50)
  {
    TotalCost=price-(discount*15);
    printf("total price %d\n",price );
    printf("%d rupees with 15 percent discount\n",TotalCost );
  }
    else if(y>30 && y<50)
    {
      TotalCost=price-(discount*15);
      printf("total price %d\n",price );
      printf("%d rupees with 10 percent discount\n",TotalCost );
    }
    else
    printf("%d rupees",price);
}
