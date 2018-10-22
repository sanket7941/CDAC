#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "adc_intr.h"

#define ADC_CHANNEL	6


volatile uint16_t adc_val=0;
volatile uint16_t adc_flag=0;

void adc_init(void)
{
	// set PORTA as input
	DDRA = ~BV(ADC_CHANNEL);
	PORTA = BV(ADC_CHANNEL);

	// enable adc and adc interrupt
	ADCSRA = BV(ADEN) | BV(ADIE);
	// enable global interrupt
	sei();
	// select adc channel, left adjust and select ref voltage
	ADMUX |= (BV(MUX0) | BV(MUX2) | BV(ADLAR) | BV(REFS1) | BV(REFS0));
}

uint16_t adc_read(void)
{
	// read value from adc
	uint16_t val = ADCH;
	return val;
}

ISR(ADC_vect)
{
	adc_val = adc_read();
	adc_flag = 1;
}
