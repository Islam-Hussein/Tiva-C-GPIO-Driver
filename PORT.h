

#ifndef PORT_H_
#define PORT_H_

#include "mcu_hw.h"
#include "STD.h"
#include "PORT_Cfg.h"
#include "BIT_MATH.h"



typedef uint8 Port_PinType;

#define Port_Pin_A0     0
#define Port_Pin_A1     1
#define Port_Pin_A2     2
#define Port_Pin_A3     3
#define Port_Pin_A4     4
#define Port_Pin_A5     5
#define Port_Pin_A6     6
#define Port_Pin_A7     7


#define Port_Pin_B0     8
#define Port_Pin_B1     9
#define Port_Pin_B2     10
#define Port_Pin_B3     11
#define Port_Pin_B4     12
#define Port_Pin_B5     13
#define Port_Pin_B6     14
#define Port_Pin_B7     15

#define Port_Pin_C0     16
#define Port_Pin_C1     17
#define Port_Pin_C2     18
#define Port_Pin_C3     19
#define Port_Pin_C4     20
#define Port_Pin_C5     21
#define Port_Pin_C6     22
#define Port_Pin_C7     23

#define Port_Pin_D0     24
#define Port_Pin_D1     25
#define Port_Pin_D2     26
#define Port_Pin_D3     27
#define Port_Pin_D4     28
#define Port_Pin_D5     39
#define Port_Pin_D6     30
#define Port_Pin_D7     31

#define Port_Pin_E0     32
#define Port_Pin_E1     33
#define Port_Pin_E2     34
#define Port_Pin_E3     35
#define Port_Pin_E4     36
#define Port_Pin_E5     37
#define Port_Pin_E6     38
#define Port_Pin_E7     39

#define Port_Pin_F0     40
#define Port_Pin_F1     41
#define Port_Pin_F2     42
#define Port_Pin_F3     43
#define Port_Pin_F4     44
#define Port_Pin_F5     45
#define Port_Pin_F6     46
#define Port_Pin_F7     47


typedef uint8 Port_PinMode;
#define DIO_MODE   0


typedef enum 
{
	PORT_PIN_IN,
	PORT_PIN_OUT
	
}PortDirectionType;


typedef enum
	{
		PORT_ATTACH_DEFAULT,
		PORT_ATTACH_PULLUP,
		PORT_ATTACH_PULLDOWN,
		PORT_ATTACH_OPENDRAIN
	}PortInternalAttach;


	typedef enum 
	{
		Port_PinTypeinCurrent_NA,
		Port_PinTypeinCurrent2ma,
		Port_PinTypeinCurrent4ma,
		Port_pinTypeinCurrent8ma
	}Port_Pin_Current;


	
	typedef struct
	{
		Port_PinType    			PinId;
		PortDirectionType			PinDir;
		Port_PinMode					PinMode;
		PortInternalAttach    PinInternalAttach;
		Port_Pin_Current      Pin_Current;
	}Pin_ConfigType;
	
	
	
	extern  	const	  Pin_ConfigType*     Cfg_ptr;
	
	
	
	
	
	void Port_Init( const	 Pin_ConfigType*  Config_ptr);
	
	
	
	

#endif