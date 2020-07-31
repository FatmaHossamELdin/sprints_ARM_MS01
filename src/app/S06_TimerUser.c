#include "Timer.h"


extern const Gpt_ConfigType Gpt_Config[];

void TimerUser(void)
{
	Gpt_Init(Gpt_Config);
	
	Gpt_StartTimer(GPT_16_32_BIT_TIMER0, 0xF);
	
	
}
