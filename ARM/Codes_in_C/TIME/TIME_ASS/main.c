#include "LPC17xx.h"
#include"int.h"
#include"time.h"
#include"led.h"
#include"lcd.h"
#include<stdio.h>
int main()
{
	int cnt =0;
	char str[20];

	SystemInit();
	LEDInit();
	LCDInit();
	INTInit();
	//TIMEInit(1000);
	// initTIME(1000);
	enterdata(line1,"sankat");
	enterdata(line2,"program");
	while(1)
	{
		while(flag == 0);
			switch (flag)
			 {
				case 1: enterdata(line1,"ONE");break;
				case 2: enterdata(line2,"TWO");break;
				case 3: LED_ON();break;
				case 4:	LED_OFF();break;
			  default: flag=0;
			}

	}
}
