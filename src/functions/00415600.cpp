// Adapted from pc_decomp_backup/src/functions/FUN_00415600.cpp
// Historical source SHA256: 1028c3ece37dce7233ab04d2ece06fddbb59c7d634626b6632794dc7548045f1
extern "C" {
extern "C" { extern int DAT_004A2828; }
extern "C" { extern int FUN_004A2870; }
extern "C" { extern void* FUN_004A2990; }
extern "C" int __cdecl FUN_00421560_DrawCharacter(void*, void**);
extern "C" void __cdecl FUN_00424BD0(void**);

extern "C" void __cdecl PlayerLaunch_00415600(void** p)
{
    if (FUN_004A2870 != 0) {
        if (FUN_00421560_DrawCharacter(FUN_004A2990, p) != 0) return;
    }
    DAT_004A2828 = 0;
    p[0x1c] = (void*)0xc;
    p[0x15] = (void*)2;
    FUN_00424BD0(p);
}
}
