extern "C" unsigned char BYTE_ARRAY_004a2540[];
extern "C" unsigned char BYTE_ARRAY_004a25d0[];
extern "C" unsigned long DAT_0045ACD0[];
extern "C" unsigned long DAT_0045AD00[];
extern "C" unsigned long DAT_00463b68;
extern "C" unsigned long * __cdecl FUN_00429c10_Object_unk(unsigned long);
extern "C" unsigned long __cdecl FUN_00429c90_RemoteUnk(void);

extern "C" __declspec(naked) void __cdecl FUN_0042a2e5_MapFunkUnk(void)
{
    register unsigned long *GexObject;
    unsigned long *ppGVar2;
    unsigned long pGVar1;
    unsigned long uVar3;
    unsigned long uVar4;

    if (GexObject[0x2c] == 0) {
        BYTE_ARRAY_004a2540[GexObject[0x2a]] =
            (unsigned char)(BYTE_ARRAY_004a2540[GexObject[0x2a]] | 1);
        pGVar1 = GexObject[0x2a];
        if (((long)pGVar1 < 0x31) || (0x36 < (long)pGVar1)) {
            BYTE_ARRAY_004a25d0[pGVar1] = 0;
        } else {
            ppGVar2 = FUN_00429c10_Object_unk(
                ((unsigned long *)GexObject[0x2b])[0x27]);
            ((unsigned long *)GexObject[0x2b])[0x27] = GexObject[0x2a];
            ppGVar2[0x27] =
                (GexObject[0x2a] << 16) | (ppGVar2[0x27] & 0xffffUL);
            uVar3 = GexObject[0x2a] & 0xf;
            uVar3 |= ((volatile unsigned long *)ppGVar2)[0x2c] & 0xffff0000UL;
            ppGVar2[0x2c] = uVar3;
            uVar3 &= 0xf;
            uVar3 <<= 2;
            ppGVar2[0x28] =
                ((*(unsigned long *)((unsigned char *)DAT_0045AD00 + uVar3) +
                  *(unsigned long *)((unsigned char *)DAT_0045ACD0 + uVar3) - 1) << 16) |
                (*(unsigned long *)((unsigned char *)DAT_0045ACD0 + uVar3) & 0xffffUL);
            pGVar1 = DAT_0045ACD0[ppGVar2[0x2c] & 0xf];
            ppGVar2[0x15] = pGVar1;
            ppGVar2[0x29] = pGVar1 << 16;
            ((unsigned long *)GexObject[0x2b])[0x27] = GexObject[0x2a];
        }
        GexObject[0x2b] = 0;
        uVar4 = FUN_00429c90_RemoteUnk();
        GexObject[0x2d] = uVar4;
        GexObject[0x28] = 0;
        GexObject[0x1c] = 0;
        DAT_00463b68 = 0;
    }
}
