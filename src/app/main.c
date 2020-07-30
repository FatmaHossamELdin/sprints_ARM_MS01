#include "Wdt.h"

extern const Wdg_ConfigType Wdg_Config;
int main ()
{
	NvicUser();
	McuUser();
	DioUser();
	
	Wdg_Init(&Wdg_Config);
	
	
	while(1)
	{
		
	}
	return 0 ;
}
