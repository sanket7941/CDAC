#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define BV(bit) (1<<(bit))

#define LCD_DATA_DIR	DDRB
#define LCD_DATA_PORT	PORTB
#define LCD_DATA_PIN	PINB

#define LCD_CTRL_DIR	DDRD
#define LCD_CTRL_PORT	PORTD
#define LCD_CTRL_PIN	PIND

#define LCD_D4	4
#define LCD_D5	5
#define LCD_D6	6
#define LCD_D7	7

// #define LCD_BL	0
#define LCD_EN	6
#define LCD_RW	5
#define LCD_RS	4

#define LCD_DATA_MASK (BV(LCD_D4)|BV(LCD_D5)|BV(LCD_D6)|BV(LCD_D7))
#define LCD_CTRL_MASK (BV(LCD_EN)|BV(LCD_RW)|BV(LCD_RS))

void lcd_write_nibble(uint8_t rs, uint8_t val)
{
	// rs=0: for cmd	and rs=1: for data
	if(rs==LCD_CMD)
		LCD_CTRL_PORT &= ~BV(LCD_RS);
	else
		LCD_CTRL_PORT |= BV(LCD_RS);

	asm("nop");
	_delay_ms(1);

	LCD_CTRL_PORT &= ~BV(LCD_RW);	//rw=0:	write operation

	LCD_DATA_PORT &= ~LCD_DATA_MASK;
	LCD_DATA_PORT |= val & 0xF0;	// write nibble

	LCD_CTRL_PORT |= BV(LCD_EN);	//en=1
	asm("nop");
	// _delay_ms(1);
	LCD_CTRL_PORT &= ~BV(LCD_EN);	//en=0
}

void lcd_write(uint8_t rs, uint8_t val)
{
	uint8_t high = val & 0xF0, low = val << 4;
	_delay_ms(3);
	lcd_write_nibble(rs, high);
	lcd_write_nibble(rs, low);
	// busy flag
}

void lcd_init()
{
	// set data and ctrl port as output
	LCD_DATA_DIR |= LCD_DATA_MASK;
	LCD_DATA_PORT &= ~LCD_DATA_MASK;
	LCD_CTRL_DIR |= LCD_CTRL_MASK;
	LCD_CTRL_PORT &= ~LCD_CTRL_MASK;
	// settling time 100ms
	_delay_ms(100);

	// send commands to lcd

	// DL(0)=>4bit	N(1)=>2 lcd lines	F(0)=>font 5x8
	lcd_write(LCD_CMD, 0x28);

	// D(1)=>display on	C(0)=>no cursor	B(0)=>no blink
	lcd_write(LCD_CMD, 0x0C);

	// lcd clear
	lcd_write(LCD_CMD, 0x01);

	// I/D(1)=>increment cursor	S(0)=>no shift
	//lcd_write(LCD_CMD, 0x06);
}

int lcd_gotoxy(uint8_t row, uint8_t col)
{
	if(row>1 || col>15)
		return 0; // false => failed
	if(row==0)	//row 0: ADDR = 0x00
		lcd_write(LCD_CMD, 0x80+col);
	else		//row 1: ADDR = 0x40
		lcd_write(LCD_CMD, 0xC0+col);
	return 1; // true => success
}

void lcd_putchar(char ch)
{
	lcd_write(LCD_DATA, ch);
}

void lcd_putstring(uint8_t row, const char *str)
{
	int cnt;
	lcd_gotoxy(row, 0);
	for(cnt=0; *str!='\0' && cnt<16; ++cnt)
		lcd_putchar(*str++);
}
