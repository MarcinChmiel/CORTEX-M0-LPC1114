//Example shows how to set USART
//This example wait for char to receive and send it back via USART to PC

#include "LPC11xx.h"
#define BAUD			9600
#define BAUD_DIVISOR		(48000000/(BAUD*16))
int main(void)
{

 char c = '\0';
 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);				//Enable clock for IOCON block
 LPC_IOCON->PIO1_6 = 1;						//Enable RXD function
 LPC_IOCON->PIO1_7 = 1;						//Enable TXD function
 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);				//Enable clock for UART
 LPC_SYSCON->UARTCLKDIV = 1;					//PCLK div 1
 LPC_UART->FCR = (1<<0);					//Enable for both UART RX and TX FIFOs
 LPC_UART->LCR = (1<<7); 					//Enable access to Divisor Latches
 LPC_UART->DLL = BAUD_DIVISOR;
 LPC_UART->DLM = (BAUD_DIVISOR >> 8);
 LPC_UART->LCR &= ~(1<<7);					//Disable access to Divisor Latches
 LPC_UART->LCR |= (1<<1) | (1<<0);				//8 data bits, 1 stop bit, No parity
 while(1)
 {
   		 while(!(LPC_UART->LSR & (1<<0)));		//Wait for full receive buffer
   		 c = LPC_UART->RBR;
   		 while(!(LPC_UART->LSR & (1<<5)));		//Wait for empty transmit buffer
   		 LPC_UART->THR = c;
 }

   	return 0;
}
