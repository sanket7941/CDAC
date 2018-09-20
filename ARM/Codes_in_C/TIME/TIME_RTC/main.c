#include "LPC17xx.h"
#include"rtc.h"
#include"lcd.h"
#include<stdio.h>
int main()
{
	char str[18];
	char* week_days[] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
	rtc_time_t x = { 	.hour = 20, .min = 20, .sec = 50,
						.dom = 20, .mon =7, .year =2018,
						.dow = 1, .doy = 1 };
	SystemInit();
	RTCinit(&x);
	LCDInit();
	enterdata(line1,"TIME");
	while(1)
	{
		while(flag == 0);
		flag=0;
		rtc_get(&x);
		sprintf(str, "%02d-%02d-%04d %s ", x.dom, x.mon, x.year, week_days[x.dow]);
		enterdata(0xc0, str);
		sprintf(str, "DeathTime%02d:%02d:%02d", x.hour, x.min, x.sec);
		enterdata(0x80, str);
	}
}
