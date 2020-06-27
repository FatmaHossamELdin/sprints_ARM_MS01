#include "Cpu_Driver.h"

__attribute__((naked)) void CpuDriver_EnableGlobalInterupt(void)
{
	__asm ("CPSIE i") ; /* clear PRIMASK */
	__asm ("CPSIE f") ; /* clear FAULTMASK*/
}

__attribute__((naked)) void CpuDriver_DisableGlobalInterupt(void)
{
	__asm ("CPSID i") ; /* set PRIMASK*/
	__asm ("CPSID f") ; /* set FAULTMASK*/
}

__attribute__((naked)) void CpuDriver_StartCriticalSection(void)
{
	__asm ("CPSID i") ; /* set PRIMASK*/
	__asm ("CPSID f") ; /* set FAULTMASK*/
}

__attribute__((naked)) void CpuDriver_StopCriticalSection(void)
{
	__asm ("CPSIE i") ; /* clear PRIMASK */
	__asm ("CPSIE f") ; /* clear FAULTMASK*/
}