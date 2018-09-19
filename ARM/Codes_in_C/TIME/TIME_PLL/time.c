
#include"time.h"
#include"LPC17xx.h"

void initTIME(void)
{
  LPC_TIM0->TCR = BV(TCR_RST);
  LPC_TIM0->CTCR =CTCR_TIMER_MODE;
  LPC_TIM0->PR=PR_VAL - 1;
}
void Time(uint32_t ms)
{
  uint32_t x;
  x = (PCLK/1000)*ms/PR_VAL;
  LPC_TIM0->MR0 = x-1;
  LPC_TIM0->MCR |= (BV(MCR_MR0I)|BV(MCR_MR0R));
  LPC_TIM0->TCR = BV(TCR_EN);

  while(!(LPC_TIM0->IR & BV(IR_MR0)));

  LPC_TIM0->IR |=(BV(IR_MR0));

}
