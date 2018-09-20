// by sanket
#include"lcd.h"
#include"LPC17xx.h"


void LCDInit(void)
{
	LCD_DATA->FIODIR|= (BV(D7) | BV(D6) | BV(D5) | BV(D4));
	LCD_CMD->FIODIR |= (BV(RS) | BV(RW) | BV(EN));

  SW_DELAY_MS(300);

  SendData(cmd,bitmode);
  SendData(cmd,dispmode);
  SendData(cmd,entrymode);
  SendData(cmd,clear);
	SW_DELAY_MS(100);
}
// check the busy flag on data pin no 7
void busy(void)
{
  LCD_DATA->FIODIR &= ~BV(D7);
  LCD_CMD->FIOCLR =  BV(RS);
  LCD_CMD->FIOSET |= (BV(RW) |BV(EN));

  while(LCD_DATA->FIOPIN & BV(D7));
  LCD_CMD->FIOCLR =BV(EN);
  LCD_DATA->FIODIR |=BV(D7);
}
// send 8 bit data to LCD
void SendData(uint8_t x ,uint8_t val)
{
  uint8_t high =(val >> 4);
  uint8_t low =(val & 0x0F);
  sendnibble(x ,high);
  sendnibble(x,low);
  busy();
  SW_DELAY_MS(3);
}

// send the 4 bit data
void sendnibble(uint8_t x, uint8_t val)
{
// RS= 0 cmd RS=1 DATA
  if(x == cmd)
    LCD_CMD->FIOCLR = BV(RS);
  else
    LCD_CMD->FIOSET |= BV(RS);

    LCD_CMD->FIOCLR = BV(RW);
    LCD_DATA->FIOCLR =(BV(D4) |BV(D5) |BV(D6) |BV(D7));
    LCD_DATA->FIOSET |=((uint32_t)val<<D4);
    LCD_CMD->FIOSET |=BV(EN);
    SW_DELAY_MS(1);
    LCD_CMD->FIOCLR =BV(EN);
  }

void enterdata(uint8_t line,char s[])
{
  int i;
  SendData(cmd,line);// send command to print in line 1
  for(i = 0;s[i]!='\0';i++)
  {
    SendData(data,s[i]);// send data
  }
}
