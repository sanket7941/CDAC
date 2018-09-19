
#include"time.h"
#include"LPC17xx.h"

volatile int flag =0;
void initTIME(uint32_t ms)
{
  uint32_t x;
  LPC_TIM0->TCR = BV(TCR_RST);
  LPC_TIM0->CTCR =CTCR_TIMER_MODE;
  LPC_TIM0->PR=PR_VAL - 1;

  x = (PCLK/1000)*ms/PR_VAL;
  LPC_TIM0->MR0 = x-1;
  LPC_TIM0->MCR |= (BV(MCR_MR0I)|BV(MCR_MR0R));

  // while(!(LPC_TIM0->IR & BV(IR_MR0)));
  NVIC_EnableIRQ(TIMER0_IRQn);
  LPC_TIM0->TCR = BV(TCR_EN);
  // LPC_TIM0->IR |=(BV(IR_MR0));
}

void TIMER0_IRQHandler(void)
{
  flag=1;
  LPC_TIM0->IR |=BV(IR_MR0);
}
