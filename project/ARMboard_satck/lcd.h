#ifndef __LCD_H
#define __LCD_H

#include "LPC17xx.h"

#define LCD_DATA_GPIO LPC_GPIO2
#define LCD_CTRL_GPIO LPC_GPIO1

#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define LCD_EN 22
#define LCD_RW 23
#define LCD_RS 24

#define LCD_CLEAR	0x01
#define LCD_4BIT_2LN_5x10	0x2C
#define LCD_DISPON	0x0C
#define LCD_ADDRINCR	0x06
#define LCD_LEFTSHIFT	0x18

#define LCD_LINE1	0x80
#define LCD_LINE2	0xC0

#define LCD_CMD		0
#define LCD_DATA	1

void lcd_send_nibble(uint8_t rs, uint8_t val);
void lcd_busy_wait(void);
void lcd_send_byte(uint8_t rs, uint8_t val);

void lcd_puts(uint8_t line, unsigned char s[]);
void lcd_init(void);

#endif







