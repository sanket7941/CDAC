#include "LPC17xx.h"
#include "buzz.h"
#include "int.h"

int main()
{
	SystemInit();
	BuzzInit();
	int_init();

	while(1);
}
