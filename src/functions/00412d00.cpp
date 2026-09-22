extern "C" {

extern int DAT_00462E80;
extern int DAT_00458798;
extern int DAT_0045879C;
extern int DAT_004587A0;
extern int DAT_004587A4;
extern int DAT_004A0218;

extern void __cdecl FUN_00420BC0(int *p);
extern int __cdecl FUN_00423A50(int *p);
extern void __cdecl FUN_00412B50(int *p);

void __cdecl GEX_Target(int *param_1)
{
    int pGVar1;
    int pGVar2;
    int iVar6;
    int iVar4;
    int iVar5;

    FUN_00420BC0(param_1);
    param_1[0x1c] = 0x34;
    param_1[0x26] = 0;
    DAT_00462E80 = param_1[0x31];
    pGVar1 = param_1[0x1e];
    pGVar2 = param_1[0x1f];
    param_1[0x14] = 0x45;
    iVar6 = (int)((((unsigned int)param_1[0x31] + 0x200000u) & 0xC00000u) >> 0x16) << 0x4;
    param_1[0x15] = 0x3;
    iVar4 = *(int *)((char *)&DAT_00458798 + iVar6);
    iVar5 = *(int *)((char *)&DAT_0045879C + iVar6);

    do {
        param_1[0x1e] = pGVar1 + iVar4;
        param_1[0x1f] = pGVar2 + iVar5;
        if (FUN_00423A50(param_1) != 0) {
            break;
        }
        iVar4 = iVar4 + *(int *)((char *)&DAT_004587A0 + iVar6);
        iVar5 = iVar5 + *(int *)((char *)&DAT_004587A4 + iVar6);
    } while (iVar4 != 0 || iVar5 != 0);

    param_1[0x2a] = pGVar1;
    param_1[0x2b] = pGVar2;
    DAT_004A0218 = 0x67;
    FUN_00412B50(param_1);
}

}
