// main.c
#include <string.h>
#include "uart.h"
#include "lcd.h"

int main()
{
	char str[50];
	SystemInit();
	LCDInit();
	uart_init(9600);
	enterdata(line1,"input data");
	while(1)
	{
		uart_puts("Hello DESD!!\r\n");
		uart_puts("God Bless You!!\r\n");
		uart_gets(str);

		enterdata(line2,str);

	}
	return 0;
}
