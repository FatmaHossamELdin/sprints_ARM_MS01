

__attribute__((naked)) void CpuDriver_EnableGlobalInterupt(void);
__attribute__((naked)) void CpuDriver_DisableGlobalInterupt(void);

__attribute__((naked)) void CpuDriver_StartCriticalSection(void);
__attribute__((naked)) void CpuDriver_StopCriticalSection(void);