// Adapted from pc_decomp_backup/src/functions/FUN_004334C0.cpp
// Historical source SHA256: 22c64468cd0170068d7eff2c90463d6014883429595f5a1ee27ca7ddd6b7faa1
extern "C" {
extern "C" void __cdecl FUN_00444530(void**);
extern "C" void __cdecl FUN_0042e850(void**);
extern "C" void __cdecl FUN_00441150(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar1 = param_1[0x1f];
    void* pGVar2 = param_1[0x1e];
    void* pGVar3 = param_1[0x32];
    void* pGVar4 = param_1[0x33];

    FUN_00444530(param_1);
    FUN_0042e850(param_1);
    FUN_00441150(param_1);
    param_1[0x1e] = pGVar2;
    param_1[0x1f] = pGVar1;
    param_1[0x32] = pGVar3;
    param_1[0x33] = pGVar4;
}
}
