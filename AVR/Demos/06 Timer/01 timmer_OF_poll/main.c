/*
  timmer code with polling
    usuing timmer 1
*/

#include <avr/io.h>
#include <util/delay.h>

#define BV(x) (1<<(x))

void timerDealyMS(uint16_t ms)
{
  uint16_t cnt;

  cnt =((F_CPU/1000) * ms>>10);

  TCNT1 = 65535 - cnt; //we are using  overflow

  TCCR1A=0x00;
  TCCR1B= BV(CS12)|BV(CS10); // set for OF flag

  while((TIFR & BV (TOV1)) == 0); // wait until ov flag

  TIFR = BV(TOV1);
}

int main(void)
{
	uint8_t data = 0xFF;
	// make PORTC as output
	DDRC = 0xFF;
	// on-off leds with given time delay.
	while(1)
	{
		PORTC = data;
		timerDealyMS(300);
		data = ~data;
	}
	return 0;
}
