// Adapted from pc_decomp_backup/src/functions/FUN_004237C0.cpp
// Historical source SHA256: c42cfc2479423c2c246eb4d87bc6c2808074fa5893f82d5ba09ab8f819075de8
extern "C" {
extern "C" { extern unsigned char DAT_004A286B[5]; }
extern "C" { extern unsigned char DAT_004A2847[5]; }
extern "C" { extern unsigned char DAT_004A2820[4]; }
extern "C" { extern unsigned char DAT_004A2868[4]; }
extern "C" int __cdecl GEX_Target() {
    int s = 0;
    for (int i = 0; i < 4; i++)
        s += DAT_004A2868[i] + DAT_004A2820[i] + DAT_004A2847[i + 1] + DAT_004A286B[i + 1];
    return s;
}
}
