// Write a program to calculate Area and Perimeter of Triangle for given length of three sides of
// triangle. Use sqrt() function from math.h to calculate square root.
#include<stdio.h>
#include<math.h>
void main()
{
    float a,b,c,x,s,area,Perimeter;
    printf("enter the values of a,b,c");
    scanf("%f %f %f",&a,&b,&c);
    s=(a+b+c)/2;
    x=(s*(s-a)*(s-b)*(s-c));
    area=sqrt(x);
    printf("the area of a trangle is : %f ",area);
    Perimeter=a+b+c;
    printf("\nthe Perimeterof triangle is : %f",Perimeter);
}
