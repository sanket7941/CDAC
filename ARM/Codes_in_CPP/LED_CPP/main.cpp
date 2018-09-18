#include "LPC17xx.h"
#include "led.h"

int main()
{
	SystemInit();
	
	led l1;

	while(1)
	{
		l1.LED_ON();
		SW_DELAY_MS(2000);
		l1.LED_OFF();
		SW_DELAY_MS(2000);
	}
}
