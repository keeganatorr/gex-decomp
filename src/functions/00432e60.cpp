extern "C" int DAT_0045b268[];
extern "C" int GEX_pGlob_004a2ad4;
extern "C" int FUN_00428c80(int);
extern "C" int *FUN_004195d0(int, int, int, int);
extern "C" void FUN_00419be0(int *, int *);

extern "C" void FUN_00432e60(int *param_1)
{
    int iVar5 = 0;
    int *puVar3 = DAT_0045b268;
    int ebp = 0x19;
    int iVar1;
    int *ppGVar2;

    do {
        iVar1 = FUN_00428c80(4);
        param_1[0x27] = iVar1 + 2;
        ppGVar2 = FUN_004195d0(0x5c, param_1[0x1e], param_1[0x1f], GEX_pGlob_004a2ad4);
        if (ppGVar2 != 0) {
            ppGVar2[0x1b] = ppGVar2[0x1b] | 0xc000;
            ppGVar2[0x21] = 0x7fff0000;
            ppGVar2[0x20] = puVar3[0];
            ppGVar2[0x24] = 0x7fff0000;
            ppGVar2[0x23] = puVar3[1];
            ppGVar2[0x25] = 0x6000;
            ppGVar2[0x14] = 0x21;
            ppGVar2[0x15] = iVar5 + 1;
            ppGVar2[0x2f] = param_1[0x2f];
            ppGVar2[0x2e] = ebp;
            ppGVar2[0x1c] = 0x40;
            FUN_00419be0(ppGVar2, param_1);
        }
        ebp = ebp - 2;
        puVar3 = puVar3 + 2;
        iVar5 = iVar5 + 1;
    } while (puVar3 < DAT_0045b268 + 30);
}
