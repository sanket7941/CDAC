
#include"led.h"

void LEDinit(void)
{
	FIO1DIR |= BV(LED);//
	LED_OFF();
}

void LED_ON(void)
{
	FIO1SET |= BV(LED);
}

void LED_OFF(void)
{
	FIO1CLR = BV(LED);
}
