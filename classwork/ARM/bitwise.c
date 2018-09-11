#include<stdio.h>

main()
{
	int a=6,b=5,c=6,ans;// 4=0100000000000  1000=8

	ans=a|b;


	printf("a=%x b=%x \n ",a,b);

	printf("NOT a %x =\n ",~a);

	printf("a OR b = %x \n",ans);


	printf("a AND b = %x \n",a&b);


	printf("a XOR b = %x \n ",a^b);

	printf("a shift left = %x \n ",c<<1);

	printf("a shift right = %x \n ",c>>1);
}
