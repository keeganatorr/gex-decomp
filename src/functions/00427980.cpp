// Adapted from pc_decomp_backup/src/functions/FUN_00427980.cpp
// Historical source SHA256: f0d4517285c7184f79ab7a14555f82215917632bc1904941740272ae2ce964b5
extern "C" {
extern "C" { extern unsigned char DAT_004a0293; }
extern "C" { extern unsigned char DAT_004a0294; }
extern "C" void __cdecl FUN_00424B80(void**);
extern "C" void __cdecl FUN_00424090(void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_00427850(void**);
extern "C" void __cdecl FUN_004213f0(void*);
extern "C" void __cdecl FUN_004213c0(int, void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" { extern int FUN_004A2990; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (DAT_004a0294 != 0) {
        FUN_00424B80(param_1);
        return;
    }
    if (DAT_004a0293 == 0) {
        FUN_00424090(param_1);
        return;
    }
    if (FUN_00421560_DrawCharacter(FUN_004A2990, param_1) == 0) {
        FUN_004250B0(param_1);
        return;
    }
    int* p26 = (int*)&param_1[0x26];
    (*p26)++;
    if (*p26 > 3) {
        FUN_00427850(param_1);
        return;
    }
    FUN_004213f0(param_1);
    FUN_004213c0(FUN_004A2990, param_1);
}
}
