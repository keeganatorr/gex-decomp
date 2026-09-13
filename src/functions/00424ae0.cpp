// Adapted from pc_decomp_backup/src/functions/FUN_00424AE0.cpp
// Historical source SHA256: 3deb9fcdb29e4c7154eaaf25c0d7b3809a2aa77f5af623c0e578cb99d3c8e57b
extern "C" {
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(void*, void*);
extern "C" int __cdecl FUN_00421560(void*, void*);
extern "C" void __cdecl FUN_00424E50(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar2;
    int iVar1;

    if (param_1[0x26] == (void*)0x0) {
        param_1[0x26] = (void*)0x0;
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] == 2) {
            FUN_00424E50(param_1);
            return;
        }
    } else {
        param_1[0x26] = (void*)((int)param_1[0x26] - 1);
    }
    pGVar2 = param_1[0x20];
    param_1[0x20] = (void*)((unsigned int)((int)pGVar2 > 0) - (unsigned int)((int)pGVar2 < 0));
    FUN_004213F0((void*)param_1);
    FUN_004213C0(DAT_004A2990, (void*)param_1);
    param_1[0x20] = pGVar2;
    iVar1 = FUN_00421560(DAT_004A2990, (void*)param_1);
    if (iVar1 == 0) {
        FUN_00424E50(param_1);
    }
}
}
