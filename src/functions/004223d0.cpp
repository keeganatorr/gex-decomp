// Adapted from pc_decomp_backup/src/functions/FUN_004223D0.cpp
// Historical source SHA256: 387dc8461d898c1c901113dbddf041533366082f1f09800a3b6a6275de0d1d02
extern "C" {
extern "C" { extern int DAT_0045A6E0; }
extern "C" { extern int DAT_004594A8; }
extern "C" { extern int DAT_004594A4; }
extern "C" { extern int DAT_004594A0; }

extern "C" void __cdecl GEX_Target()
{
    int h = DAT_0045A6E0;
    if (h >= 0) {
        DAT_004594A8 = DAT_004594A4;
        DAT_004594A4 = DAT_004594A0;
        DAT_0045A6E0 = -1;
        DAT_004594A0 = h;
    }
}
}
