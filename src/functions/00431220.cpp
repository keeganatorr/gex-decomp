// Adapted from pc_decomp_backup/src/functions/FUN_00431220.cpp
// Historical source SHA256: 575ac8d28e960024d2a4bd099eb439f76256c3bbd8500c91e2452894b2b8d22a
extern "C" {
extern "C" void __cdecl FUN_0042e850(void**);
extern "C" void __cdecl FUN_00441150(void**);

extern "C" void __cdecl ob232Draw_00431220(void** param_1)
{
    void* pGVar1 = param_1[0x1e];
    void* pGVar2 = param_1[0x1f];
    void* pGVar3 = param_1[0x32];
    void* pGVar4 = param_1[0x33];
    
    FUN_0042e850(param_1);
    FUN_00441150(param_1);
    param_1[0x1e] = pGVar1;
    param_1[0x1f] = pGVar2;
    param_1[0x32] = pGVar3;
    param_1[0x33] = pGVar4;
}
}
