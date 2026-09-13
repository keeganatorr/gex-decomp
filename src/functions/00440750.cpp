// Adapted from pc_decomp_backup/src/functions/FUN_00440750.cpp
// Historical source SHA256: 7babb9b53dac170212bad1c86beff8a8684517cb227adc621ff665eb8953f2a2
extern "C" {
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" { extern int DAT_0046bc78; }
extern "C" { extern unsigned short DAT_00460e08[]; }
extern "C" { extern const char DAT_00460eec[]; }
extern "C" { extern const char DAT_00460f24[]; }
extern "C" void __cdecl GEX_Target(void* Tile) {
    short* t = (short*)Tile;
    int tileCount;
    unsigned short* puVar1;
    if (t[9] >= 0 || t[10] == 0) {
        FUN_00405390(DAT_00460eec, DAT_0046bc78, (int)t[9]);
        return;
    }
    FUN_00405390(DAT_00460f24, Tile, DAT_0046bc78);
    tileCount = DAT_0046bc78;
    puVar1 = DAT_00460e08 + tileCount * 2;
    t[9] = (short)DAT_0046bc78;
    DAT_0046bc78++;
    unsigned short uVar2 = (unsigned char)t[8] & 3;
    *puVar1 = (short)(((puVar1[1] & 0x3c0) >> 2 | *(puVar1 + 3) & 0x100) >> 4 | uVar2 << 7);
    *(char*)(puVar1 + 3) = (char)*(puVar1 + 3);
    unsigned char bVar3 = (unsigned char)(puVar1[1]);
    if (uVar2 == 1) { *(unsigned char*)(puVar1 + 1) = (bVar3 & 0x3f) * 2; return; }
    if (uVar2 != 2) { *(unsigned char*)(puVar1 + 1) = bVar3 << 2; return; }
    *(unsigned char*)(puVar1 + 1) = bVar3 & 0x3f;
}
}
