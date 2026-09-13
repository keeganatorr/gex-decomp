// Adapted from pc_decomp_backup/src/functions/FUN_00421F20.cpp
// Historical source SHA256: f784f16cf0092f67530cbb8c2c303095b5d34777ff9a581c9a088d5985b273af
extern "C" {
extern "C" { extern unsigned int DAT_0045a790[]; }
extern "C" int __cdecl GEX_Target(void** param1) {
    unsigned int idx = (((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c) << 2;
    unsigned int uVar1 = DAT_0045a790[idx | ((unsigned int)param1[0x31] & 0xffe7ffff) >> 0x13];
    if (uVar1 & 0x1000) param1[0x39] = param1[0x1e];
    if (uVar1 & 0x100) param1[0x3a] = param1[0x1e];
    if (uVar1 & 0x10) param1[0x3b] = param1[0x1f];
    if (uVar1 & 1) param1[0x3c] = param1[0x1f];
    return 1;
}
}
