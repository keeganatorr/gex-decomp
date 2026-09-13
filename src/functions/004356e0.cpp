// Adapted from pc_decomp_backup/src/functions/FUN_004356E0.cpp
// Historical source SHA256: 06a28ca47e7722f7e98fb17300b638be63fd895e11618cd7b27ab0afca9f2c07
extern "C" {
extern "C" { extern int DAT_0045b7d8_framecount_; }
extern "C" void __cdecl FUN_0041A340(void**, int);
extern "C" void __cdecl FUN_00422470_EatObjects(void**);

extern "C" void __cdecl GEX_Target(void** param_1, int* param_2)
{
    int iVar1;
    void* pGVar2;

    if (*param_2 == 0) return;
    if (param_1[0x1c] != 0) return;
    if ((((int*)param_1[0x5d])[0] & 0xffff) != 1) return;
    param_1[0x1c] = (void*)1;
    iVar1 = *((int*)&DAT_0045b7d8_framecount_ + (int)param_1[0x26]);
    param_1[0x15] = 0;
    param_1[0x14] = (void*)(iVar1 + 0xb);
    param_1[0x27] = 0;
    FUN_0041A340(param_1, 0x90);
    pGVar2 = param_1[2];
    param_1[2] = (void*)0x130;
    FUN_00422470_EatObjects(param_1);
    param_1[2] = pGVar2;
}
}
