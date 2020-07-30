/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer_Cfg.h"
#include "Timer.h"
#include "mcu_hw.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MAX_NUMBER_OF_GPIO_GPT 		12u

#define TAEN 		0
#define TBEN 		8

#define TACDIR	4
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static GptNotification						locGptNotification;
static Gpt_ChannelTickFrequency 	locChannelTickFreq;
static GptChannelTickValueMax  		locChannelTickMaxValue;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern volatile uint32 GlobalSystemClock;
static const uint32 Gpt_BaseAddress[MAX_NUMBER_OF_GPIO_GPT] = {GPT_16_32_BIT_TIMER0_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER1_BASE_ADDRESS,		
	                                                           GPT_16_32_BIT_TIMER2_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER3_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER4_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER5_BASE_ADDRESS,			
	                                                           GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void Gpt_NotificationFn(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr)
{
	uint8 i;
	uint32 gptBaseAddress;
	Gpt_ChannelType  	locChannel;
	ChannelMode				locChannelMode;
	
	
	for(i=0;i<GPT_ACTIVATED_CHANNELS_SIZE;i++)
	{
		locChannel								= ConfigPtr[i].channel;
		locChannelTickFreq				= ConfigPtr[i].channelTickFreq;
		locChannelTickMaxValue		= ConfigPtr[i].channelTickMaxValue;
		locChannelMode						= ConfigPtr[i].channelMode;
		
		gptBaseAddress = Gpt_BaseAddress[locChannel];
		GPTMCTL(gptBaseAddress) =	0;
		
		/*
		* For a 16/32-bit timer, this value selects the 16-bit timer configuration.
		* For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.
		*/
		GPTMCFG(gptBaseAddress) = 0x4;
		
			/* counting up */
		GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);
		
		/* channel mode */
		if (locChannelMode == GPT_CH_MODE_ONESHOT)
		{
			GPTMTAMR(gptBaseAddress) |= 0x1;
		}
		else if (locChannelMode == GPT_CH_MODE_CONTINUOUS)
		{
			GPTMTAMR(gptBaseAddress) |= 0x2; 
		}
		
		/* Disablling interupt notifation */
		Gpt_DisableNotification(locChannel);
	}		
		/* Predef timers */
#if GPT_PREDEF_TIMER_1US_16BIT_STATUS == Enable

#else
		
#endif
		
#if GPT_PREDEF_TIMER_1US_24BIT_STATUS == Enable

#else
		
#endif

#if GPT_PREDEF_TIMER_1US_32BIT_STATUS == Enable

#else	
		
#endif
		
#if GPT_PREDEF_TIMER_100US_32BIT_STATUS == Enable

#else

#endif	
}

void Isr_Timer(void)
{
	if (locGptNotification != NULL)
	{
		locGptNotification();
	}
}
/******************************************************************************
* \Syntax          : void Gpt_DisableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMIMR(gptBaseAddress) = 0;
}
/******************************************************************************
* \Syntax          : void Gpt_EnableNotification( Gpt_ChannelType Channel )        
* \Description     : Enables the interrupt notification for a channel (relevant in normal mode).                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMIMR(gptBaseAddress) = 0x1;
}

/******************************************************************************
* \Syntax          : Gpt_GetTimeElapsed( Gpt_ChannelType Channel )        
* \Description     : Returns the time already elapsed.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): Gpt_ValueType                                                      
* \Return value:   : Gpt_ValueType  uint32                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel )
{
	
}

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
Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
	
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )       
* \Description     : Returns the time remaining until the target time is reached.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  uint32                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{
	
}


/******************************************************************************
* \Syntax          : void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );        
* \Description     : Starts a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant(but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel. 
*										 Value		 Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
	uint32 i;
	uint32 prescale;
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	
	prescale = GlobalSystemClock / locChannelTickFreq;
	for(i=2;;i*=2)
	{
		if(prescale/i == 1)
		{
			if(prescale%i <= (i/2))
			{
				prescale = i;
			}
			else
			{
				prescale = i*2;
			}
			break;
		}
	}
	/* adding the value deppending on the freq required */
	GPTMTAILR(gptBaseAddress) = Value * prescale;
	
	GPTMCTL(gptBaseAddress) |= (1<<TAEN);
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer( Gpt_ChannelType Channel )       
* \Description     : Stops a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                           
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	
	GPTMCTL(gptBaseAddress) &= (~(1<<TAEN));
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
