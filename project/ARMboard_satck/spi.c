#include "spi.h"

void spi_init(void)
{
	// enable SCLK, MOSI, MISO using PINSEL.
	LPC_PINCON->PINSEL0 |= BV(31) | BV(30);
	LPC_PINCON->PINSEL1 |= BV(5) | BV(4) | BV(3) | BV(2);
	// Keep SSEL as GPIO & make it as output pin
	LPC_PINCON->PINSEL1 &= ~(BV(1) | BV(0));
	LPC_GPIO0->FIODIR |= BV(SSEL);	
	// set SPI bit rate -- SPCCR
	LPC_SPI->SPCCR = CCR_VAL;
	// set SPI config -- SPCR
	LPC_SPI->SPCR = BV(SPCR_CPHA) | BV(SPCR_CPOL) | BV(SPCR_MSTR) | BV(SPCR_LSBF);
	// disable slave
	spi_slave_ss1();
}

uint8_t spi_transfer(uint8_t val)
{
	uint8_t ret_val;
	// enable slave
	spi_slave_ss0();
	// write data to SPDR
	LPC_SPI->SPDR = val;
	// wait for SPIF
	while(!(LPC_SPI->SPSR & BV(SPSR_SPIF)))
		;
	// read SPSR regr
	(void)LPC_SPI->SPSR;
	// read data from SPDR
	ret_val = LPC_SPI->SPDR;
	// disable slave
	spi_slave_ss1();
	return ret_val;
}

void spi_slave_ss0(void)
{
	LPC_GPIO0->FIOCLR = BV(SSEL);
}
void spi_slave_ss1(void)
{
	LPC_GPIO0->FIOSET |= BV(SSEL);
}


