/* timmer header for interrupt*/
#ifndef __TIME_H
#define __TIME_H

#include"LPC17xx.h"


//  define all pins of Timer SFR
#define IR_MR0 0
#define IR_MR1 1
#define IR_MR2 2
#define IR_MR3 3
#define IR_MR4 4
#define IR_MR5 5

#define TCR_EN 0
#define TCR_RST 1

#define MCR_MR0I 0
#define MCR_MR0R 1
#define MCR_MR0S 2

#define PR_VAL 18 // prescaled by 12
#define PCLK 18000000UL // crystal on HW

#define CTCR_TIMER_MODE	0x00000000

// define function

void initTIME(uint32_t ms);
void TIMER0_IRQHandler(void);

// define global flag
extern volatile int flag;

#endif
