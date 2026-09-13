// Adapted from pc_decomp_backup/src/functions/FUN_00435CC0.cpp
// Historical source SHA256: 595d4e3fdf54fe3ea8c647229101720bced6ba29cef91b2083f0f8d1525670f8
extern "C" {
extern "C" void __cdecl FUN_0041A340(void**, int);
extern "C" void __cdecl FUN_0041FA80(int);
extern "C" { extern int DAT_004593c0; }
extern "C" { extern int DAT_004a2808; }
extern "C" { extern int DAT_004642b0; }
extern "C" { extern int DAT_004642ac; }
extern "C" void __cdecl GEX_Target(void** param1, int* param2) {
    if (*param2 != 0 && param1[0x27] == 0) {
        FUN_0041A340(param1, 0xe3);
        DAT_004593c0++; DAT_004a2808++; DAT_004642b0++; DAT_004642ac = 0x14;
        param1[0x27] = (void*)1;
        param1[0x14] = 0; param1[0x15] = 0;
        param1[0x1b] = (void*)((unsigned int)param1[0x1b] | 0x80000);
        if (DAT_004642b0 > 0x13) FUN_0041FA80(0x54);
        if (DAT_004642b0 > 9) { FUN_0041FA80(0x41); return; }
        FUN_0041FA80(0x50); FUN_0041FA80(0x12);
    }
}
}
