// uart.c
#include "uart.h"

static char *tx_string = "";
static int tx_index;
static volatile tx_flag = 1;

void uart_init(uint32_t baud)
{
	uint16_t dl;
	// enable UART3 RX & TX pins 
	// PINSEL0[1:0]=10(tx), PINSEL0[3:2]=10(rx)
	LPC_PINCON->PINSEL0 &= ~(BV(3)|BV(2)|BV(1)|BV(0));
	LPC_PINCON->PINSEL0 |= (BV(3)|BV(1));
	// config FCR -- enable FF.
	LPC_UART3->FCR = BV(FCR_EN);
	// config LCR -- 8-bit, no parity, 1-stop bits, DLAB=1
	LPC_UART3->LCR = BV(LCR_DLAB) | BV(LCR_WL1) | BV(LCR_WL0);
	// calc div latch value - dl = (PCLK / 16) / baud.
	dl = (PCLK >> 4) / baud;
	// set divisor latch -- DLM & DLL
	LPC_UART3->DLL = dl & 0x00FF;
	LPC_UART3->DLM = dl >> 8;
	// LCR -- DLAB=0
	LPC_UART3->LCR &= ~BV(LCR_DLAB);
	// enable tx intrrupt in UART & NVIC
	LPC_UART3->IER = BV(IER_THRE);
	NVIC_EnableIRQ(UART3_IRQn);
}

uint8_t uart_getch(void)
{
	// wait while 8-bits of data is received
	while(!(LPC_UART3->LSR & BV(LSR_RDR)))
		;	
	// read & return char
	return LPC_UART3->RBR;
}

void uart_puts(char str[])
{
	// wait for last string tx
	while(tx_flag == 0)
		;
	// reset string
	tx_string = str;
	tx_index = 0;
	tx_flag = 0;
	// send first char
	LPC_UART3->THR = tx_string[tx_index++];
}

void uart_gets(char str[])
{
	int i=0;
	char ch;
	do {
		ch = uart_getch();
		str[i++] = ch;
	} while(ch != '\r');
	str[i++] = '\n';
	str[i] = '\0';
}

void UART3_IRQHandler(void)
{
	uint32_t iir, iid;

	while( !((iir = LPC_UART3->IIR) & BV(IIR_PEND)) )
	{
		iid = (iir >> 1) & 7;
		if(iid == IIR_ID_THRE)
		{	// send next char
			if(tx_string[tx_index] != '\0')
				LPC_UART3->THR = tx_string[tx_index++];
			else // string tx is done
				tx_flag = 1;
		}
		if(iid == IIR_ID_RDA)
		{	// handle rda intr
		}
	}
}

