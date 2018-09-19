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
#define MCR_MR1I 3
#define MCR_MR1R 4
#define MCR_MR1S 5
#define MCR_MR2I 6
#define MCR_MR2R 7
#define MCR_MR2S 8
#define MCR_MR3I 9
#define MCR_MR3R 10
#define MCR_MR3S 11


#define PR_VAL 12 // prescaled by 12
#define PCLK 12000000UL // crystal on HW

#define CTCR_TIMER_MODE	0x00000000

// define function

void TIMEInit(uint32_t ms);
void TIMER0_IRQHandler(void);

// define global flag
extern volatile int flag;

#endif
