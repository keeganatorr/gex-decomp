// Adapted from pc_decomp_backup/src/functions/FUN_00412A00.cpp
// Historical source SHA256: 5314bbde1097d0e9f1363520128589a72efc74458def0d80ab05dd89a9252474
extern "C" {
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern int DAT_00400000; }
extern "C" int __cdecl GEX_Target(int param_1)
{
    if (DAT_004A0282 != 0) return 0;
    if (DAT_004A0283 != 0) return 0x800000;
    if (DAT_004A0280 != 0) return 0xc00000;
    if (DAT_004A0281 != 0) return (int)&DAT_00400000;
    return *(int*)(param_1 + 0xc4);
}
}
