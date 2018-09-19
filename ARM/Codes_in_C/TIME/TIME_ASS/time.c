
#include"time.h"
#include"LPC17xx.h"

volatile int flag =0;
void TIMEInit(uint32_t ms)
{
  uint32_t x;
  LPC_TIM0->TCR = BV(TCR_RST);
  LPC_TIM0->CTCR =CTCR_TIMER_MODE;
  LPC_TIM0->PR=PR_VAL - 1;

  x = (PCLK/1000)*ms/PR_VAL;
  //  loading MR register for each time slot

  LPC_TIM0->MR0 = ((3*x)-1);
  LPC_TIM0->MCR |= (BV(MCR_MR0I));

  LPC_TIM0->MR1 = ((5*x)-1);
  LPC_TIM0->MCR |=BV(MCR_MR1I);

  LPC_TIM0->MR2 = ((9*x)-1);
  LPC_TIM0->MCR |= BV(MCR_MR2I);

  LPC_TIM0->MR3 = ((11*x)-1);
  LPC_TIM0->MCR |= (BV(MCR_MR3I)|BV(MCR_MR3R));

  NVIC_EnableIRQ(TIMER0_IRQn);
  LPC_TIM0->TCR = BV(TCR_EN);

}

void TIMER0_IRQHandler(void)
{
  if((flag = (LPC_TIM0->IR & BV(IR_MR0))))
    {LPC_TIM0->IR |=BV(IR_MR0);
    flag=1;
  }
  else if(LPC_TIM0->IR & BV(IR_MR1))
    {
      LPC_TIM0->IR |=BV(IR_MR1);
      flag=2;
    }
  else if(LPC_TIM0->IR & BV(IR_MR2))
    {
      LPC_TIM0->IR |=BV(IR_MR2);
    flag=3;
  }
  else if (LPC_TIM0->IR & BV(IR_MR3))
    {
      LPC_TIM0->IR |=BV(IR_MR3);
      flag=4;
  }
}
