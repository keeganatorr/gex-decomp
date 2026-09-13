// Adapted from pc_decomp_backup/src/functions/FUN_00414E80.cpp
// Historical source SHA256: d97a1c34894fbde8d11fc242de55361ce4d7ecc5dfdf4b55f48e5d20ee107e07
extern "C" {
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004A284C; }
extern "C" int __cdecl FUN_00421820(void*);
extern "C" int __cdecl FUN_00421560(int, void*);
extern "C" void __cdecl FUN_004250B0(void*);
extern "C" void __cdecl FUN_00414A30(void*);
extern "C" void __cdecl FUN_00424B80(void*);
extern "C" void __cdecl FUN_00421900(void*);
extern "C" void __cdecl FUN_00427850(void*);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(int, void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int iVar1;

    iVar1 = FUN_00421820(param_1);
    if (FUN_00421560(FUN_004A2990, param_1) == 0) {
        FUN_004250B0(param_1);
        return;
    }
    if (DAT_004A0280 != 0 && DAT_004A0283 == 0) {
        FUN_00414A30(param_1);
        return;
    }
    if (iVar1 == 0 && (DAT_004A0280 != 0 && DAT_004A0283 == 0)) {
        FUN_00424B80(param_1);
        return;
    }
    DAT_004A284C = 1;
    FUN_00421900(param_1);
    {
        int v = *(int*)((char*)param_1 + 0x98) + 0x8000;
        *(int*)((char*)param_1 + 0x98) = v;
        if (v < 0) {
            *(int*)((char*)param_1 + 0x98) = v - 0x10000;
            (*(int*)((char*)param_1 + 0x54))++;
            if (*(int*)((char*)param_1 + 0x54) > 5) {
                FUN_00427850(param_1);
                return;
            }
        }
    }
    FUN_004213F0(param_1);
    FUN_004213C0(FUN_004A2990, param_1);
}
}
