#ifndef __BUZZ_H
#define __BUZZ_H

#include"LPC17xx.h"

// define buzz  port pin
#define buzz 11

#define port2 LPC_GPIO2
class buzzer
{
public:
  buzzer();
  void BuzzOn(void);
  void BuzzOff(void);

};

#endif
