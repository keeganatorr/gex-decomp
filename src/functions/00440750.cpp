extern "C" {
int __cdecl FUN_00405390(const char *, ...);
extern volatile int DAT_0046bc78;
extern unsigned int *DAT_00460e08;
extern const char DAT_00460eec[];
extern const char DAT_00460f24[];

void __cdecl GEX_Target(void *Tile)
{
    unsigned char *tile = (unsigned char *)Tile;
    int tileCount;
    unsigned int *puVar1;
    unsigned int uVar2;
    unsigned short w4;
    unsigned short w6;
    unsigned char bVar3;

    if (*(short *)(tile + 0x12) >= 0 || *(short *)(tile + 0x14) == 0) {
        FUN_00405390(DAT_00460eec, DAT_0046bc78, (int)*(short *)(tile + 0x12));
        return;
    }
    FUN_00405390(DAT_00460f24, Tile, DAT_0046bc78);
    tileCount = DAT_0046bc78;
    puVar1 = DAT_00460e08;
    *(short *)(tile + 0x12) = (short)DAT_0046bc78;
    puVar1 = puVar1 + tileCount * 2;
    DAT_0046bc78++;
    uVar2 = (unsigned int)tile[0x10] & 3;
    w4 = *(unsigned short *)((unsigned char *)puVar1 + 4);
    w6 = *(unsigned short *)((unsigned char *)puVar1 + 6);
    *(unsigned short *)puVar1 =
        (unsigned short)((short)((w4 & 0x3c0) >> 2 | (w6 & 0x100)) >> 4) |
        (unsigned short)((uVar2 & 3) << 7);
    *((unsigned char *)puVar1 + 3) = (unsigned char)w6;
    bVar3 = (unsigned char)w4;
    if (uVar2 == 1) {
        *((unsigned char *)puVar1 + 2) = (unsigned char)((bVar3 & 0x3f) * 2);
        return;
    }
    if (uVar2 != 2) {
        *((unsigned char *)puVar1 + 2) = (unsigned char)(bVar3 << 2);
        return;
    }
    *((unsigned char *)puVar1 + 2) = (unsigned char)(bVar3 & 0x3f);
}
}
