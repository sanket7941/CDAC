#include"rtc.h"
#include"LPC17xx.h"

volatile int flag = 0;
volatile int ALflag = 0;

void RTCinit(struct rtc *t)
{
LPC_RTC->CCR =BV(CCR_RST);
LPC_RTC->SEC =t->sec;
LPC_RTC->HOUR =t->hour;
LPC_RTC->DOM =t->dom;
LPC_RTC->DOW =t->dow;
LPC_RTC->DOY =t->doy;
LPC_RTC->MONTH=t->mon;
LPC_RTC->YEAR =t->year;

LPC_RTC->CIIR |= BV(CIIR_IMSEC);
LPC_RTC->AMR =0xFC;

NVIC_EnableIRQ(RTC_IRQn);

LPC_RTC->CCR =BV (CCR_EN);
}

void rtc_get(struct rtc *t)
{
  t->sec = LPC_RTC->SEC;
	t->min = LPC_RTC->MIN;
	t->hour = LPC_RTC->HOUR;
	t->dom = LPC_RTC->DOM;
	t->dow = LPC_RTC->DOW;
	t->doy = LPC_RTC->DOY;
	t->mon = LPC_RTC->MONTH;
	t->year = LPC_RTC->YEAR;
}

// RTCalarm
void RTCalarm(struct rtc *al)
{

  LPC_RTC->ALSEC    =al->sec;
  LPC_RTC->ALHOUR   =al->hour;
  LPC_RTC->ALDOM    =al->dom;
  LPC_RTC->ALDOW    =al->dow;
  LPC_RTC->ALDOY    =al->doy;
  LPC_RTC->ALMON    =al->mon;
  LPC_RTC->ALYEAR   =al->year;

}

void RTC_IRQHandler(void)
{
  // alflag
  if((LPC_RTC->ILR & BV(ILR_ALF)))
  {
  LPC_RTC->ILR |= BV(ILR_ALF);
  ALflag = 1;
  }

  if(LPC_RTC->ILR & BV(ILR_CIF))
  
  {
  LPC_RTC->ILR |= BV(ILR_CIF);
  flag = 1;
  }
}
