// Adapted from pc_decomp_backup/src/functions/FUN_004239B0.cpp
// Historical source SHA256: 488e702267e62d35559b52c92aa8de5df73f5cff7bada55f029d009228815147
extern "C" {
extern "C" void __cdecl FUN_00423780(void**);
extern "C" { extern unsigned char DAT_004a286c[]; }

extern "C" int __cdecl GEX_Target(void** param_1)
{
    FUN_00423780(param_1);
    int count = 4;
    if ((((unsigned int)param_1[0x31] + 0x1000) & 0x400000) != 0) {
        count = 3;
    }
    for (int i = 0; i < count; i++) {
        if (DAT_004a286c[i] == 0) return 0;
    }
    return 1;
}
}
