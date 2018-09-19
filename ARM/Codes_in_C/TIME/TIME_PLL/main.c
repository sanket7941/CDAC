#include "LPC17xx.h"
#include"time.h"
#include"led.h"
#include"lcd.h"
#include<stdio.h>
int main()
{
	int cnt =0;
	char str[20];
	SystemInit();
	init();
	LCDInit();
	initTIME();
	enterdata(0x80,"sanket");
	while(1)
	{
		sprintf(str, "Count = %d    ", cnt++);
		enterdata(0x80, str);
		Time(1000);
	}
}
