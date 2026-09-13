// Adapted from pc_decomp_backup/src/functions/FUN_0041E9D0.cpp
// Historical source SHA256: c524f34dd865cfc0fe233e4b3226838e780b6dc7216068c91ae032b24ad24381
extern "C" {
extern "C" void __cdecl FUN_0041CB80(int *, int **);

extern "C" int __cdecl GEX_Target(int *param_1, int param_2)
{
    int pGVar1;
    int *piVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int *piVar7;
    int **ppiVar8;
    unsigned int **ppuVar9;
    int iVar10;
    unsigned int local_68;
    int local_60;
    int local_5c;
    int local_58;
    int local_54;
    unsigned int *local_50[10];
    int local_48;
    int local_44;
    int local_40;
    int local_38;
    int local_34;
    int *local_28[10];
    int local_10;
    int local_c;
    int local_4;

    pGVar1 = param_1[0x5e];
    if (*(int *)(param_2 + 4) == 1) {
        FUN_0041CB80(param_1, (int **)local_28);
        FUN_0041CB80((int *)pGVar1, (int **)local_50);
    }
    else {
        piVar7 = (int *)(param_2 + 8);
        ppiVar8 = (int **)local_28;
        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *ppiVar8 = (int *)*piVar7;
            piVar7 = piVar7 + 1;
            ppiVar8 = ppiVar8 + 1;
        }
        piVar7 = (int *)(param_2 + 0x30);
        ppuVar9 = (unsigned int **)local_50;
        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *ppuVar9 = (unsigned int *)*piVar7;
            piVar7 = piVar7 + 1;
            ppuVar9 = ppuVar9 + 1;
        }
    }
    if ((*local_50[0] & 2) != 0) {
        piVar2 = (int *)local_50[0][8];
        iVar4 = local_c;
        if (((unsigned int)param_1[0x1b] & 0x80000000) != 0) {
            iVar4 = local_10;
            local_10 = local_c;
        }
        if (local_40 == 0) {
            local_60 = local_38;
            local_5c = local_34;
            iVar5 = local_48 + *piVar2;
            local_54 = piVar2[2];
            iVar10 = local_54 * 0x10000 + *piVar2 + local_48;
            local_58 = 0;
            iVar3 = iVar5;
        }
        else {
            local_58 = piVar2[2];
            local_60 = local_34;
            local_5c = local_38;
            iVar10 = local_48 - *piVar2;
            iVar5 = (local_48 + local_58 * -0x10000) - *piVar2;
            local_54 = 0;
            iVar3 = iVar10;
        }
        iVar6 = (local_4 - piVar2[1]) - local_44;
        if ((iVar5 < local_10 && local_10 < iVar10) &&
            (local_68 = (unsigned int)*(unsigned char *)(((local_10 - iVar3) >> 0x10) + 0xc + (int)piVar2),
            iVar6 < (int)(local_68 * 0x10000)))
        {
            return 1;
        }
        if ((iVar5 < iVar4 && iVar4 < iVar10) &&
            (iVar6 < (int)((unsigned int)*(unsigned char *)(((iVar4 - iVar3) >> 0x10) + 0xc + (int)piVar2) * 0x10000)))
        {
            return 1;
        }
        if ((local_10 < local_60 || iVar5 <= local_10) && (iVar4 < local_60 || iVar5 <= iVar4))
        {
            if ((iVar10 <= local_10) &&
                ((local_10 < local_5c || (iVar10 <= local_10 && local_10 < local_5c)) &&
                 iVar6 < (int)((unsigned int)*(unsigned char *)(local_54 + 0xc + (int)piVar2) * 0x10000)))
            {
                return 1;
            }
        }
        else if (iVar6 < (int)((unsigned int)*(unsigned char *)((int)piVar2 + local_58 + 0xc) * 0x10000))
        {
            return 1;
        }
    }
    return 0;
}
}
