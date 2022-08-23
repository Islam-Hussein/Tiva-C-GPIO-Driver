


#include "PORT.h"


#define 	Pin_Size_In_Port				8
#define 	Max_Num_GPIO_Ports			6



static 	const 	uint32  Port_BaseAddress [Max_Num_GPIO_Ports] =
{
	GPIO_APB_BASE_ADDRESS_A,
	GPIO_APB_BASE_ADDRESS_B,
	GPIO_APB_BASE_ADDRESS_C,
	GPIO_APB_BASE_ADDRESS_D,
	GPIO_APB_BASE_ADDRESS_E,
	GPIO_APB_BASE_ADDRESS_F
};


	void	Port_Init( const	 Pin_ConfigType*  Config_ptr)
	{
		
		Port_PinType    			PinId;
		PortDirectionType			PinDir;
		
		uint8 	cnt , 	PortIndex , PinIndex ;	
		uint32 	BaseAddr ;
		
		for(cnt = 0 ; cnt < ACTIVATED_PIN_SIZE ; cnt++)
		{
			PinId 	= Config_ptr[cnt].PinId  ;
			PinDir	= Config_ptr[cnt].PinDir ;
			
			
			PortIndex = PinId / Pin_Size_In_Port;
			PinIndex	= PinId % Pin_Size_In_Port;
			
			BaseAddr = Port_BaseAddress[PortIndex];
			
			SYSCTL->RCGC2 = (1	<< PortIndex);
			
			
			GPIO(BaseAddr)->LOCK = 0x4C4F434B;
			GPIO(BaseAddr)->CR 	 = (1 << PinIndex);
			
			GPIO(BaseAddr)->DIR  |= (PinDir << PinIndex);
			
			
			switch (Config_ptr[cnt].PinMode)
			{
				case DIO_MODE:
				
				GPIO(BaseAddr)->AFSEL &=~  (1 << PinIndex); 
				GPIO(BaseAddr)->DEN 	|=  (1 << PinIndex); 
				GPIO(BaseAddr)->AMSEL &=~  (1 << PinIndex); 
				break;
				
				
				
				default:
				break;
			
			}
			
			
			switch(Config_ptr[cnt].PinInternalAttach)
			{
				case PORT_ATTACH_PULLUP:
				GPIO(BaseAddr)->PUR 	|=  (1<<PinIndex);
				break;
				
				case PORT_ATTACH_PULLDOWN:
				GPIO(BaseAddr)->PDR 	|=  (1<<PinIndex);
				break;
				
				case PORT_ATTACH_OPENDRAIN:
				GPIO(BaseAddr)->ODR 	|=  (1<<PinIndex);
				break;
				
				
				
				
				default:
				break;
			}
			
			
			
			
			
		}
		
		
		
		
	
	
	}
