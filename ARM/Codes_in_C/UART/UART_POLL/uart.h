// uart.h
#ifndef __UART_H
#define __UART_H

#include "LPC17xx.h"

#define PCLK	(SystemCoreClock >> 2)

#define LCR_WL0		0
#define LCR_WL1		1
#define LCR_STOP	2
#define LCR_PARITY	3
#define LCR_DLAB	7

#define LSR_RDR		0
#define LSR_THRE	5

#define FCR_EN			0
#define FCR_RXFF_RST	1
#define FCR_TXFF_RST	2
#define FCR_RX_TRIG0	6
#define FCR_RX_TRIG1	7

#define IER_RBR		0
#define IER_THRE	1
#define IER_RLS		2

#define IIR_PEND	0

#define IIR_ID_RLS	3
#define IIR_ID_RDA	2
#define IIR_ID_CTI	6
#define IIR_ID_THRE	1

void uart_init(uint32_t baud);
void uart_putch(uint8_t ch);
uint8_t uart_getch(void);
void uart_puts(char str[]);
void uart_gets(char str[]);

void UART3_IRQHandler(void);

#endif

