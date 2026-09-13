// Adapted from pc_decomp_backup/src/functions/FUN_0040F700.cpp
// Historical source SHA256: 0fe4dffe5919701c6ef17e169d8b6750d0f48f0161fc662b15f614e66185280e
extern "C" {
extern "C" { extern unsigned int DAT_00457c88[]; }
extern "C" void __cdecl GEX_Target(unsigned int keyInput, int param2, unsigned char* keyBytes) {
    if (DAT_00457c88[0] == -1) return;
    int i = 0;
    do {
        unsigned int mask = DAT_00457c88[i];
        unsigned char* pb = (unsigned char*)(param2 + i);
        keyBytes[*pb] = (mask & keyInput) != 0;
        i++;
    } while (DAT_00457c88[i] != 0xffffffff);
}
}
