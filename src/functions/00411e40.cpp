// Adapted from pc_decomp_backup/src/functions/FUN_00411E40.cpp
// Historical source SHA256: 39a482d592c9fd3d24c15963eb5383857fd06c6a9e1bb91763a9c54db8b4c0d6
extern "C" {
extern int DAT_004583e8[];
extern int DAT_00458488[];
extern int DAT_0045848c[];
extern int DAT_00458508[];
extern int DAT_00458368[];
extern int DAT_0045836c[];
extern int FUN_004A2864;

extern "C" void __cdecl FUN_00421cd0_xpos_ypos_related(void **);
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void **);
extern "C" int __cdecl FUN_0041CB80(void **, int **);
extern "C" void __cdecl FUN_00411160(void **);

extern "C" void __cdecl PlayerSideInside90Trans_00411e40(void **param_1)
{
    int iVar1;
    int pGVar2;
    int pGVar3;
    unsigned int uVar4;
    int *local_28[6];

    FUN_00421cd0_xpos_ypos_related(param_1);
    iVar1 = FUN_00421f20_pStateUnk_Side(param_1);
    if (iVar1 == 0) {
        return;
    }
    pGVar2 = (int)param_1[0x26];
    param_1[0x26] = (void *)(pGVar2 + 0x40);
    if ((int)param_1[0x26] < 0x10001) {
        return;
    }
    param_1[0x26] = (void *)(pGVar2 + -0x40);
    uVar4 = (((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c) | ((int)param_1[0x31] >> 0x15);
    pGVar3 = (int)param_1[0x15] + 1;
    param_1[0x15] = (void *)pGVar3;
    param_1[0x1e] = (void *)(*(int *)param_1[0x1e] + DAT_004583e8[(pGVar3 + DAT_00458488[uVar4 * 2] * 5 + -0x1c) * 4] + -0x1c);
    param_1[0x1f] = (void *)(*(int *)param_1[0x1f] + DAT_004583e8[(pGVar3 + DAT_0045848c[uVar4 * 2] * 5 + -0x1c) * 4] + -0x1c);
    if (pGVar3 < 4) {
        return;
    }
    uVar4 = DAT_00458508[uVar4];
    param_1[0x31] = (void *)((uVar4 & 7) << 0x15);
    param_1[0x1b] = (void *)((unsigned int)param_1[0x1b] & 0x7fffffff);
    if ((uVar4 & 8) != 0) {
        param_1[0x1b] = (void *)((unsigned int)param_1[0x1b] | 0x80000000);
    }
    if (param_1[0x2a] != (void *)0x0) {
        if (param_1[0x2a] == (void *)2) {
            if ((FUN_004A2864 == 0) || (iVar1 = FUN_0041CB80((void **)FUN_004A2864, local_28), iVar1 == 0))
                goto FUN_00411F6F;
        }
        else {
            pGVar2 = (int)param_1[0x1e] & 0xffe00000;
            param_1[0x1e] = (void *)pGVar2;
            param_1[0x1e] = (void *)(DAT_00458368[uVar4 * 2] | pGVar2);
        }
    }
FUN_00411F6F:
    if (param_1[0x2b] != (void *)0x0) {
        if (param_1[0x2b] == (void *)2) {
            if ((FUN_004A2864 == 0) || (iVar1 = FUN_0041CB80((void **)FUN_004A2864, local_28), iVar1 == 0))
                goto FUN_00411FBD;
        }
        else {
            pGVar2 = (int)param_1[0x1f];
            param_1[0x1f] = (void *)((unsigned int)pGVar2 & 0xffe00000);
            param_1[0x1f] = (void *)(DAT_0045836c[uVar4 * 2] | ((unsigned int)pGVar2 & 0xffe00000));
        }
    }
FUN_00411FBD:
    FUN_00411160(param_1);
}
}
