#include <avr/io.h>
#include <util/delay.h>

//Hw: PA --> LEDs
//	0 -- glow
//	1 -- off

int main(void)
{
	uint8_t data = 0xAA;
	// make PA as output
	DDRC = 0xFF;
	while(1)
	{
		// write data on PA (to ON/OFF leds)
		PORTC = data;
		// delay
		_delay_ms(1000);
		// change led pattern
		data = ~data;
	}
	return 0;	
}


