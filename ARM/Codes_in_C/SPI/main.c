#include "LPC17xx.h"
#include"spi.h"

int main()
{
	// code 1 sending data with spi to toggle led
	#if 1

	uint8_t data = 0x55;
	SystemInit();
	SPIinit();
	while(1)
	{
			spi_transfer(data);
			data = ~data;
			SW_DELAY_MS(500);
	}

	#endif

	//code 2 running led with SPI
	#if 0
	int i,j;
	// uint8_t data = 0x55;
	SystemInit();
	SPIinit();
	while(1)
	{
		for (j = 20; j > 1; j--)
		{
		for (i = 0; i < 8; i++)
		{
			spi_transfer(1<<i);
			// data = ~data;
			SW_DELAY_MS(10*j);
		}
	}
	}
	#endif
}
