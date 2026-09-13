// Adapted from pc_decomp_backup/src/functions/FUN_004249E0.cpp
// Historical source SHA256: a99a982ecc06f726c41400ff8432bdec751c0d32f46a5b71d2afdce1034a1cbf
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004213C0(void**, int);
extern "C" void __cdecl FUN_004213F0(void**);
extern "C" void __cdecl FUN_00421560(void**);
extern "C" void __cdecl FUN_004245B0(void**, int);
extern "C" void __cdecl FUN_00424AE0(void**);
extern "C" void __cdecl FUN_00424E50(void**);
extern "C" void __cdecl FUN_00425EF0(void**);
extern "C" void __cdecl FUN_00427760(void**);
extern "C" void __cdecl FUN_00427B80(void**);
extern "C" { extern int DAT_00456018; }
extern "C" { extern int DAT_0045A6D0; }
extern "C" { extern int DAT_004A021C; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int DAT_004A2990; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar2;
    int iVar3;
    void** ppGVar1;

    if (DAT_004A021C != 0) return;
    if (DAT_00456018 != 0) return;
    if ((unsigned int)param_1[0x20] >> 0x1f) return;
    if (DAT_004A0293 != 0) {
        FUN_00420BC0(param_1);
        return;
    }
    if (DAT_004A0294 != 0) {
        FUN_004213F0(param_1);
        return;
    }
    if (DAT_004A0295 != 0) {
        FUN_00421560(param_1);
        return;
    }
    {
        int v27 = (int)param_1[0x27] - ((unsigned int)param_1[0x20] >> 0x1f);
        param_1[0x27] = (void*)v27;
        if (v27 < 0) {
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
            param_1[0x27] = (void*)(v27 + 0x580);
            if ((int)param_1[0x27] < 0) param_1[0x27] = 0;
        }
    }
    param_1[0x26] = 0;
    FUN_004245B0(param_1, 0x8000);
    
    if ((unsigned int)param_1[0x2b] & 0x2000) return;
    if ((int)param_1[0x2b] >> 0x1f) {
        iVar3 = 0;
        ppGVar1 = param_1;
        while (iVar3 < 32) {
            if ((unsigned int)ppGVar1[0x2b] >> 1) {
                FUN_00424E50(param_1);
                return;
            }
            iVar3++;
            ppGVar1++;
        }
        FUN_00424AE0(param_1);
        return;
    }
    if ((unsigned int)param_1[0x2b] & 0x40) {
        FUN_004213C0(param_1, (int)param_1[0x15]);
        return;
    }
    if ((int)param_1[0x2b] >= 0) {
        if ((int)param_1[0x15] <= 2) {
            FUN_00425EF0(param_1);
        }
        FUN_00427B80(param_1);
        FUN_00427760(param_1);
        return;
    }
}
}
