//sanket
#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	SystemInit();
	LCDInit();
	int x[5]={0xBB,0xFB,0x9B,0x0B,0x4C};//サンケート
	int i;

	// enterdata(0x80,"");
	enterdata(0xc0,"Great");
	SendData(cmd,line1);
	for ( i = 0; i < 6; i++)
	 {
			SendData(data,x[i]);
	}


	// sendnibble(0x80,0x1011);
	// sendnibble(0x80,0x1011);
	busy();
  SW_DELAY_MS(3);
	while(1);
}
