/*
code :: header for SPI
*/

#include "spi.h"

void SPIinit(void)
{
  // enable SCLK, MOSI, MISO using PINSEL 0&1.
	LPC_PINCON->PINSEL0 |= BV(31) | BV(30);
	LPC_PINCON->PINSEL1 |= BV(5) | BV(4) | BV(3) | BV(2);
  
	LPC_PINCON->PINSEL1 &= ~(BV(1) | BV(0));
	LPC_GPIO0->FIODIR |= BV(SSEL);

	LPC_SPI->SPCCR = CCR_VAL; //set spi rate

	LPC_SPI->SPCR = BV(SPCR_CPHA) | BV(SPCR_CPOL) | BV(SPCR_MSTR) | BV(SPCR_LSBF);

	spi_slave_ss1();//disab;e slave
}

uint8_t spi_transfer(uint8_t val)
{
	uint8_t ret_val;

	spi_slave_ss0(); // enable slave

	LPC_SPI->SPDR = val; // write data to SPDR

	while(!(LPC_SPI->SPSR & BV(SPSR_SPIF)));	// wait for SPIF


	(void)LPC_SPI->SPSR;// read SPSR regr

	ret_val = LPC_SPI->SPDR;// read data from SPDR

	spi_slave_ss1();// disable slave
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
