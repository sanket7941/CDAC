#include <avr/io.h>
#include <util/delay.h>

#define BV(n) (1<<(n))

void pwm_init(void)
{
	// set GPIO as output (PD7 -- OC2)
	DDRD = 0xFF;
	//set OCR2
	OCR2 = 0;
	//timer2 -- fast pwm mode, inverted pwm, prescalar=1
	//TCCR2 = BV(COM21) | BV(COM20) | BV(WGM21) | BV(WGM20) | BV(CS00);
	//timer2 -- phase correct pwm mode, inverted pwm, prescalar=1
	TCCR2 = BV(COM21) | BV(COM20) | BV(WGM20) | BV(CS00);
}

int main(void)
{
	uint16_t cnt = 0;
	pwm_init();
	while(1)
	{
		for(;cnt < 255; cnt++)
		{
			OCR2 = cnt;
			_delay_ms(20);
		}
		for(;cnt > 0; cnt--)
		{
			OCR2 = cnt;
			_delay_ms(20);
		}
	}
	return 0;
}
