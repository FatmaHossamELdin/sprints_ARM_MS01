/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Port_PinType;
#define Port_Pin_A0			0
#define Port_Pin_A1			1
#define Port_Pin_A2			2
#define Port_Pin_A3			3
#define Port_Pin_A4			4
#define Port_Pin_A5			5
#define Port_Pin_A6			6
#define Port_Pin_A7			7

#define Port_Pin_B0			8
#define Port_Pin_B1			9
#define Port_Pin_B2			10
#define Port_Pin_B3			11
#define Port_Pin_B4			12
#define Port_Pin_B5			13
#define Port_Pin_B6			14
#define Port_Pin_B7			15


#define Port_Pin_C0			16
#define Port_Pin_C1			17
#define Port_Pin_C2			18
#define Port_Pin_C3			19
#define Port_Pin_C4			20
#define Port_Pin_C5			21
#define Port_Pin_C6			22
#define Port_Pin_C7			23


#define Port_Pin_D0			24
#define Port_Pin_D1			25
#define Port_Pin_D2			26
#define Port_Pin_D3			27
#define Port_Pin_D4			28
#define Port_Pin_D5			29
#define Port_Pin_D6			30
#define Port_Pin_D7			31

#define Port_Pin_E0			32
#define Port_Pin_E1			33
#define Port_Pin_E2			34
#define Port_Pin_E3			35
#define Port_Pin_E4			36
#define Port_Pin_E5			37
#define Port_Pin_E6			38
#define Port_Pin_E7			39

#define Port_Pin_F0			40
#define Port_Pin_F1			41
#define Port_Pin_F2			42
#define Port_Pin_F3			43
#define Port_Pin_F4			44
#define Port_Pin_F5			45
#define Port_Pin_F6			46
#define Port_Pin_F7			47


typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;


typedef uint8 Port_PinModeType;
#define Port_PinMode_X_DIO			0
#define Port_PinMode_PA0_U0RX		1
#define Port_PinMode_PA1_U0TX		1
#define Port_PinMode_PA2_SSI0Clk	2

typedef enum
{
	PORT_ATTACH_DEFAULT,
	PORT_ATTACH_PULLUP,
	PORT_ATTACH_PULLDOWN,
	PORT_ATTACH_OPENDRAIN
	
}Port_PinInternalAttachType;

typedef enum
{
	PORT_PIN_CURRENT_NA,
	PORT_PIN_CURRENT_2m,
	PORT_PIN_CURRENT_4m,
	PORT_PIN_CURRENT_8m
}Port_PinOutputCurrentType;

typedef enum
{
	PORT_EXT_INT_DISABLE,
	PORT_EXT_INT_RISING,
	PORT_EXT_INT_FALLING,
	PORT_EXT_INT_BOTH,
}Port_PinExternalIntType;

typedef struct
{
	Port_PinType				pinId;
	Port_PinDirectionType		pinDir;
	Port_PinModeType			pinMode; 
	Port_PinOutputCurrentType	currentStrength;
	Port_PinInternalAttachType	internalAttach;
	Port_PinExternalIntType		externalInt;
}Port_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init ( const Port_ConfigType* ConfigPtr );
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/