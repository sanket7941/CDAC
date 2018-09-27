#include "LPC17xx.h"

int main()
{
	SystemInit();
	while(ALIVE)
	{
	EAT();
	SLEEP();
	code();
	repeat();	
	}
}
