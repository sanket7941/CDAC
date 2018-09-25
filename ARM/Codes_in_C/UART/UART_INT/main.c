#include "LPC17xx.h"
#include"uart.h"
#include"lcd.h"
#include<string.h>

int main()
{
	char str[32];
	SystemInit();
	LCDInit();
	UARTinit(9600);
	UartPuts(" surya full ");
	enterdata(0xc0,"code by ganuu");
	while(1)
	{
		// UartPuts("chota chetan:\r\n");
		// UartPuts("prateek sheth:\r\n");
		UartPuts(" surya full ");
		// UartGets(str);

		// strupr(str);
		enterdata(line1,"abc");
	//	UartPuts(str);
	}
}
