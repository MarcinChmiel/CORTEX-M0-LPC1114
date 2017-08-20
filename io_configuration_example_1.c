//Example shows how to configure IO pins

#include "LPC11xx.h"

int main(void)
{

 LPC_GPIO0->DIR |= (1<<2);			//Set P0_2 as output
 LPC_GPIO0->DATA |= (1<<2);			//Set P0_2 pin

 while(1)
 {

    
    return 0;
 }
}
