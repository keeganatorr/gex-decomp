extern "C" int DAT_004a2824;
extern "C" int DAT_004a2844;
extern "C" int DAT_004a285c;

extern "C" void GEX_Target(int *param_1)
{
    if (DAT_004a2824 == 0) return;
    int iVar1 = param_1[0x1e];
    int iVar2 = DAT_004a2844 - iVar1;
    if (iVar2 >= 0x300000) iVar2 = 0x300000;
    if (iVar2 <= -0x300000) iVar2 = -0x300000;
    iVar2 >>= 16;
    if (iVar2 == 0) return;
    if (DAT_004a285c != 0) {
        if (*(int *)(0x457210 + param_1[0x1c] * 4) & 0x20) {
            param_1[0x20] += 0x50000 / iVar2;
        } else {
            param_1[0x1e] = iVar1 + 0x50000 / iVar2;
        }
    } else {
        if (*(int *)(0x457210 + param_1[0x1c] * 4) & 0x20) {
            param_1[0x20] += -0x20000 / iVar2;
        } else {
            param_1[0x1e] = iVar1 + -0x50000 / iVar2;
        }
    }
}
