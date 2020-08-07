#include "Timer.h"


Gpt_ValueType value;

int main ()
{
	uint16 i;
	NvicUser();
	McuUser();
	DioUser();
	
//	WdtUser();
	TimerUser();
	
	while(1)
	{
		
		for(i=0;i<10000;i++)
		{
			i=i;
		}
		
		value = Gpt_GetTimeElapsed(GPT_32_64_BIT_WIDE_TIMER1);
	}
	return 0 ;
}

