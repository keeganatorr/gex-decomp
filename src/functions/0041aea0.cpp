// Adapted from pc_decomp_backup/src/functions/FUN_0041AEA0.cpp
// Historical source SHA256: 55ddf2c7596ea682fc4cb3a3b68524d7419f1224865b1f8609080ec2682192e9
extern "C" {
extern int FUN_004A2AD4;
extern int DAT_00458c7c;
extern int DAT_00459054;
extern int DAT_00459058;
extern int DAT_0045905c;
extern int DAT_00459050;

extern "C" void __cdecl FUN_0041A630(int);
extern "C" void __cdecl FUN_0041A340(void **, int);
extern "C" int __cdecl FUN_00428C80(int);
extern "C" void ** __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void **, void **);
extern "C" void __cdecl FUN_00419A80(void **);

extern "C" void __cdecl GEX_Target(void **param_1)
{
    int iVar1;
    void **ppGVar2;
    int iVar3;
    int iVar4;
    int ypos;

    FUN_0041A630((((int)param_1[0x28] << 0x10 | (unsigned int)param_1[0x26]) << 8 | (unsigned int)param_1[0x27]));
    iVar4 = 0x14;
    DAT_00458c7c = 1;
    FUN_0041A340(param_1, 0xac);
    do {
        ppGVar2 = (void **)FUN_004A2AD4;
        iVar1 = FUN_00428C80(DAT_00459054);
        ypos = (int)param_1[0x1f] + (iVar1 + -0x10) * 0x80;
        iVar1 = FUN_00428C80(DAT_00459054);
        ppGVar2 = FUN_004195D0(0x5c, (int)param_1[0x1e] + iVar1 * 0x80, ypos, (int)ppGVar2);
        if (ppGVar2 != (void **)0x0) {
            ppGVar2[0x1b] = (void *)((unsigned int)ppGVar2[0x1b] | 0xc000);
            ppGVar2[0x21] = (void *)0x7fff0000;
            iVar1 = FUN_00428C80(DAT_00459058);
            iVar1 = DAT_00459058 + iVar1;
            iVar3 = FUN_00428C80(2);
            ppGVar2[0x20] = (void *)(iVar1 * ((-(unsigned int)(iVar3 == 0) & 2) - 1));
            ppGVar2[0x24] = (void *)0x7fff0000;
            iVar1 = FUN_00428C80(2);
            iVar3 = FUN_00428C80(DAT_0045905c);
            ppGVar2[0x23] = (void *)(((-(unsigned int)(iVar1 == 0) & 2) - 1) * (DAT_0045905c + iVar3));
            ppGVar2[0x14] = (void *)0x20;
            ppGVar2[0x26] = (void *)DAT_00459050;
            ppGVar2[0x1c] = (void *)0x30;
            FUN_00419BE0(ppGVar2, param_1);
        }
        iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (param_1[0x2b] != (void *)0x0) {
        param_1[0x2c] = (void *)0x28;
        param_1[0x19] = (void *)0x0;
        return;
    }
    FUN_00419A80(param_1);
}
}
