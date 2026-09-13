// Adapted from pc_decomp_backup/src/functions/FUN_00432930.cpp
// Historical source SHA256: 2b1e0a3b61c808c1e229052369afa20844b6ca35d59e8c8e6a87f0f491901bed
extern "C" {
extern "C" void __cdecl FUN_00431730(void**);
extern "C" void __cdecl FUN_0041E7C0(void**);
extern "C" void** __cdecl FUN_0041A380(void**);
extern "C" void __cdecl FUN_004327F0(void*);

extern "C" void __cdecl GEX_Target(void** param1)
{
    if (param1[0x59] != 0)
        GEX_Target((void**)param1[0x59]);
    if (param1[0x58] != 0)
        GEX_Target((void**)param1[0x58]);
    FUN_00431730(param1);
    param1[0x17] = 0;
    param1[0x19] = 0;
    param1[0x1b] = (void*)((unsigned int)param1[0x1b] & 0xffbfffff);
    param1[0x26] = 0;
    param1[0x18] = (void*)&FUN_004327F0;
    param1[0x28] = (void*)0x1e;
    param1[0x27] = 0;
    FUN_0041E7C0(param1);
    void** ppGVar1 = FUN_0041A380(param1);
    
    void* pGVar2;
    void* pGVar3;
    if (((unsigned int)param1[0x1b] & 0x40000000) == 0)
    {
        pGVar3 = ppGVar1[1];
        pGVar2 = ppGVar1[3];
    }
    else
    {
        pGVar3 = (void*)-(int)ppGVar1[3];
        pGVar2 = (void*)-(int)ppGVar1[1];
    }
    param1[0x2a] = 0;
    param1[0x2b] = (void*)((int)pGVar3 + ((int)pGVar2 + (1 - (int)pGVar3) >> 1) + -0x1c);
}
}
