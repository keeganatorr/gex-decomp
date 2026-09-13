// Adapted from pc_decomp_backup/src/functions/FUN_0041A590.cpp
// Historical source SHA256: a3e9ccc68c0c4c42d44c3beee017523f96e79dd28e4e461b1e5d14c02d7ab80e
extern "C" {
extern "C" { extern unsigned char BYTE_ARRAY_004a25d0[]; }
extern "C" { extern unsigned char BYTE_ARRAY_004a2540[]; }
extern "C" { extern int FUN_004A2660[]; }

extern "C" int __cdecl GEX_Target(unsigned int RemoteLevelID)
{
    if (BYTE_ARRAY_004a25d0[RemoteLevelID] != 0 || (BYTE_ARRAY_004a2540[RemoteLevelID] & 1) != 0) {
        return 1;
    }
    for (int* p = FUN_004A2660; p <= &FUN_004A2660[0x17 / 4]; p++) {
        unsigned int v = *p & 0xff;
        if ((v == 0 || v == 1 || v == 2) && ((*p & 0xffff00) >> 8) == RemoteLevelID) {
            return 2;
        }
    }
    return 0;
}
}
