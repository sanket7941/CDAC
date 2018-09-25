#include"int.h"
#include"buzz.h"
#include"LPC17xx.h"

void int_init(void)
{
  // make P2.12 as inint2
LPC_PINCON->PINSEL4 &= ~(BV(25) | BV(24));
LPC_PINCON->PINSEL4 |=  BV(24);

// config as falling Module

LPC_SC->EXTMODE |=BV(INT2);
LPC_SC->EXTPOLAR &= ~BV(INT2);
// enable int
LPC_SC->EXTINT |= BV(INT2);

NVIC_EnableIRQ(EINT2_IRQn);
}
void EINT2_IRQHandler(void)
{
    // write the ISR
    HeartBeat();
    LPC_SC->EXTINT |= BV(INT2);
}
