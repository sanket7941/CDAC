#include"buzz.h"
#include"LPC17xx.h"


void BuzzInit(void)
{
  port2->FIODIR |= BV(buzzer);
  BuzzOff();
}

void BuzzOn(void)
{
  port2->FIOCLR = BV(buzzer);
}
void BuzzOff(void)
{
  port2->FIOSET |= BV(buzzer);
}
void Note1(int s)
{
  int x=s;
  BuzzOn();
  SW_DELAY_MS(x);
  BuzzOff();
}
