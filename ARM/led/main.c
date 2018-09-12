#include "LPC17xx.h"
#include"led.h"


int main()
{
	int i;
	SystemInit();
	init();


	for(i=0;i<10;i++)
	{
		LED_ON();
		SW_DELAY_MS(1000);
		LED_OFF();
		SW_DELAY_MS(1000);

	}

	LED_OFF();
	while(1);
}
