#ifndef NVIC_H_
#define NVIC_H_

#include "platform_Types.h"  

typedef enum{
	NVIC_GPIO_Port_A,
	NVIC_GPIO_Port_B,
	NVIC_GPIO_Port_C,
	NVIC_GPIO_Port_D,
	NVIC_GPIO_Port_E,
	
}NVIC_IntType;

typedef struct{
	NVIC_IntType	Interupt_Number;
	uint8			Group_Priority;
	uint8			SubGroup_Priority;
}NVIC_CfgType;


void NVIC_init(void);


#endif
