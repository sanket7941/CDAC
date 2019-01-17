#ifndef __UART_H
#define __UART_H
#include"LPC17xx.h"
//  define all pins
#define LCR_WL0   0
#define LCR_WL1   1
#define LCR_STOP  2
#define LCR_PAR   3
#define LCR_DLAB  7

#define LSR_RDR   0
#define LSR_THRE  5

#define FCR_EN    0
#define FCR_RX    1
#define FCR_TX    2
#define FCR_TRIG0 6
#define FCR_TRIG1 7

#define PCLK 18000000UL


// define the function
void UARTinit(uint32_t baud);
void UartPutch(uint8_t ch);
uint8_t UartGetch(void);
void UartPuts(char str[]);
void UartGets(char str[]);

#endif
