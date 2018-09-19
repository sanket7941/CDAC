
#include"led.h"
#include"LPC17xx.h"
void LEDInit(void)
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
void blink(void)
{
	LED_ON();
	SW_DELAY_MS(1000);
	LED_OFF();
}
