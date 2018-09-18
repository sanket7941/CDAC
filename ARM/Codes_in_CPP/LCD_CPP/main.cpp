#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	lcd l1;
	l1.enterdata(line1, "zing zing");
	l1.enterdata(line2, "Zingaat!!");
	while(1);

}
