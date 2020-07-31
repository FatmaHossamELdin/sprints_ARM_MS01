#include "Timer.h"

extern GptNotification	locGptNotification[];


int main ()
{
	NvicUser();
	McuUser();
	DioUser();
	
//	WdtUser();
	TimerUser();
	
	while(1)
	{
		
	}
	return 0 ;
}



void TIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_16_32_BIT_TIMER0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_16_32_BIT_TIMER0];
		gptNotificationFn_TIMER0A();
	}
}

void TIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER1A;
	if (locGptNotification[GPT_16_32_BIT_TIMER1] != NULL)
	{
		gptNotificationFn_TIMER1A = locGptNotification[GPT_16_32_BIT_TIMER1];
		gptNotificationFn_TIMER1A();
	}
}

void TIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER2A;
	if (locGptNotification[GPT_16_32_BIT_TIMER2] != NULL)
	{
		gptNotificationFn_TIMER2A = locGptNotification[GPT_16_32_BIT_TIMER2];
		gptNotificationFn_TIMER2A();
	}
}

void TIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER3A;
	if (locGptNotification[GPT_16_32_BIT_TIMER3] != NULL)
	{
		gptNotificationFn_TIMER3A = locGptNotification[GPT_16_32_BIT_TIMER3];
		gptNotificationFn_TIMER3A();
	}
}

void TIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER4A;
	if (locGptNotification[GPT_16_32_BIT_TIMER4] != NULL)
	{
		gptNotificationFn_TIMER4A = locGptNotification[GPT_16_32_BIT_TIMER4];
		gptNotificationFn_TIMER4A();
	} 
}

void TIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER5A;
	if (locGptNotification[GPT_16_32_BIT_TIMER5] != NULL)
	{
		gptNotificationFn_TIMER5A = locGptNotification[GPT_16_32_BIT_TIMER5];
		gptNotificationFn_TIMER5A();
	}
}

void WTIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER0A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER0] != NULL)
	{
		gptNotificationFn_WTIMER0A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER0];
		gptNotificationFn_WTIMER0A();
	}
}

void WTIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER1A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER1] != NULL)
	{
		gptNotificationFn_WTIMER1A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER1];
		gptNotificationFn_WTIMER1A();
	}
}

void WTIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER2A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER2] != NULL)
	{
		gptNotificationFn_WTIMER2A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER2];
		gptNotificationFn_WTIMER2A();
	}
}

void WTIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER3A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER3] != NULL)
	{
		gptNotificationFn_WTIMER3A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER3];
		gptNotificationFn_WTIMER3A();
	}
}

void WTIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER4A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER4] != NULL)
	{
		gptNotificationFn_WTIMER4A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER4];
		gptNotificationFn_WTIMER4A();
	}
}

void WTIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER5A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER5] != NULL)
	{
		gptNotificationFn_WTIMER5A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER5];
		gptNotificationFn_WTIMER5A();
	}
}
