


#include "PORT.h"
#include "STD.h"







const			Pin_ConfigType      Port_Config [ ACTIVATED_PIN_SIZE ] =
{
	/*{  pinid 	,		 pindir  ,    pinMode  ,    PinInternalAttach    ,   pinCurrent   } */
	{  Port_Pin_F0 	,		 PORT_PIN_IN  ,    DIO_MODE  ,    PORT_ATTACH_PULLUP    ,   Port_PinTypeinCurrent_NA   } ,
	
	
	{  Port_Pin_F1 	,		 PORT_PIN_OUT ,    DIO_MODE  ,    PORT_ATTACH_DEFAULT    ,   Port_PinTypeinCurrent_NA  } 
	
} ;


const			Pin_ConfigType*        Cfg_ptr = Port_Config ;