#include "Port.h"
#include "Dio.h"


extern const Port_ConfigType Port_Config[];
Dio_LevelType channelLevel= STD_LOW;

void DioUser(void)
{
	
	Port_Init(Port_Config);
	Dio_WriteChannel(Channel_B7,STD_HIGH);
	channelLevel = Dio_ReadChannel(Channel_B7);
}