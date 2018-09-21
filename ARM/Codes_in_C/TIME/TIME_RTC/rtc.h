#ifndef __RTC_H
#define __RTC_H

#include "LPC17xx.h"
//structure for RTC data
struct rtc
{
  int hour,min,sec;
  int dom,mon,year;
  int dow,doy;
};

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

#define AMR_ALSEC   0
#define AMR_ALMIN   1
#define AMR_ALHOUR  2
#define AMR_ALDOM   3
#define AMR_ALDOW   4
#define AMR_ALDOY   5
#define AMR_ALMON   6
#define AMR_ALYEAR  7


extern volatile int ALflag;
extern volatile int flag;

void RTCinit(struct rtc *t);
void RTCalarm(struct rtc *t);
void GETalarm(struct rtc *t);
void rtc_get(struct rtc *t);
void RTC_IRQHandler(void);

#endif
