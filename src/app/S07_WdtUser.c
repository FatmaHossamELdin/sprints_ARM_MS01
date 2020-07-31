#include "Wdt.h"

extern const Wdg_ConfigType Wdg_Config;

void WdtUser(void)
{
	Wdg_Init(&Wdg_Config);
	
}