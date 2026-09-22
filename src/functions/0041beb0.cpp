extern "C" {
unsigned int FUN_00428C60(void);
int FUN_00428C80(int);
extern int DAT_0046363C;
extern int DAT_00463640;
extern int DAT_0046366C;
extern int DAT_0046367C;

void GEX_Target(void)
{
    unsigned int uVar1;
    int iVar2;

    uVar1 = FUN_00428C60();
    switch (uVar1 & 3) {
    case 0:
        DAT_0046363C = 0;
        iVar2 = FUN_00428C80(0xf0);
        DAT_00463640 = iVar2 << 16;
        iVar2 = FUN_00428C80(0x60);
        DAT_0046367C = (iVar2 + 0x10) * 0x10000;
        break;
    case 1:
        DAT_0046363C = 0x13f0000;
        iVar2 = FUN_00428C80(0xf0);
        DAT_00463640 = iVar2 << 16;
        iVar2 = FUN_00428C80(0x60);
        DAT_0046367C = (iVar2 + 0x90) * 0x10000;
        break;
    case 2:
        iVar2 = FUN_00428C80(0x140);
        DAT_0046363C = iVar2 << 16;
        DAT_00463640 = 0;
        iVar2 = FUN_00428C80(0x60);
        DAT_0046367C = (iVar2 - 0x30) * 0x10000;
        break;
    case 3:
        iVar2 = FUN_00428C80(0x140);
        DAT_0046363C = iVar2 << 16;
        DAT_00463640 = 0xef0000;
        iVar2 = FUN_00428C80(0x60);
        DAT_0046367C = (iVar2 + 0x50) * 0x10000;
        break;
    }

    DAT_0046366C = 0;
    DAT_0046367C &= 0xff0000;
}

void GEX_AfterTarget(void)
{
}
}
