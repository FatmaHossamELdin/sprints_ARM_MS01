/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic.h"
#include "mcu_hw.h"
#include "Nvic_cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define NVIC_GROUPING_SYSTEM_XXX 	4
#define	NVIC_GROUPING_SYSTEM_XXY 	5
#define	NVIC_GROUPING_SYSTEM_XYY 	6
#define	NVIC_GROUPING_SYSTEM_YYY 	7

#define APINT_VECTKEY 							0x05FA
#define APINT_VECTKEY_FIRLED_OFFSET 16u
#define PRIGROUP_FIELED_OFFSET			0x8u
#define NVIC_REG_NUM_OF_PRI_FIELDS	4u

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : Svoid NVIC_init(void)        
* \Description     : NVIC initialization                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : void
*******************************************************************************/
void NVIC_init(void)
{
	Nvic_IntType intNum;
	uint8 locGroup, locSubGroup,i,locGroupingField;
	uint32 enRegOffset, enBitOffset;
	uint32 priRegOffset, priBitOffset;
	
	/* configure grouping and subgrouping int APINT register in SCB */
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIRLED_OFFSET)
					|(NVIC_GROUPING_SYSTEM << PRIGROUP_FIELED_OFFSET);
	
	for(i=0; i< NVIC_ACTIVATED_INT_SIZE ;i++)
	{
		intNum			= NVIC_Cfg[i].Interupt_Number;
		locGroup		= NVIC_Cfg[i].Group_Priority;
		locSubGroup = NVIC_Cfg[i].SubGroup_Priority;
		
		/* enable\disable based on user configuration */
		enRegOffset = (intNum/WORD_LENGTH_BITS)*WORD_LENGTH_BYTES;
		enBitOffset = intNum%WORD_LENGTH_BITS;
			
		GET_HWREG(NVIC_BASE_ADDRESS,enRegOffset) |= (1 << enBitOffset);
				
		
#if NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX
			locGroupingField = locGroup;
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY
			locGroupingField = ((locGroup<<1)&0x6) | (locSubGroup&0x1);
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY
        locGroupingField = ((locGroup<<2)&0x4) | (locSubGroup&0x3);
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY
        locGroupingField = locGroup;
#else
     #error INVALID GROUPING SELECTION			
#endif
			
			/* asign group\subgroup priority */
		
			priRegOffset = (intNum/NVIC_REG_NUM_OF_PRI_FIELDS)*WORD_LENGTH_BYTES;
			priBitOffset = 5 + (8 * (intNum%NVIC_REG_NUM_OF_PRI_FIELDS));
			GET_HWREG(NVIC_PRI_BASE_ADDRESS,priRegOffset) |= (locGroupingField << priBitOffset);
		
		
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/

