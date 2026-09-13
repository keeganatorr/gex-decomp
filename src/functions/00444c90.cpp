// Adapted from pc_decomp_backup/src/functions/FUN_00444C90.cpp
// Historical source SHA256: f21f26f04a3c1778b0886c9c6e282a17ee62f3342a5bb98e4a4cc7224989d58e
extern "C" {
extern "C" { extern void** FUN_004A33AC; }
extern "C" { extern int DAT_004a2f74_TilesPixelBlue; }
extern "C" { extern int DAT_004a2f7c_TilesPixelGreen; }
extern "C" { extern int DAT_004a2f80_TilesPixelRed; }
extern "C" { extern int DAT_004a2f70_TilesUnk1; }

extern "C" int __cdecl GEX_Target()
{
    void** ppv = FUN_004A33AC;
    for (int i = 0x40000; i != 0; i--) *ppv++ = 0;
    DAT_004a2f74_TilesPixelBlue = -1;
    DAT_004a2f7c_TilesPixelGreen = -1;
    DAT_004a2f80_TilesPixelRed = -1;
    DAT_004a2f70_TilesUnk1 = -1;
    int* pu = (int*)0x004a2fa0;
    for (int j = 0x100; j != 0; j--) *pu++ = 0;
    for (unsigned int u = 0; u < 0x400; u++) {
        int val = ((int)(u & 0x1f) * ((int)u >> 5));
        int shift = val + (val >> 31 & 0xf);
        val = shift >> 4;
        if (val > 0x1f) val = 0x1f;
        if (val < 0) val = 0;
        ((unsigned char*)0x004a2b50)[u] = (unsigned char)val;
    }
    return 1;
}
}
