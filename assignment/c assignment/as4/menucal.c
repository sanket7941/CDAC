#include<stdio.h>
int add(int *a,int *b);
int sub(int *a,int *b);
int mul(int *a,int *b);
int div(int *a,int *b);

int main()
{
  int n1,n2,ans;
  int x;
  printf("enter the two numbers");
  scanf("%d%d",&n1,&n2);

  printf("1 add\n");
  printf("2 sub\n");
  printf("3 mul\n");
  printf("4 div\n");
  printf("enter the number\n");
  scanf("%d",&x);
  switch (x)
  {
    case 1: ans=add(&n1,&n2);
              printf("%d",ans);
              break;

    case 2: ans=sub(&n1,&n2);
              printf("%d",ans);
              break;

    case 3: ans=mul(&n1,&n2);
              printf("%d",ans);
             break;

    case 4:ans=div(&n1,&n2);
              printf("%d",ans);
             break;
  }
}

int add(int *a,int *b)
{
  int sum= *a+*b;
  printf("additon of %d and %d=%d",*a,*b);
   return sum ;
}

int sub(int *a,int *b)
{
  int sub= *a-*b;
  printf("sub of %d and %d=%d",*a,*b);
   return sub;
}
int mul(int *a,int *b)
{
  int mul= *a * *b;
     printf("mul of %d and %d=%d",*a,*b);
   return mul;
}
int div(int *a,int *b)
{
  if(b>0)
  {
  int divs= *a / *b;
  printf("div of %d and %d=%d",*a,*b);
   return divs;
  }
  else
  printf("enter the positive number");
}
