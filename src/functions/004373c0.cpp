// Adapted from pc_decomp_backup/src/functions/FUN_004373C0.cpp
// Historical source SHA256: 477520309283577a2c3d4c2204aed33eab0c3b5cfa3249a6a35d4c8b2bc3d74f
extern "C" {
extern "C" { extern int DAT_0045C998; }

extern "C" int __cdecl GEX_Target(int param_1)
{
    if (DAT_0045C998 == 1) {
        return ((200 - param_1) * param_1 * 4) / 1000;
    }
    if (DAT_0045C998 == 3) {
        return ((0xb4 - param_1) * param_1) / 0x2d + ((param_1 + -0x96) * param_1 * 4) / 0x10e;
    }
    if (DAT_0045C998 == 2) {
        return ((param_1 + -0xb4) * param_1) / 0x46 + ((0x8c - param_1) * param_1) / 0x78;
    }
    if (DAT_0045C998 == 4) {
        return ((100 - param_1) * param_1 * 6) / 0xfa + ((0x32 - param_1) * param_1 * 2) / 500;
    }
    return 0;
}
}
