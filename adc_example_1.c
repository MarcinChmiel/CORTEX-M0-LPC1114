//Example shows how to set ADC
//When analog voltage is greater than 2V - turn on LED
//P1_0 - AD1	-	analog input
//P0_2 - LED	-	digital output
//1024 - Vref
//ADC - V_AD1
//V_AD1 = ADC * Vref / 1024


#include "LPC11xx.h"
#define Vref 3.1

int main(void)
{
	LPC_GPIO0->DIR |= (1<<2);						//Set P0_2 as output
	LPC_GPIO0->DATA = 0;							//GPIO2 Init

	//ADC INIT
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);					//Enables clock for I/O configuration block
	LPC_IOCON->R_PIO1_0 = (1<<1);						//Selects function AD1
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<13);					//Enables clock for ADC
	LPC_SYSCON->PDRUNCFG &= ~(1<<4);					//ADC Powered
	LPC_ADC->CR |= (1<<1);							//Selects AD1
	LPC_ADC->CR |= (1<<11) | (1<<9);					//CLKDIV 10+1 -> APB clock < 4.5MHz


	float result;
	int i;


   	 while(1)
	{
   		for(i=0; i<400000; i++); 					//Delay
   		LPC_ADC->CR |= (1<<24);						//Start Conversion
   		while(!(LPC_ADC->GDR & (1<<31)));				//Wait until conversion completes
   		result = ( (LPC_ADC->GDR >> 6) & 0x3FF ) * Vref / 1024;
   		if(result > 2)
   			LPC_GPIO0->DATA |= (1<<2);				//Set P0_2 HIGH
   		else
   			LPC_GPIO0->DATA &= ~(1<<2);				//Set P0_2 LOW
	}

   	return 0;
}
