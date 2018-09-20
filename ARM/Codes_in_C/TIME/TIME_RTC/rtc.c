#include"rtc.h"
#include"LPC17xx.h"

volatile int flag = 0;

void RTCinit(rtc_time_t *t)
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

NVIC_EnableIRQ(RTC_IRQn);

LPC_RTC->CCR =BV (CCR_EN);
}
void rtc_get(rtc_time_t *t)
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
void RTC_IRQHandler(void)
{
  flag = 1;
  if(LPC_RTC->ILR & BV(ILR_CIF))
  LPC_RTC->ILR |= BV(ILR_CIF);
}
