// Adapted from pc_decomp_backup/src/functions/FUN_0043EC20.cpp
// Historical source SHA256: 7cda0b5239b110765b6f4333ccb19ef1cda637ffa2c6ded3cee574ce3878cc76
extern "C" {
struct DrawCache { short f0,f2,f4,f6; };
extern "C" void __cdecl FUN_0043EB50(void*, int);
extern "C" { extern unsigned int DAT_00460040; }
extern unsigned short DAT_00460042;
extern unsigned short DAT_004600C8;
extern "C" void __cdecl GEX_Target(DrawCache* tile) {
    unsigned short sVar1, uVar2;
    if ((DAT_00460042 < 0x101) &&
        (0x100 < (int)tile->f6 + (int)DAT_00460042)) {
        DAT_00460040 = (0x100 << 16) | (DAT_00460040 & 0xffff);
    }
    if (0x1e0 < (int)tile->f6 + (int)DAT_00460042) {
        unsigned int combined = (unsigned short)DAT_00460040 + DAT_004600C8;
        DAT_00460040 = combined;
        DAT_004600C8 = 0;
    }
    if ((int)(short)DAT_00460040 <
        (int)(((int)tile->f4 + (int)(short)DAT_00460040 - 1U) & 0xffffffc0)) {
        DAT_00460040 = ((unsigned short)DAT_00460040 + tile->f4 - 1) & 0xffc0;
        DAT_004600C8 = 0;
    }
    if (DAT_004600C8 < tile->f4)
        DAT_004600C8 = tile->f4;
    sVar1 = tile->f6;
    uVar2 = DAT_00460042;
    tile->f0 = (short)DAT_00460040;
    tile->f2 = uVar2;
    DAT_00460042 = DAT_00460042 + sVar1;
    FUN_0043EB50(tile, 0);
}
}
