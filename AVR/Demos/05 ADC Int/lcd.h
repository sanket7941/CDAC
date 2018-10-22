#ifndef __LCD_H
#define __LCD_H

#define LCD_DATA	1
#define LCD_CMD		0
#define WAIT		1
#define NOWAIT		0

void lcd_write(uint8_t rs, uint8_t val);
void lcd_init(void);
int lcd_gotoxy(uint8_t row, uint8_t col);
void lcd_putchar(char ch);
void lcd_putstring(uint8_t row, const char *str);

#endif

