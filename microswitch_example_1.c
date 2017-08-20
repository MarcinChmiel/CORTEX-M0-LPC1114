//Example shows how to switch LED state every time when BUTTON is pressed
//PIN P0_2 - LED
//PIN P0_3 - BUTTON

#include "LPC11xx.h"

int main(void)
{

 int last_button_state = 0;
 int i;
 LPC_GPIO0->DIR |= (1<<2);						//P0_2 OUTPUT
 LPC_GPIO0->DATA &= ~(1<<2);						//LED OFF
 LPC_GPIO0->DIR &= ~(1<<3);						//P0_3 INPUT
 while(1)
 {
    	int button_state = ( LPC_GPIO0->DATA & (1<<3) );		//Read P0_3 STATE
    	if(button_state != last_button_state)
    		for(i=0; i<240000; i++);				//Debouncing
    		if(button_state == (1<<3))				//If pressed
    			LPC_GPIO0->DATA ^= (1<<2);			//Change LED STATE
    	last_button_state = button_state;
 }
    return 0;
}
