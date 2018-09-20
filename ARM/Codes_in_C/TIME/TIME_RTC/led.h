#ifndef __LED_H
#define __LED_H

#include "LPC17xx.h"

#define FIO1DIR (*(uint32_t*)0x2009C020)
#define FIO1SET (*(uint32_t*)0x2009C038)
#define FIO1CLR (*(uint32_t*)0x2009C03C)
#define LED 29

void LED_ON(void);

void LED_OFF(void);

void blink(void);

void init(void);

#endif
