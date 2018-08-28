#include <stdio.h>
#include<strings.h>

int main()
{
    char food[30];
    printf("enter somthing delicious\n");
    scanf("%s",food);

    if(strcmp(food,"cheese") == 0)
    {
        printf("I like cheese too :)");
    }
    else
    {
        printf("I like cheese more.");
    }

    return 0;
}
