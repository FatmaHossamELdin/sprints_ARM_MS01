#include "Timer.h"


extern const Gpt_ConfigType Gpt_Config[];

void TimerUser(void)
{
	Gpt_Init(Gpt_Config);
	
	Gpt_StartTimer(GPT_32_64_BIT_WIDE_TIMER1, 0xFF);
	

}
