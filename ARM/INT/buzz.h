#ifndef __BUZZ_H
#define __BUZZ_H
// delay define
#include"LPC17xx.h"

#define a 150
#define d 80
#define l 400


#define port2 LPC_GPIO2

#define buzzer 11

void BuzzInit(void);

void Note1(int s);

void BuzzOn(void);

void BuzzOff(void);

void ringtone(void);

void HeartBeat(void);

#endif
