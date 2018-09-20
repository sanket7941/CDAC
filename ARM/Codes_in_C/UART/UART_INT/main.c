#include "LPC17xx.h"
#include"uart.h"
#include<string.h>

int main()
{
	char str[32];
	SystemInit();
	UARTinit(9600);
	UartPuts("papppu bhai !!");
	while(1)
	{
		// UartPuts("chota chetan:\r\n");
		UartPuts("prateek sheth:\r\n");
		UartGets(str);
		strupr(str);
		UartPuts(str);
	}
}
