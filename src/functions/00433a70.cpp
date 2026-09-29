// Adapted from pc_decomp_backup/src/functions/FUN_00433A70.cpp
// Historical source SHA256: 3f8204f33d28b82f4c2b2308b30291dee0209a5c7b12ade5295d8b5fb9d063f6
extern "C" {
extern "C" void __cdecl FUN_00433900(void**);
extern "C" void __cdecl FUN_00434260(void**);

extern "C" void __cdecl EnemyDoIt_00433a70(void** param_1)
{
    void* pGVar1;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = (void*)0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = (void*)0;
    param_1[0x3b] = (void*)0;
    param_1[0x3c] = (void*)0;
    pGVar1 = (void*)(((int)pGVar1 * 2 ^ (int)pGVar1) & 0x200 ^ (int)pGVar1);
    param_1[0x38] = pGVar1;
    param_1[0x38] = (void*)((int)pGVar1 & 0xfffffeff);
    FUN_00434260(param_1);
    FUN_00433900(param_1);
    if (param_1[0x45] == (void*)-1) {
        param_1[0x44] = (void*)0;
    }
    param_1[0x45] = (void*)-1;
}
}
