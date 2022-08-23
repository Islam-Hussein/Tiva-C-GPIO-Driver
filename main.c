
//#include <TM4C123GH6PM.h>

#include "PORT.h"



int main(void)
{

	
	uint32 input_value = 0;
	Port_Init(Cfg_ptr);




	while(1)
	{
		input_value = GPIO(GPIO_APB_BASE_ADDRESS_F)->DATA  & (0x01) ;
		while((GPIO(GPIO_APB_BASE_ADDRESS_F)->DATA  & (0x01) ) == 0);
		
		if(! input_value)
		{
			GPIO(GPIO_APB_BASE_ADDRESS_F)->DATA  ^= 0x01;
		}
	
	
	
	}


	return 0;
}







