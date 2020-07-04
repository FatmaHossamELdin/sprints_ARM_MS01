#include "Nvic.h"
#include "mcu_hw.h"
#include "platform_Types.h" 
#include "Nvic_cfg.h"

#define NVIC_GROUPING_SYSTEM_XXX 	4
#define	NVIC_GROUPING_SYSTEM_XXY 	5
#define	NVIC_GROUPING_SYSTEM_XYY 	6
#define	NVIC_GROUPING_SYSTEM_YYY 	7

extern const NVIC_CfgType NVIC_Cfg[NVIC_ACTIVATED_INT_SIZE];

void NVIC_init(void)
{
	NVIC_IntType IntNum;
	uint8 LocGroup, LocSubGroup,i;
	uint32 *NVIC_ENx, *NVIC_PRIx;
	uint8 NVIC_ENx_Bit, NVIC_PRIx_Bit;
	
	/* configure grouping and subgrouping int APINT register in SCB */
	
	/* to write on APINT we put 0x05FA in the VECTKEY field  and setting grouping mode*/
	APINT = (0x05FA0000)|(NVIC_GROUPING_SYSTEM << 8);
/*	APINT |= 0x05FA0000;
	APINT |= (NVIC_GROUPING_SYSTEM << 8);
*/	
	for(i=0; i< NVIC_ACTIVATED_INT_SIZE ;i++)
	{
		IntNum = NVIC_Cfg[i].Interupt_Number;
		LocGroup = NVIC_Cfg[i].Group_Priority;
		LocSubGroup = NVIC_Cfg[i].SubGroup_Priority;
		
		/* enable\disable based on user configuration */
			NVIC_ENx = EN0Adress + (IntNum/32);
			NVIC_ENx_Bit = IntNum%32;
			
			*NVIC_ENx |= (1 << NVIC_ENx_Bit);
				
		/* asign group\subgroup priority */
		
			NVIC_PRIx = PRI0Adress + (IntNum/4);
			
			NVIC_PRIx_Bit = 5 + (8 * (IntNum%4));
			
			#if NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX
			*NVIC_PRIx |=  (LocGroup << NVIC_PRIx_Bit);
			
			#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY
			*NVIC_PRIx |=  ((LocSubGroup << NVIC_PRIx_Bit)|(LocGroup << (NVIC_PRIx_Bit+1)));
			
			#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY
			*NVIC_PRIx |=  ((LocSubGroup << NVIC_PRIx_Bit)|(LocGroup << (NVIC_PRIx_Bit+2)));
			
			#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY
			*NVIC_PRIx |=  (LocSubGroup << NVIC_PRIx_Bit);
			
			#endif
		
	}	
}
