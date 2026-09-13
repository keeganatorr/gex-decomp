// Adapted from pc_decomp_backup/src/functions/FUN_00441010.cpp
// Historical source SHA256: f64b3f2d7b1b4904fd3e538e86326af0b5a7b8f2b715a0f0c08d7cafe4c1e10d
extern "C" {
extern "C" { extern int DAT_00460f6c; }
extern int FUN_0046BCF8;
extern "C" void __cdecl GEX_Target(void** gObject) {
    if ((*(short*)((int)gObject + 0x12) >= 0) || (((unsigned int)gObject[4] & 0x40) == 0)) return;
    
    
    
    if (DAT_00460f6c != 0x0046BD00) DAT_00460f6c = 0x0046BD00;
    *(short*)((int)gObject + 0x12) = (short)FUN_0046BCF8;
    void** header = gObject + 5;
    unsigned int uVar2 = *(unsigned char*)((int)(gObject + 4)) & 3;
    if (*(short*)header == 0) return;
    do {
        unsigned short* puVar1 =
            (unsigned short*)(DAT_00460f6c + FUN_0046BCF8 * 8);
        unsigned short xPos =
            *(unsigned short*)(DAT_00460f6c + 4 + FUN_0046BCF8 * 8);
        unsigned short yPos = puVar1[3];
        unsigned char local_c = (unsigned char)yPos;
        *puVar1 = (unsigned short)((*(unsigned int*)(puVar1 + 2) >> 0x14) & 0x10) |
                  (unsigned short)((*(unsigned int*)(puVar1 + 2) >> 6) & 0xf) | (uVar2 << 7);
        *(unsigned char*)((int)puVar1 + 3) = local_c;
        unsigned char bVar3 = (unsigned char)xPos;
        if (uVar2 == 1) bVar3 = (bVar3 & 0x3f) * 2;
        else if (uVar2 == 2) bVar3 = bVar3 & 0x3f;
        else bVar3 = bVar3 << 2;
        header = header + 2;
        *(unsigned char*)(puVar1 + 1) = bVar3;
        FUN_0046BCF8++;
    } while (*(short*)header != 0);
}
}
