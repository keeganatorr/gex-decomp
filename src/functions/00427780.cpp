// Adapted from pc_decomp_backup/src/functions/FUN_00427780.cpp
// Historical source SHA256: 0ec5bf1e9cdf4b51f12f79885f96d42a4c16e3309c174c2f2969f0c455176dfe
extern "C" {
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_00421820(void*);
extern "C" void __cdecl FUN_00424B80(void*);
extern "C" void __cdecl FUN_00414C90(void*);
extern "C" void __cdecl FUN_004250B0(void*);
extern "C" void __cdecl FUN_00414A30(void*);
extern "C" void __cdecl FUN_00427940(void*);
extern "C" int __cdecl FUN_00421560(int, void*);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(int, void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int iVar1;
    int iVar2;

    iVar1 = FUN_00421820(param_1);
    if (iVar1 == 0 && DAT_004A0281 != 0) {
        FUN_00424B80(param_1);
        return;
    }
    if (DAT_004A0283 != 0) {
        FUN_00414C90(param_1);
        return;
    }
    if (DAT_004A0280 == 0) {
        iVar2 = FUN_00421560(FUN_004A2990, param_1);
        if (iVar2 == 0) {
            FUN_004250B0(param_1);
            return;
        }
        if (DAT_004A0280 != 0) {
            *(int*)((char*)param_1 + 0x6c) &= 0x7fffffff;
        }
        if (DAT_004A0280 != 0) {
            *(int*)((char*)param_1 + 0x6c) |= 0x80000000;
        }
        if (DAT_004A0280 == 0 && iVar1 == 0) {
            FUN_00427940(param_1);
        }
        FUN_004213F0(param_1);
        FUN_004213C0(FUN_004A2990, param_1);
        return;
    }
    FUN_00414A30(param_1);
}
}
