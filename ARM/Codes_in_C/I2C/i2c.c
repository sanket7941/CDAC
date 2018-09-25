/*
code name I2C header File
Debug
*/
#include"i2c.h"
#include"LPC17xx.h"
#include"uart.h"
#include"lcd.h"

void I2Cinit(void)
{
  // enable i2c0 pins
  LPC_PINCON->PINSEL1 &= ~BV(25)|BV(24)|)BV(23)|BV(22));
  LPC_PINCON->PINSEL1 |= (BV(22) | BV(24));
// prescalar
  I2_SCLL = SCLL_VAL;
  I2_SCLH = SCLH_VAL;

  I2_CONCLR = BC(CON_ACK) | BV(CON_SIF) | BV(CON_START) | BV(CON_EN);

  I2_CONSET =BV(CON_EN);
}
void i2c_start(void)
{
  uart_putstring("sending start ! \r \n");

  I2_CONCLR = BV(CON_ACK) | BV(CON_SIF) | BV(CON_START);
  I2_CONSET = BV(CON_EN) | BV(CON_START);

  while((I2_CONSET & BV(CON_START))==0);
  UartPuts("Sentstart!\r\n");
}

void i2c_rep_start(void)
{
  i2c_start();
}

void i2c_stop(void)
{
  I2_CONCLR = BV(CON_SIF);
  I2_CONSET = BV(con_en) | BV(con_ACK) |BV(CON_STOP);
}

void i2c_send_addr(uint8_t data)
{
  uart_putstring("Sending address!\r\n");

	I2_DAT = addr;

	I2_CONCLR = BV(CON_SIF) | BV(CON_START);

	I2_CONSET = BV(CON_EN);

	while((I2_CONSET & BV(CON_SIF))==0);
	uart_putstring("address sent! \r\n");
}

void i2c_send_data(uint8_t data)
{

	I2_DAT = data;

	I2_CONCLR = BV(CON_SIF) | BV(CON_START);

	I2_CONSET = BV(CON_EN);

	while((I2_CONSET & BV(CON_SIF))==0);
}

uint8_t i2c_recv_ack(void)
{
	uint8_t data;
	// clear SI flag
	I2_CONCLR = BV(CON_SIF);
	// set i2c en
	I2_CONSET = BV(CON_EN) | BV(CON_ACK);
	// wait for receive
	while((I2_CONSET & BV(CON_SIF))==0);

	data = I2_DAT;
	return data;
}

uint8_t i2c_recv_nack(void)
{
	uint8_t data;

	I2_CONCLR = BV(CON_SIF) | BV(CON_ACK);

	I2_CONSET = BV(CON_EN);

	while((I2_CONSET & BV(CON_SIF))==0);

	data = I2_DAT;
	return data;
}
