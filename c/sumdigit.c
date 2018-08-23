// sum of the digit
#include <stdio.h>
int main()
{
    int n,sum,temp;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%lld", &n);
    temp=n;

    while(n != 0)
    {
        count= n%10;
        sum+=count;
        n /= 10;

    }

    printf("sum of digits%d is %d\n",temp, sum);
}
