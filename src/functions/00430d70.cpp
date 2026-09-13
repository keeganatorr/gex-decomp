// Adapted from pc_decomp_backup/src/functions/FUN_00430D70.cpp
// Historical source SHA256: d0e3a32445c37be0c10a306655c49aa8e21d42d2c47d6797c56f579d0a476950
extern "C" {
extern "C" void __cdecl FUN_0042e850(void**);
extern "C" void __cdecl FUN_00441150(void*);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar1;
    void* pGVar2;
    void* pGVar3;
    void* pGVar4;

    pGVar1 = param_1[0x1f];
    pGVar2 = param_1[0x1e];
    pGVar3 = param_1[0x32];
    pGVar4 = param_1[0x33];
    param_1[0x38] = (void*)((unsigned int)param_1[0x38] | 0x40);
    FUN_0042e850(param_1);
    FUN_00441150((void*)param_1);
    param_1[0x1e] = pGVar2;
    param_1[0x1f] = pGVar1;
    param_1[0x32] = pGVar3;
    param_1[0x33] = pGVar4;
}
}
