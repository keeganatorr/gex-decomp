// Adapted from pc_decomp_backup/src/functions/FUN_00430990.cpp
// Historical source SHA256: 34c21ca59feb6b967aa4689655e27f84eb0657170f8052db10e0c13c2298579e
extern "C" {
extern "C" int __cdecl GEX_Target(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9)
{
    int iVar1, iVar2, iVar3, iVar4;
    int iVar6, iVar7, iVar8, iVar9;
    unsigned int uVar5, uVar10;

    uVar5 = param_8 - param_6;
    uVar10 = param_9 - param_7;

    iVar7 = param_2 + *(int *)(param_1 + 0x7c);
    iVar8 = param_3 + *(int *)(param_1 + 0x7c);
    iVar6 = param_4 + *(int *)(param_1 + 0x78);
    iVar9 = param_5 + *(int *)(param_1 + 0x78);

    if (((((param_6 < iVar6) && (param_8 < iVar6)) || ((iVar9 < param_6 && (iVar9 < param_8)))) ||
        ((param_7 < iVar7 && (param_9 < iVar7)))) || ((iVar8 < param_7 && (iVar8 < param_9)))) {
        return 0;
    }

    iVar2 = (int)(int)uVar5 >> 8;
    if ((uVar10 & 0xffff0000) == 0) {
        iVar1 = ((iVar7 - param_7 >> 8)) * iVar2;
        iVar2 = ((iVar8 - param_7 >> 8)) * iVar2;
    } else {
        iVar1 = ((iVar7 - param_7 >> 8) * iVar2) / ((int)uVar10 >> 0x10);
        iVar2 = ((iVar8 - param_7 >> 8) * iVar2) / ((int)uVar10 >> 0x10);
    }

    iVar4 = (int)(int)uVar10 >> 8;
    if ((uVar5 & 0xffff0000) == 0) {
        iVar3 = ((iVar6 - param_6 >> 8)) * iVar4;
        iVar4 = ((iVar9 - param_6 >> 8)) * iVar4;
    } else {
        iVar3 = ((iVar6 - param_6 >> 8) * iVar4) / ((int)uVar5 >> 0x10);
        iVar4 = ((iVar9 - param_6 >> 8) * iVar4) / ((int)uVar5 >> 0x10);
    }

    if ((((iVar1 + param_6 < iVar6) || (iVar9 <= iVar1 + param_6)) &&
        ((iVar2 + param_6 < iVar6 || (iVar9 <= iVar2 + param_6)))) &&
       (((iVar3 + param_7 < iVar7 || (iVar8 <= iVar3 + param_7)) &&
        ((iVar4 + param_7 < iVar7 || (iVar8 <= iVar4 + param_7)))))) {
        return 0;
    }

    return 1;
}
}
