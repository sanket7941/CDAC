#ifndef __BUZZ_H
#define __BUZZ_H

#include"LPC17xx.h"

#define port2 LPC_GPIO2

#define buzzer 11

void BuzzInit(void);

void BuzzOn(void);

void BuzzOff(void);

#endif
