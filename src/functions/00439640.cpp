// Adapted from pc_decomp_backup/src/functions/FUN_00439640.cpp
// Historical source SHA256: c2ad498b937f65985537dea5a1bbf8f5de8044c25d4131901590a04cdd969d73
extern "C" {
extern int PTR_ARRAY_00464610[];
extern int FUN_004645B0[];
extern int DAT_00464528;
extern int DAT_00464530;
extern int DAT_00464534;
extern int DAT_0046452c;
extern int DAT_0046466c;
extern int DAT_00464668;
extern int DAT_00464664;
extern int DAT_00464660;
extern int DAT_0046465c;
extern int DAT_00464520;
extern int DAT_00464524;
extern int DAT_004645ac;
extern int PTR_00464518;
extern int DAT_0046451c;
extern int DAT_004646f0;
extern int DAT_004646f8;

extern "C" unsigned int __cdecl FUN_004391d0_HuntDiveInner(int, int, int);

extern "C" void __cdecl GEX_Target(int param_1)
{
    int iVar1;
    unsigned int uVar2;
    unsigned int uVar3;
    int iVar4;

    iVar1 = *(int *)(param_1 + 0x9c);
    iVar4 = PTR_ARRAY_00464610[iVar1];
    FUN_004645B0[iVar1 * 3 + 2] = FUN_004645B0[iVar1 * 3 + 1];
    FUN_004645B0[iVar1 * 3 + 1] = FUN_004645B0[iVar1 * 3];
    uVar2 = *(unsigned int *)((int)&DAT_00464528 + iVar1 * 4);
    FUN_004645B0[iVar1 * 3] = *(unsigned int *)(iVar4 + 0xa0);
    *(unsigned int *)((int)&DAT_00464530 + iVar1 * 4) = uVar2;
    *(unsigned int *)((int)&DAT_00464534 + iVar1 * 4) = *(unsigned int *)((int)&DAT_0046452c + iVar1 * 4);
    *(unsigned int *)((int)&DAT_00464528 + iVar1 * 4) = *(unsigned int *)(param_1 + 0xd4);
    *(unsigned int *)((int)&DAT_0046452c + iVar1 * 4) = *(unsigned int *)(param_1 + 0xd8);
    *(unsigned int *)(param_1 + 0xd4) = *(unsigned int *)(param_1 + 0x78);
    *(unsigned int *)(param_1 + 0xd8) = *(unsigned int *)(param_1 + 0x7c);
    *(unsigned int *)((int)&DAT_0046466c + iVar1 * 0x10) = *(unsigned int *)((int)&DAT_00464668 + iVar1 * 4);
    *(unsigned int *)((int)&DAT_00464668 + iVar1 * 4) = *(unsigned int *)((int)&DAT_00464664 + iVar1 * 4);
    *(unsigned int *)((int)&DAT_00464664 + iVar1 * 4) = *(unsigned int *)((int)&DAT_00464660 + iVar1 * 4);
    if (iVar1 < 1) {
        if (DAT_004646f0 != 5) {
            uVar3 = FUN_004391d0_HuntDiveInner(0, DAT_00464524, DAT_004646f8);
            *(unsigned int *)((int)&DAT_00464660 + iVar1 * 4) = (uVar3 & 0xffffff00) * 0x60;
            goto FUN_00439741;
        }
        iVar4 = DAT_004646f8;
        if (0x600000 < DAT_004646f8) {
            iVar4 = 0x600000;
        }
    }
    else {
        iVar4 = *(int *)((int)&DAT_0046465c + iVar1 * 4);
    }
    *(int *)((int)&DAT_00464660 + iVar1 * 4) = iVar4;
FUN_00439741:
    if (0 < iVar1) {
        if (DAT_004646f0 != 5) {
            *(unsigned int *)(PTR_ARRAY_00464610[iVar1] + 0x78) = *(unsigned int *)((int)&DAT_00464520 + iVar1 * 4);
            *(int *)(PTR_ARRAY_00464610[iVar1] + 0x7c) = *(int *)((int)&DAT_00464524 + iVar1 * 4);
            *(unsigned int *)(param_1 + 0xa0) = *(unsigned int *)((int)&DAT_004645ac + iVar1 * 0xc);
            return;
        }
        if (0 < iVar1) {
            *(unsigned int *)(PTR_ARRAY_00464610[iVar1] + 0x78) = *(unsigned int *)((int)&PTR_00464518 + iVar1 * 4);
            *(unsigned int *)(PTR_ARRAY_00464610[iVar1] + 0x7c) = *(unsigned int *)((int)&DAT_0046451c + iVar1 * 0x10);
            *(unsigned int *)(param_1 + 0xa0) = *(unsigned int *)((int)&DAT_004645ac + iVar1 * 0xc);
        }
    }
}
}
