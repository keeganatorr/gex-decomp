// Adapted from pc_decomp_backup/src/functions/FUN_00411160.cpp
// Historical source SHA256: 877070631501f26e24f010e112fd93a05b5e7d855db29050ac0b7dd16c1abeee
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00411A40(void**);
extern "C" void __cdecl FUN_00427D30(void**);
extern "C" { extern void** DAT_004a2864; }
extern "C" { extern int DAT_004a23c8; }
extern "C" { extern int DAT_004a0218; }
extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    if (DAT_004a2864 != 0) { FUN_00411A40(param1); return; }
    param1[0x1c] = (void*)0x3d;
    param1[0x14] = (void*)0x49;
    param1[0x15] = (void*)4;
    param1[0x23] = 0; param1[0x20] = 0; param1[0x26] = 0;
    DAT_004a23c8 = 0;
    int dir = ((int)param1[0x1b] & 0x80000000) >> 0x1c | (int)param1[0x31] >> 0x15;
    if (dir == 0 || dir == 0xc) param1[0x1e] = (void*)((int)param1[0x1e] | 0x1f0000);
    else if (dir == 4 || dir == 8) param1[0x1e] = (void*)((int)param1[0x1e] & 0xffe00000);
    DAT_004a0218 = 0x6b;
    FUN_00427D30(param1);
}
}
