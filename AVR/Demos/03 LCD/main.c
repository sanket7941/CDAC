/*
	PORT       pin no 			func
	PORT D			4					RS
	PORT D			5					RW
	PORT D			6					E

	PORT B			4					B4
	PORT B			5					B5
	PORT B			6					B6
	PORT B			7					B7
*/
#include<avr/io.h>
#include<util/delay.h>

#define BV(bit) (1<<(bit))


//  set pins for LCD
#define DATA_DIR DDRB
#define DATA_PORT PORTB
#define DATA_PIN PINB

#define CTRL_DIR DDRD
#define CTRL_PORT PORTD
#define CTRL_PIN PIND

#define D4 4
#define D5 5
#define D6 6
#define D7 7

#define RW 4
#define RS 5
#define EN 6
// rs=0: for cmd	and rs=1: for data

#define LCD_DATA	1
#define LCD_CMD		0

#define LCD_DATA_MASK (BV(D4)|BV(D5)|BV(D6)|BV(D7))
#define LCD_CTRL_MASK (BV(EN)|BV(RW)|BV(RS))

//  function dec

void LCDInit(void );
int lcd_gotoxy(uint8_t row,uint8_t col);
void lcd_putchar(char ch);
void lcd_putstring(uint8_t row,const char *str);
void lcd_write(uint8_t rs,uint8_t val);
void lcd_write_nibble(uint8_t rs ,uint8_t val);


// initialize the LCD
void LCDInit(void )
 {
  DATA_DIR |= LCD_DATA_MASK;
  DATA_PORT &= ~LCD_DATA_MASK;
  CTRL_DIR |= LCD_CTRL_MASK;
  CTRL_PORT &= ~LCD_CTRL_MASK;

  _delay_ms(100);

  lcd_write(LCD_CMD,0x28);
  lcd_write(LCD_CMD,0x0c);
  lcd_write(LCD_CMD,0x01); // clear the LCD screen
 }
// set the position of the curser
 int lcd_gotoxy(uint8_t row,uint8_t col)

 {
   if (row>1 || col >15)
   return 0;
   if(row==0)
   { lcd_write(LCD_CMD,0x80+col);}
   else
    {
    lcd_write(LCD_CMD,0xc0+col);
    }
    return 1;
  }
// take data and commant in char and string form
  void lcd_putchar(char ch)
  {
    lcd_write(LCD_DATA,ch);
  }

  void lcd_putstring(uint8_t row,const char *str)
  {
    int cnt;
    lcd_gotoxy(row,0);
    for(cnt=0;*str!='\0' && cnt<16;++cnt)
    {
      lcd_putchar(*str++);
    }
  }
// write onto the LCD controller

void lcd_write(uint8_t rs,uint8_t val)
{
  uint8_t high = val & 0xF0,low = val << 4 ;
  _delay_ms(3);
  lcd_write_nibble(rs,high);
  lcd_write_nibble(rs,low);
}

void lcd_write_nibble(uint8_t rs ,uint8_t val)
{
  // rs=0: for cmd	and rs=1: for data
  if(rs==LCD_CMD)
    CTRL_PORT &= ~BV(RS);
    else
    CTRL_PORT |= BV(RS);

    asm("nop");

    CTRL_PORT &= ~BV(RW);

    DATA_PORT &= ~LCD_DATA_MASK;
    DATA_PORT |= val &0x0F;

    CTRL_PORT |= BV(EN); // Enable =1
    asm("nop");
    CTRL_PORT &= ~BV(EN); // Enable = 0

}
// --------------------- MAIN CODE-----------------------------

int main(void)
{
	LCDInit();
	lcd_putstring(0, "gariba");
	lcd_putstring(1, "shukakuu");
	while(1);
	return 0;
}
