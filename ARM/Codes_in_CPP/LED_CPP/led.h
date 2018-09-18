#ifndef __LED_H
#define __LED_H

#include"LPC17xx.h"

#define LED 29

#define PORT1 LPC_GPIO1

class led
{
public:
  led();
  void LED_ON(void);
  void LED_OFF(void);

};

#endif
