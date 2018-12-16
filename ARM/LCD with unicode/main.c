//sanket
#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	SystemInit();
	LCDInit();
	enterdata(0x80,"サンケート");
	enterdata(0xc0,"voila in japnees");
	while(1);
}
