//Example shows how to set PWM mode with CT16B1 timer

#include "LPC11xx.h"

int main(void)
{
	int i;
	int k = 1;

	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<8);   		// Enable TIMER16_1 clock
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);		// Enable IOCON clock
	LPC_IOCON->PIO1_9 = 1;        			// PIO1_9 - CT16B1_MAT0 FUNCTION
	LPC_TMR16B1->PWMC |= (1<<0);       		// PWM mode is enabled for CT16B1_MAT0
	LPC_TMR16B1->PWMC |= (1<<3);       		// PWM mode is enabled for match channel 3 = PERIOD
	LPC_TMR16B1->MCR |= (1<<10);       		// MR3 resets timer
	LPC_TMR16B1->MR3 = 960;         		// PERIOD: Example : 50kHz, 48Mhz/50k = 960
	LPC_TMR16B1->MR0 = 0;          			// DUTY CYCLE: MR3 = 0%, 0 = 100%
	LPC_TMR16B1->TCR = 1;            		// Enable Timer1


   	 while(1)
	{

   		for(i=0; i<3000; i++);			//Some delay
		LPC_TMR16B1->MR0 += k;			//Duty cycle update
		if(LPC_TMR16B1->MR0 == 0 || LPC_TMR16B1->MR0 == 960)
			k *= -1;
	}

   	return 0;
}
