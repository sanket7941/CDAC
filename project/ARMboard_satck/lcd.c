#include "lcd.h"

void lcd_send_nibble(uint8_t rs, uint8_t val)
{
	// rs=0 (command) or rs=1 (data)
	if(rs == LCD_CMD)
		LCD_CTRL_GPIO->FIOCLR = BV(LCD_RS);
	else
		LCD_CTRL_GPIO->FIOSET |= BV(LCD_RS);
	// rw=0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_RW);
	// write nibble on D4 to D7 pins
	LCD_DATA_GPIO->FIOCLR = (BV(LCD_D7)|BV(LCD_D6)|BV(LCD_D5)|BV(LCD_D4));
	LCD_DATA_GPIO->FIOSET |= ((uint32_t)val << LCD_D4);
	// falling edge on en.
	LCD_CTRL_GPIO->FIOSET |= BV(LCD_EN);
	SW_DELAY_MS(1); //asm("nop");
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_EN);
}

void lcd_busy_wait(void)
{
	// make D7 pin as input
	LCD_DATA_GPIO->FIODIR &= ~BV(LCD_D7);
	// rs=0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_RS);
	// rw=1, en = 1
	LCD_CTRL_GPIO->FIOSET |= (BV(LCD_RW) | BV(LCD_EN));
	// read D7 pin & wait until it become 0.
	while(LCD_DATA_GPIO->FIOPIN & BV(LCD_D7))
		;
	// en=0
	LCD_CTRL_GPIO->FIOCLR = BV(LCD_EN);
	// make D7 pin as output
	LCD_DATA_GPIO->FIODIR |= BV(LCD_D7);
}
void lcd_send_byte(uint8_t rs, uint8_t val)
{
	uint8_t high = (val >> 4);
	uint8_t low = (val & 0x0F);
	lcd_send_nibble(rs, high);
	lcd_send_nibble(rs, low);
	lcd_busy_wait();
	SW_DELAY_MS(3);
}

void lcd_puts(uint8_t line,unsigned char s[])
{
	int i;
	// set line addr: 0x80 or 0xC0
	lcd_send_byte(LCD_CMD, line);

	// send all chars one by one.
	for(i=0; s[i]!='\0'; i++)
		lcd_send_byte(LCD_DATA, s[i]);
}

void lcd_init(void)
{
	// make data & ctrl ports as output
	LCD_DATA_GPIO->FIODIR |= (BV(LCD_D7)|BV(LCD_D6)|BV(LCD_D5)|BV(LCD_D4));
	LCD_CTRL_GPIO->FIODIR |= (BV(LCD_RS)|BV(LCD_RW)|BV(LCD_EN));

	// reset delay for lcd.
	SW_DELAY_MS(300);

	// set lcd mode/function.
	lcd_send_byte(LCD_CMD, LCD_4BIT_2LN_5x10);
	lcd_send_byte(LCD_CMD, LCD_DISPON);
	lcd_send_byte(LCD_CMD, LCD_ADDRINCR);
	lcd_send_byte(LCD_CMD, LCD_CLEAR);

	SW_DELAY_MS(100);
}
