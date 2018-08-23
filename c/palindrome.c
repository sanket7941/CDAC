// palindrome number
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

    (rev==temp) ? printf("the number %d is palindrome\n",temp) : printf("the number %d is not palindrome\n",temp);
}
