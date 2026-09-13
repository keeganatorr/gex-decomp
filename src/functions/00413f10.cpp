// Adapted from pc_decomp_backup/src/functions/FUN_00413F10.cpp
// Historical source SHA256: 43d69c87c4b954790b13e8747521cb34a7fe462d40f3f421120ddc2395f24393
extern "C" {
extern "C" { extern int DAT_004A01E0; }
extern "C" { extern int DAT_004A0283; }
extern "C" { extern int DAT_004A2990; }
extern "C" int __cdecl FUN_004219C0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" int __cdecl FUN_00423B00(void**);
extern "C" void __cdecl FUN_00413E60(void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_004244E0(void**, int);
extern "C" void __cdecl FUN_004213F0(void**);
extern "C" void __cdecl FUN_004213C0(int, void**);
extern "C" int __cdecl FUN_00421A00(void**);
extern "C" void __cdecl FUN_004214D0(void**);
extern "C" void __cdecl FUN_0042D2C0(int, void**, int);
extern "C" void __cdecl FUN_00421740(void**);
extern "C" int __cdecl FUN_004215D0(void**);
extern "C" void __cdecl FUN_00424090(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;

    if (-0xe0000 < (int)param_1[0x23]) {
        param_1[0x15] = (void*)0xa;
        FUN_00420960(param_1);
    }
    if (-0x90000 < (int)param_1[0x23]) {
        param_1[0x15] = 0;
        FUN_00420960(param_1);
    }
    if (param_1[0x26] != 0) {
        param_1[0x26] = (void*)((int)param_1[0x26] - 1);
        param_1[0x23] = param_1[0x27];
    }
    iVar1 = FUN_00423B00(param_1);
    if (iVar1 == 0) {
        if (0x20000 < (int)param_1[0x23]) {
            if (*(unsigned char*)&DAT_004A0283 != 0) {
                FUN_00413E60(param_1);
                return;
            }
            FUN_004250B0(param_1);
            return;
        }
        FUN_004244E0(param_1, 0x10000);
        FUN_004213F0(param_1);
        DAT_004A01E0 = 0;
        FUN_004213C0(DAT_004A2990, param_1);
        iVar1 = FUN_00421A00(param_1);
        if (iVar1 == 0) {
            FUN_004214D0(param_1);
            FUN_0042D2C0(DAT_004A2990, param_1, (int)&FUN_004219C0);
            FUN_00421740(param_1);
            iVar1 = FUN_004215D0(param_1);
            if (iVar1 != 0) {
                FUN_00424090(param_1);
            }
        }
    }
}
}
