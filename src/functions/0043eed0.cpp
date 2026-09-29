extern unsigned short USHORT_ARRAY_00460274[];
extern int DAT_0046070c;
extern unsigned char DAT_00460674_GraphicsUnk2;
extern int DAT_004a2b04;
extern unsigned int PTR_UINT_00460700[];
extern unsigned int DAT_0046a534_StaticGraphics;

extern "C" void FUN_0043eed0_TvStatic(void)
{
    unsigned short *puVar1 = USHORT_ARRAY_00460274;
    int iVar2 = 0x200;
    do {
        *puVar1++ = (unsigned short)DAT_0046070c;
        DAT_0046070c = (DAT_0046070c * 0x7d) % 0x2aaaab;
        iVar2--;
    } while (iVar2 != 0);
    DAT_00460674_GraphicsUnk2 = 1;
    USHORT_ARRAY_00460274[-5] = 0xffff;
    DAT_0046a534_StaticGraphics = PTR_UINT_00460700[DAT_004a2b04] + 4;
}
