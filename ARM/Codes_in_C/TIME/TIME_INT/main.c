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
	initTIME(1000);
	enterdata(line1,"sanket");
	while(1)
	{
		while(flag == 0);
		flag=0;
		sprintf(str, "Count = %d", cnt++);
		enterdata(0xc0, str);
	}
}
