#include"led.h"

led::led()
{
	PORT1->FIODIR |= BV(LED);//
	LED_OFF();
}

void led::LED_ON(void)
{
	PORT1->FIOSET |= BV(LED);
}

void led::LED_OFF(void)
{
	PORT1->FIOCLR = BV(LED);
}
