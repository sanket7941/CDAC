// 7. Write a function to print given number of terms of Fibonacci series.


#include <stdio.h>
int fab(int x);
int main()
{
    int x,ans;

    printf("Enter the number of terms: ");
    scanf("%d", &x);
    printf("\nFibonacci Series: ");
    fab(x);
    //printf("%d",ans);
}
int fab(int x)
{
  int i,x1 = 0, x2 = 1, nextTerm;
  for (i = 1; i <= x; ++i)
  {
      printf("%3d", x1);
      nextTerm = x1 + x2;
      x1 = x2;
      x2 = nextTerm;
  }
  return x1;
}
