// Adapted from pc_decomp_backup/src/functions/FUN_004329F0.cpp
// Historical source SHA256: 5f05f6291dbe51f6b6beffcb7860a74ded9b052c285afc0f56c84b403ce2a445
extern "C" {
extern "C" int __cdecl FUN_0041E9D0(void**, int);
extern "C" void __cdecl FUN_0041A340(void**, int);
extern "C" void __cdecl FUN_0041BE80(void**, int, int);
extern "C" void __cdecl FUN_00432930(void**);
extern "C" void __cdecl FUN_00419520(void**);

extern "C" void __cdecl GEX_Target(void** param_1, int* param_2)
{
    int iVar2;
    int *pObj5d, *pObj5e;

    if (*param_2 == 0) return;
    iVar2 = FUN_0041E9D0(param_1, (int)param_2);
    if (iVar2 != 0) return;
    pObj5d = (int*)param_1[0x5d];
    if ((pObj5d[0] & 0xffff) == 2 || (pObj5d[0] & 0xffff) == 0) {
        pObj5e = (int*)param_1[0x5e];
        if ((pObj5e[0x1b] & 0x400000) != 0) {
            FUN_0041A340((void**)pObj5e, 0x80);
            FUN_0041BE80((void**)pObj5e, 0, 0);
            FUN_00432930((void**)pObj5e);
        }
    }
    FUN_00419520(param_1);
}
}
