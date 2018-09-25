#include"uart.h"
#include"LPC17xx.h"
void UARTinit(uint32_t baud)
{
  uint16_t dl;
  LPC_PINCON->PINSEL0 &= ~(BV(3)|BV(2)|BV(1)|BV(0));
  LPC_PINCON->PINSEL0 |= (BV(3) | BV(1));

  LPC_UART3->LCR= BV(LCR_DLAB) |BV(LCR_WL1)|BV(LCR_WL0);

  dl =(PCLK >> 4)/baud;//0111 0101
/*
    0000 0000 0111 0101
  & 0000 0000 1111 1111
    0000 0000 0111 0101 DLL

    0000 0000 0111 0101
>>8 0000 0000 0000 0000
*/
  LPC_UART3->DLL = dl & 0x00ff; // 75
  LPC_UART3->DLM = dl >> 8; //     00


  LPC_UART3->LCR &= ~BV(LCR_DLAB);

  LPC_UART3->FCR =BV(FCR_EN);

}

void UartPutch(uint8_t ch)
{
  while(!(LPC_UART3->LSR & BV(LSR_THRE)));

  LPC_UART3->THR=ch;
}

uint8_t UartGetch(void)
{
  while(!(LPC_UART3->LSR & BV(LSR_RDR)));
  return LPC_UART3->RBR;
}
void UartPuts(char str[])
{
  int i;
  for (i = 0;str[i]!='\0'; i++)
   {
    UartPutch(str[i]);
  }
}
void UartGets(char str[])
{
  int i=0;
  char ch;
  do {
    ch = UartGetch();
    str[i++] =ch;
     } while(ch!='\r');
  str[i++] = '\n';
  str[i] = '\0';
}
