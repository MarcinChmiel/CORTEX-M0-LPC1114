//Example shows how to use SysTick Timer

//FCPU 40MHz

#include "LPC11xx.h"

int main(void)
{
 LPC_GPIO0->DIR |= (1<<2);					//P0_2 output
 LPC_GPIO0->DATA &= ~(1<<2);					//P0_2 low
 SysTick_Config(12000000); 					//Set SysTick Timer with counting to 250ms

 while(1)					
 {

 }
    	return 0;
}

void SysTick_Handler(void)					//Interrupt function for SysTick timer
{
    	LPC_GPIO0->DATA ^= (1<<2);				//Switch P0_2 state
}
