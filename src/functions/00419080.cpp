// Adapted from pc_decomp_backup/src/functions/FUN_00419080.cpp
// Historical source SHA256: 93f984851c5eacd5986a0a1b219065c2e336c8be31d0a95dccf778e925d1c3fb
extern "C" {
extern "C" { extern int DAT_004A02C8; }

extern "C" unsigned char* __cdecl SCRIPT_ClearController_00419080(unsigned char* param_1)
{
    unsigned int uVar2;
    unsigned int offset;
    unsigned char* base;

    uVar2 = *param_1;
    offset = uVar2 * 0x24;
    base = (unsigned char*)0x4a0280;
    base[offset + 0] = 0;
    base[offset + 1] = 0;
    base[offset + 2] = 0;
    base[offset + 3] = 0;
    base[offset + 4] = 0;
    base[offset + 5] = 0;
    base[offset + 6] = 0;
    base[offset + 7] = 0;
    base[offset + 8] = 0;
    base[offset + 9] = 0;
    base[offset + 10] = 0;
    base[offset + 11] = 0;
    base[offset + 15] = 0;
    base[offset + 16] = 0;
    base[offset + 17] = 0;
    base[offset + 18] = 0;
    base[offset + 19] = 0;
    base[offset + 20] = 0;
    DAT_004A02C8 = 0;
    base[offset + 21] = 0;
    base[offset + 22] = 0;
    base[offset + 23] = 0;
    base[offset + 24] = 0;
    base[offset + 25] = 0;
    base[offset + 26] = 0;
    return param_1 + 1;
}
}
