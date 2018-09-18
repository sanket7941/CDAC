// by sanket
#ifndef __LCD_H
#define __LCD_H

#include"LPC17xx.h"

// port configration
#define LCD_DATA LPC_GPIO2
#define LCD_CMD  LPC_GPIO1

// pin configuration
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define EN 22
#define RW 23
#define RS 24

// LCD commands
#define clear 0x01
#define bitmode 0x2C
#define dispmode 0x0C
#define entrymode 0x06
#define line1 0x80
#define line2 0xC0

// selct line for data and command
#define cmd 0
#define data 1

// declear all function
void LCDInit(void);
void busy(void);
void SendData(uint8_t x ,uint8_t val);
void sendnibble(uint8_t x, uint8_t val);
void enterdata(uint8_t line,char s[]);

#endif
