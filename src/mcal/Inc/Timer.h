/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "platform_Types.h"
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	GPT_16_32_BIT_TIMER0,
	GPT_16_32_BIT_TIMER1,
	GPT_16_32_BIT_TIMER2,
	GPT_16_32_BIT_TIMER3,
	GPT_16_32_BIT_TIMER4,
	GPT_16_32_BIT_TIMER5,
	GPT_32_64_BIT_WIDE_TIMER0,
	GPT_32_64_BIT_WIDE_TIMER1,
	GPT_32_64_BIT_WIDE_TIMER2,
	GPT_32_64_BIT_WIDE_TIMER3,
	GPT_32_64_BIT_WIDE_TIMER4,
	GPT_32_64_BIT_WIDE_TIMER5
}Gpt_ChannelType; 

typedef uint32 Gpt_ValueType;

typedef enum
{
	GPT_MODE_NORMAL,
	GPT_MODE_SLEEP 
}Gpt_ModeType;

typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef uint32 Gpt_ChannelTickFrequency;
typedef uint32 GptChannelTickValueMax;

typedef enum
{
	GPT_CH_MODE_CONTINUOUS,
	GPT_CH_MODE_ONESHOT
}ChannelMode;

typedef uint32* GptNotification;

typedef struct
{
	Gpt_ChannelType  					channel;
	Gpt_ChannelTickFrequency  channelTickFreq;
	GptChannelTickValueMax  	channelTickMaxValue;
	ChannelMode								channelMode;
	GptNotification						gptNotification;
}Gpt_ConfigType;

#define PREDEF_TIMERS_INT_SIZE   4

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_Notification_Channel ( void);
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
