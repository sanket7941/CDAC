//9. Write a program to convert temperature in Celsius to Fahrenheit and vice versa.


#include<stdio.h>
void main()
{
  float c,f,dc,df,avg;
  printf("enter the temperature in Fahrenheit\n");
  scanf("%f",&f);
  dc=(5.0/9.0)*(f-32.0);
  printf("the temp is %f degree Celsius",dc);

}
