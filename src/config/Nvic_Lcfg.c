#include "Nvic.h"
#include "Nvic_cfg.h"

const NVIC_CfgType NVIC_Cfg[NVIC_ACTIVATED_INT_SIZE] ={
	/* Interupt_Number    Group_Priority     SubGroup_Priority */
	{ NVIC_GPIO_Port_A,    2,                 0                },
	{ NVIC_GPIO_Port_B,    1,                 0                },
	{ NVIC_GPIO_Port_C,    3,                 0                },
		
};


