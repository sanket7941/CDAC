/*
ALARM code using RTC
BUG=> RTC need CALIBRATION
*/

#include "LPC17xx.h"
#include"rtc.h"
#include"lcd.h"
#include"buzz.h"
#include<stdio.h>
int main()
{
	char str[18];
	char* week_days[] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
	struct rtc x = { 	.hour = 23, .min = 30, .sec = 55,
						.dom = 20, .mon =7, .year =2018,
						.dow = 1, .doy = 1 };

	struct rtc al = { 	.hour = 20, .min = 10, .sec = 00,
										.dom = 20, .mon =7, .year =2018,
										.dow = 1, .doy = 1 };
	SystemInit();
	RTCinit(&x);
	RTCalarm(&al);
	LCDInit();
	BuzzInit();
	enterdata(line1,"TIME");
	while(1)
	{
		if(ALflag == 1)
		{
		ALflag=0;
		BuzzNote1(10000);
		enterdata(line1,"ALARM beep");
		}
		if(flag == 1)
		{
			flag = 0 ;
			rtc_get(&x);
			//sprintf(str, "%02d-%02d-%04d %s ", x.dom, x.mon, x.year, week_days[x.dow]);
			//enterdata(0xc0, str);
			sprintf(str, "%02d:%02d:%02d", x.hour, x.min, x.sec);
			enterdata(line1, str);
		}
		// rtc_get(&al);
		sprintf(str, "%02d:%02d:%02d", al.hour, al.min, al.sec);
		enterdata(line2, str);
	}
}
