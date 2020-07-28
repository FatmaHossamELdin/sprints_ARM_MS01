#include "Mcu.h"
extern const Mcu_ConfigType McuConfig[];
void McuUser(void)
{
	Mcu_Init(McuConfig);
	Mcu_InitClock(1);
//	while(Mcu_GetPllStatus() == MCU_PLL_STATUS_UNLOCKED);
//	Mcu_DistributePllClock();
	
}
