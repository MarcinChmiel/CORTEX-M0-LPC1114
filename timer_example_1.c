//Example shows how to set & use CT16B0 timer

#include "LPC11xx.h"

int main(void)
{
	//CT16B0 Timer INIT
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);			//CT16B0 clock enable
	LPC_TMR16B0->TCR = 2;					//Timer Control Register: Reset Timer
	LPC_TMR16B0->MCR = 3;					//Match Control Register: Interrupt & TC Reset on MR0
	LPC_TMR16B0->MR0 = 12000;				//Match Register: ( 250ms )
	LPC_TMR16B0->PR = 999;					//Prescaler 1000 ( 0-999 )
	LPC_TMR16B0->TCR = 1;					//Timer enabled
	NVIC_EnableIRQ(TIMER_16_0_IRQn);			//Interrupt permission for CT16B0 timer
	LPC_GPIO0->DIR |= (1<<2);				//P0_2 output
	LPC_GPIO0->DATA &= ~(1<<2);				//P0_2 low

    while(1)
    {

    }
    return 0 ;
}

void TIMER16_0_IRQHandler (void)
{
	LPC_GPIO0->DATA ^= (1<<2);				//Switch P0_2 state
	LPC_TMR16B0->IR |= (1<<0);				//Reset MR0 interrupt flag
}
