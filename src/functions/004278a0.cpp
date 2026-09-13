// Adapted from pc_decomp_backup/src/functions/FUN_004278A0.cpp
// Historical source SHA256: 87272621bea8dc83412510b51afd5f9729c5258cb03dd7a464488a258994c2f9
extern "C" {
extern "C" { extern char DAT_004A0280; }
extern "C" { extern char DAT_004A0281; }
extern "C" { extern char DAT_004A0282; }
extern void* DAT_004A2990;
extern "C" int __cdecl FUN_00421560(void*, void**);
extern "C" void __cdecl FUN_00424B80(void**);
extern "C" void __cdecl FUN_00427850(void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_00424090(void**);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(void*, void*);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;

    if (DAT_004A0282 != 0) {
        FUN_00424B80(param_1);
        return;
    }
    if (DAT_004A0281 != 0 && DAT_004A0280 == 0 && DAT_004A0282 == 0) {
        FUN_00427850(param_1);
        return;
    }
    iVar1 = FUN_00421560(DAT_004A2990, param_1);
    if (iVar1 == 0) {
        FUN_004250B0(param_1);
        return;
    }
    param_1[0x26] = (void*)((int)param_1[0x26] + 1);
    if ((int)param_1[0x26] > 3) {
        FUN_00424090(param_1);
        return;
    }
    FUN_004213F0((void*)param_1);
    FUN_004213C0(DAT_004A2990, (void*)param_1);
}
}
