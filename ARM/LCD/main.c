//sanket
#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	SystemInit();
	LCDInit();
	enterdata(0x80,"sankAt");
	enterdata(0xc0,"black magic");
	while(1);
}
