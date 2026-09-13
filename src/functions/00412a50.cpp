// Adapted from pc_decomp_backup/src/functions/FUN_00412A50.cpp
// Historical source SHA256: 0030d783d52d51fda486325a32cfaa3921c11079d88c4d4c4b3296410bc40be5
extern "C" {
extern "C" { extern int DAT_00458C78; }
extern "C" { extern int DAT_004A022C; }
extern "C" { extern int DAT_004A284C; }
extern "C" { extern char DAT_004A0283; }
extern "C" { extern char DAT_004A0284; }
extern "C" { extern char DAT_004A0285; }
extern "C" void __cdecl FUN_00423800(void**);
extern "C" void __cdecl FUN_004144E0(void**);
extern "C" void __cdecl FUN_00413BA0(void**);
extern "C" void __cdecl FUN_00421900(void**);
extern "C" void __cdecl FUN_00412D00(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar2;

    FUN_00423800(param_1);
    if (DAT_00458C78 != 0 || DAT_004A0284 != 0) {
        FUN_004144E0(param_1);
        return;
    }
    if (DAT_004A0285 != 0 && DAT_004A0283 == 0) {
        FUN_00413BA0(param_1);
        return;
    }
    DAT_004A284C = 1;
    pGVar2 = (int)param_1[0x26];
    param_1[0x26] = (void*)(pGVar2 + 0x40);
    if ((int)param_1[0x26] > 0xffff) {
        param_1[0x26] = (void*)(pGVar2 - 0x40);
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] < 3) {
            FUN_00421900(param_1);
        } else {
            FUN_00412D00(param_1);
        }
    }
    DAT_004A022C = 1;
}
}
