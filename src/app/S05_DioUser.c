#include "Port.h"
#include "Dio.h"


extern const Port_ConfigType Port_Config[];

void DioUser(void)
{
	Port_Init(Port_Config);
	Dio_WriteChannel(Channel_B7,STD_HIGH);
}