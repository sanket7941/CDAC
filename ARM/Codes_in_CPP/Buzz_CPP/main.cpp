#include "LPC17xx.h"
#include "buzz.h"

int main()
{
	buzzer b1;
	SystemInit();
	while(1)
	{
		b1.BuzzOn();
		SW_DELAY_MS(200);
		b1.BuzzOff();
		SW_DELAY_MS(200);
	}
}
