extern "C" {
extern unsigned int DAT_004A2660[];
extern unsigned int DAT_004A2678;

unsigned int __cdecl GEX_Target(void)
{
    unsigned int uVar1;
    unsigned int uVar2;
    int iVar3;
    unsigned int *puVar4;

    iVar3 = 0;
    puVar4 = DAT_004A2660;
    while (1) {
        uVar1 = *puVar4;
        uVar2 = uVar1 & 0xff;
        if (uVar2 != 4 && uVar2 != 3)
            break;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
        if (puVar4 >= &DAT_004A2678) {
            int j;
            unsigned int *q;

            j = 0;
            q = DAT_004A2660;
            do {
                uVar1 = *q;
                if ((unsigned char)uVar1 == 3) {
                    DAT_004A2660[j] = 4;
                    return uVar1;
                }
                q = q + 1;
                j = j + 1;
            } while (q < &DAT_004A2678);
            return 4;
        }
    }
    DAT_004A2660[iVar3] = 4;
    return uVar1;
}
}
