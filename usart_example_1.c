//Example shows how to set USART and send char to PC every some delay

#include "LPC11xx.h"
#define BAUD			9600
#define BAUD_DIVISOR		(48000000/(BAUD*16))
int main(void)
{

 int i;
 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);				//Enable clock for IOCON block
 LPC_IOCON->PIO1_6 = 1;						//Enable RXD function
 LPC_IOCON->PIO1_7 = 1;						//Enable TXD function
 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);				//Enable clock for UART
 LPC_SYSCON->UARTCLKDIV = 1;					//PCLK div 1
 LPC_UART->FCR = (1<<0);					//Enable for both UART RX and TX FIFOs
 LPC_UART->LCR = (1<<7); 					//Enable access to Divisor Latches
 LPC_UART->DLL = BAUD_DIVISOR & 0x00ff;
 LPC_UART->DLM = (BAUD_DIVISOR >> 8) & 0x00ff;
 LPC_UART->LCR &= ~(1<<7);					//Disable access to Divisor Latches
 LPC_UART->LCR |= (1<<1) | (1<<0);				//8 data bits, 1 stop bit, No parity
   	 while(1)
	{
   		 for(i=0; i<200000;i++);			//Delay
   		 while(!(LPC_UART->LSR & (1<<5)));		//Wait for empty Transmit buffer
   		 LPC_UART->THR = '1';
	}

   	return 0;
}
