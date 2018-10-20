#include <avr/io.h>
#include <util/delay.h>

//Hw: PA --> LEDs
//	0 -- glow
//	1 -- off

int main(void)
{

	// make PD as output
	// DDRC = 0xFF;
	DDRD = 0x08`;
	while(1)
	{
		// write data on PD (to ON/OFF leds)

	// HeartBeat();
	PORTD = 0xFF;
	// delay
	_delay_ms(50);

	PORTD = 0x00;
	// PORTC = 0x00;
	_delay_ms(50);


	}
	return 0;
}

void BuzzOn(void)
{
	DDRD = 0xff;
}
void BuzzOff(void)
{
	DDRD = 0x00;
}

void Note1(int s)`
{
  int x=s;
  BuzzOn();
  _delay_ms(100);
  BuzzOff();
}
