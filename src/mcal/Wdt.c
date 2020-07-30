/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
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
#include "platform_Types.h" 
#include "Wdt.h"
#include "mcu_hw.h"
#include "Wdt_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define WRC     31
#define RESEN		1
#define INTEN		0
#define INTTYPE 2

#define WDG_UNLOCK_VALUE			0x1ACCE551
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
volatile WdgMaxTimeout		locMaxTimeout;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern volatile uint32 GlobalSystemClock;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  
*******************************************************************************/
void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )
{
	WdgNotificationEnable		locNotificationEn;
	WdgInterruptType				locInterruptType;
	WdgInitialTimeout				locIntialTimeout;
	
	
	locNotificationEn	=	ConfigPtr->notificationEn;
	locInterruptType	=	ConfigPtr->interruptType;
	locIntialTimeout	=	ConfigPtr->intialTimeout;
	locMaxTimeout			=	ConfigPtr->maxTimeout;
	
	/* TODO 1. Load the WDTLOAD register with the WdgInitialTimeout in configuration struct  */
	/* convert time to ticks*/
	locIntialTimeout *= GlobalSystemClock;
	
	WDTLOAD(WDT_BASE_ADDRESS) = locIntialTimeout;
	/* TODO 2 wait for the WRC bit in the WDTCTL register to be set. */
	while ((WDTCTL(WDT_1_BASE_ADDRESS)>>WRC) == 0);
	
	/* TODO 3. set the RESEN bit in the WDTCTL register. */
	WDTCTL(WDT_BASE_ADDRESS) |= (1<<RESEN);
	
	/* TODO 4. If WDT1, wait for the WRC bit in the WDTCTL register to be set. */
	while ((WDTCTL(WDT_1_BASE_ADDRESS)>>WRC) == 0);
	
	/* setting interruptType*/
	WDTCTL(WDT_BASE_ADDRESS) |= (1<<INTTYPE);
	while ((WDTCTL(WDT_1_BASE_ADDRESS)>>WRC) == 0);
	
	/* TODO 5. Set the INTEN bit in the WDTCTL register to enable the Watchdog  enable interrupts*/
	WDTCTL(WDT_BASE_ADDRESS) |= (1<<INTEN);
    /* TODO 6 lock  TODO the control register. */
	WDTLOCK(WDT_BASE_ADDRESS) = 1;
	
	
	
	
}

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition ( uint16 timeout )        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                        
* \Parameters (out): None                                                      
* \Return value:   : void  
*******************************************************************************/
void Wdg_SetTriggerCondition ( uint16 timeout )
{
	/*The timeout value passed shall be interpreted as 'milliseconds'.
	The conversion from milliseconds to the corresponding counter value shall be done internally by the Wdg module*/
	
	/* In case the counter value stored inside watchdog has the value "0", 
	the service Wdg_SetTriggerCondition shall do nothing,
	which means it shall ignore the counter passed by the parameter*/
	
	
	
	/*TODO check if timeout < WdgMaxTimeout */
	if(timeout > locMaxTimeout)
	{
		/*Report to Det*/
	}
	else
	{
		/* unlocking WDG */
		WDTLOCK(WDT_BASE_ADDRESS) = 0x1ACCE551;

		/* TODO  Load the WDTLOAD register with the timeout value */
		timeout *= GlobalSystemClock;
		WDTLOAD(WDT_BASE_ADDRESS) = timeout;
		
		WDTLOCK(WDT_BASE_ADDRESS) = 1;
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
