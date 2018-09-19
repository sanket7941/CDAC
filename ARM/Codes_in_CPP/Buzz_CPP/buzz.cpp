#include"buzz.h"
#include"LPC17xx.h"

buzzer::buzzer()
{
    port2->FIODIR |= BV(buzz);
    BuzzOff();
}

void buzzer::BuzzOn(void)
{
  port2->FIOSET |= BV(buzz);
}

void buzzer::BuzzOff(void)
{
  port2->FIOCLR = BV(buzz);
}
