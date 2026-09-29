// Adapted from pc_decomp_backup/src/functions/FUN_00413230.cpp
// Historical source SHA256: e4388ef9a5a96147a7f5b3a77f107ed0d7bd58deb916200fd73db146cc8994c4
extern "C" {
extern "C" { extern int DAT_00458C78; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int DAT_004A0293; }
extern "C" { extern int DAT_004A284C; }
extern "C" { extern int DAT_004A0218; }
extern "C" int __cdecl FUN_00421F20(void*);
extern "C" int __cdecl FUN_00421F90(void*);
extern "C" void __cdecl FUN_00421CD0(void*);
extern "C" void __cdecl FUN_004138B0(void*);
extern "C" void __cdecl FUN_00412960(void*);
extern "C" void __cdecl FUN_00413470(void*);
extern "C" void __cdecl FUN_00421900(void*);

extern "C" void __cdecl PlayerSideSpinAround_00413230(void* param_1)
{
    int iVar1;

    if (DAT_00458C78 != 0) {
        FUN_004138B0(param_1);
        return;
    }
    if (DAT_004A0294 != 0 || (iVar1 = FUN_00421F90(param_1), iVar1 == 0)) {
        FUN_004138B0(param_1);
        return;
    }
    if (DAT_004A0295 != 0 && DAT_004A0293 == 0) {
        FUN_00412960(param_1);
        return;
    }
    DAT_004A284C = 1;
    iVar1 = FUN_00421F20(param_1);
    if (iVar1 == 0) return;
    FUN_00421CD0(param_1);
    if (DAT_004A0293 == 0) {
        *(int*)((char*)param_1 + 0xa4) = 1;
    }
    {
        int v26 = *(int*)((char*)param_1 + 0x98);
        int new_v26 = v26 + 0x80;
        *(int*)((char*)param_1 + 0x98) = new_v26;
        if (new_v26 >= 0x10000) {
            *(int*)((char*)param_1 + 0x98) = v26;
            int v15 = *(int*)((char*)param_1 + 0x54) + 1;
            *(int*)((char*)param_1 + 0x54) = v15;
            if (v15 > 8) {
                if (DAT_004A0293 == 0 || *(int*)((char*)param_1 + 0xa4) == 0) {
                    FUN_00413470(param_1);
                    return;
                }
                *(int*)((char*)param_1 + 0x54) = 3;
                *(int*)((char*)param_1 + 0xa4) = 0;
                DAT_004A0218 = 0x67;
            }
            FUN_00421900(param_1);
        }
    }
}
}
