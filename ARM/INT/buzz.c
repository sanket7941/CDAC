#include"buzz.h"
#include"LPC17xx.h"


void BuzzInit(void)
{
  port2->FIODIR |= BV(buzzer);
  BuzzOff();
}

void BuzzOn(void)
{
  port2->FIOCLR = BV(buzzer);
}
void BuzzOff(void)
{
  port2->FIOSET |= BV(buzzer);
}
void Note1(int s)
{
  int x=s;
  BuzzOn();
  SW_DELAY_MS(x);
  BuzzOff();
}
void ringtone(void)
{
  int i;
  for ( i = 0; i < 2; i++)
	 {
		 Note1(a);// time to on
		 SW_DELAY_MS(100);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(l);
		 SW_DELAY_MS(d);
		 Note1(l);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(d);
		 Note1(a);
		 SW_DELAY_MS(6*d);
	}
}
  void HeartBeat()
  {
    Note1(200);
    SW_DELAY_MS(100);
    Note1(200);
    SW_DELAY_MS(300);

    Note1(200);
    SW_DELAY_MS(100);
    Note1(200);
    SW_DELAY_MS(100);

  }
