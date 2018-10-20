/* ExINT with buzzer
      Buzz PD3
      INT  PD2
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#define BV(bit)	(1<<(bit))

#define BUZZER_PORT		PORTD
#define BUZZER_DDR		DDRD
#define BUZZER_PIN		PIND

#define INTR0_PORT		PORTD
#define INTR0_DDR			DDRD

#define INTR2_PORT		PORTD
#define INTR2_DDR		DDRB

#define BUZZER			3
#define EINT0			2
#define EINT2			2

volatile uint8_t intr0_flag=0, intr2_flag=0;

void init(void);
void beep(uint8_t s);
void delay_s(uint8_t s);

int main(void)
{
	init();
	while(1)
	{
		if(intr0_flag)
		{
			beep(1);
			intr0_flag = 0;
		}
		if(intr2_flag)
		{
			beep(1);
			intr2_flag = 0;
		}
		_delay_ms(200);
	}
	return 0;
}

void init(void)
{
	// set buzzer pin as output
	BUZZER_DDR |= BV(BUZZER);
	// turn off the buzzer
	BUZZER_PORT &= ~BV(BUZZER);

	// set int0 pin as input
	INTR0_DDR &= ~BV(EINT0);
	// write 1 on intr pin - activate pull up
	INTR0_PORT |= BV(EINT0);
	// configure int0 for falling edge
	MCUCR |=  BV(ISC01);
	// enable int0 intrrupt
	GICR |= BV(INT0);

	// set int2 pin as input
	INTR2_DDR &= ~BV(EINT2);
	// write 1 on intr pin - activate pull up
	INTR2_PORT |= BV(EINT2);
	// configure int2 for rising edge
	MCUCSR |=  BV(ISC2);
	// enable int2 intrrupt
	GICR |= BV(INT2);

	// enable global intrrupt
	sei();
}

void beep(uint8_t s)
{
	// turn on the buzzer
	BUZZER_PORT |= BV(BUZZER);

	// delay of given sec
	delay_s(s);

	// turn off the buzzer
	BUZZER_PORT &= ~BV(BUZZER);
}

void delay_s(uint8_t s)
{
	while(s--)
		_delay_ms(1000);
}

ISR(INT0_vect)
{
	intr0_flag = 1;
}

ISR(INT2_vect)
{
	intr2_flag = 1;
}
