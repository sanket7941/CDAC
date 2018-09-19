//sanket
#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	SystemInit();
	LCDInit();
	int x[5]={187,221,185,176,196};//サンケート sanket
	int y[5]={};//おしん

	int i;

	// enterdata(0x80,"");
	enterdata(0xc0,"Sanket");
	SendData(cmd,line1);
	for ( i = 0; i < 5; i++)
	 {
			SendData(data,x[i]);
	}


	// sendnibble(0x80,0x1011);
	// sendnibble(0x80,0x1011);
	busy();
  SW_DELAY_MS(3);
	while(1);
}
