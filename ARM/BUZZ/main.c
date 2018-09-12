#include "LPC17xx.h"
#include "buzz.h"

#define a 150
#define d 80
#define l 400
int main()
{
	int i;
	SystemInit();
	BuzzInit();

	for ( i = 0; i < 3; i++)
	 {
		 Note1(a);// time to on
		 SW_DELAY_MS(100);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(l);
		 SW_DELAY_MS(d);
		 Note1(l);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(6*d);

	}

	while(1);
}
