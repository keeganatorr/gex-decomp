// Adapted from pc_decomp_backup/src/functions/FUN_0043A870.cpp
// Historical source SHA256: 1ed4ef42c9da648fb9badea51319e2a94bc728f99525435a5a992c1a37305d09
extern "C" {
extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419B80(void**, int);
extern "C" void __cdecl FUN_00444590();

extern "C" void __cdecl ob371Init_0043a870(void** param_1)
{
    void* pGVar1;

    pGVar1 = FUN_004195D0(0, (int)param_1[0x1e], (int)param_1[0x1f], (int)param_1[3]);
    if (pGVar1 != (void*)0) {
        param_1[0x26] = pGVar1;
        *(int*)((int)pGVar1 + 0x54) = 1;
        *(int*)((int)pGVar1 + 0x5c) = 0;
        *(int*)((int)pGVar1 + 0x60) = (int)&FUN_00444590;
        FUN_00419B80((void**)pGVar1, 2);
    }
    pGVar1 = FUN_004195D0(0, (int)param_1[0x1e], (int)param_1[0x1f], (int)param_1[3]);
    if (pGVar1 != (void*)0) {
        param_1[0x27] = pGVar1;
        *(int*)((int)pGVar1 + 0x54) = 2;
        *(int*)((int)pGVar1 + 0x5c) = 0;
        *(int*)((int)pGVar1 + 0x60) = (int)&FUN_00444590;
        FUN_00419B80((void**)pGVar1, 6);
    }
    FUN_00419B80(param_1, 3);
    param_1[0x2d] = (void*)0x10080;
}
}
