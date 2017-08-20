//Example shows how to switch pin state with some delay.

#include "LPC11xx.h"

int main(void)
{

 int i;

 LPC_GPIO0->DIR |= (1<<2);			//P0_2 as output
 LPC_GPIO0->DATA |= (1<<2);			//Set P0_2

 while(1)
 {
    		for(i=0; i<400000; i++);
    		LPC_GPIO0->DATA ^= (1<<2);		//Switch P0_2 state
 }
    return 0;
}
