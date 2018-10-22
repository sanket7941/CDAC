#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc_intr.h"

int main(void)
{
	char str[20], cnt_str[20];
	int16_t cnt = 0;
	lcd_init();
	adc_init();

	// lcd_putstring(0,"yee ganeeesh");

	_delay_ms(5000);
	while(1)
	{
		// start conversion
		ADCSRA |= BV(ADSC);

		if(adc_flag)
		{
			sprintf(str, "adc val: %04d", adc_val, cnt++);
			lcd_putstring(1, str);
			adc_flag = 0;
		}
		else
		{
			sprintf(cnt_str, "adc intr (%02d)", cnt++);
			lcd_putstring(0, cnt_str);
		}
		_delay_ms(200);
	}
	return 0;
}
