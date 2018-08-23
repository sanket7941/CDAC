// reverse the Number
#include <stdio.h>
int main()
{
    int n,rev,remender,temp;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%lld", &n);
    temp=n;

    while(n != 0)
    {
        remender= n%10;
        rev=rev*10+remender;
        n /= 10;
    }

    printf("the reverse of %d is %d\n",temp,rev);
}
