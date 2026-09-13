// Adapted from pc_decomp_backup/src/functions/FUN_00444530.cpp
// Historical source SHA256: 10aae0fb9a0d1d766715735aa067ed6c1b0fab2d9b5e89e5c545edf49fe74141
extern "C" {
extern "C" void* __cdecl FUN_0041A500(void**);
extern "C" void __cdecl FUN_00444410(int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pSVar3;
    void* pDVar4;
    void* pDVar1;

    if ((int)param_1[0x15] < 0) {
        return;
    }
    pSVar3 = FUN_0041A500(param_1);
    if (pSVar3 == (void*)0x0) {
        return;
    }
    if (param_1[0x30] != (void*)0x0) {
        FUN_00444410((int)param_1[0x30]);
        return;
    }
    pDVar4 = *(void**)((int)pSVar3 + 0x18);
    if (pDVar4 == (void*)0x0) {
        return;
    }
    pDVar1 = *(void**)pDVar4;
    while (pDVar1 != (void*)0x0) {
        void* temp = *(void**)((int)pDVar4 + 0x04);
        if (0 < *(int*)(*(int*)pDVar1 + 0x08)) {
            FUN_00444410(*(int*)(*(int*)pDVar1 + 0x0c));
        }
        pDVar4 = temp;
        pDVar1 = *(void**)pDVar4;
    }
}
}
