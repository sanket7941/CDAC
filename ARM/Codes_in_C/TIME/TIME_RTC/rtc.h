#ifndef __RTC_H
#define __RTC_H

#include "LPC17xx.h"
//structure for RTC data
typedef struct rtc_time_t
{
  int hour,min,sec;
  int dom,mon,year;
  int dow,doy;
}rtc_time_t;

#define ILR_CIF 0
#define ILR_ALF 1

#define CCR_EN  0
#define CCR_RST 1

#define CIIR_IMSEC  0
#define CIIR_IMMIN  1
#define CIIR_IMHOUR 2
#define CIIR_IMDOM  3
#define CIIR_IMDOW  4
#define CIIR_IMDOY  5
#define CIIR_IMMON	6
#define CIIR_IMYEAR	7

extern volatile int flag;

void RTCinit(rtc_time_t *t);
void rtc_get(rtc_time_t *t);
void RTC_IRQHandler(void);

#endif
