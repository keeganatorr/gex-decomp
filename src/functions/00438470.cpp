// Adapted from pc_decomp_backup/src/functions/FUN_00438470.cpp
// Historical source SHA256: 589803986dea7218b028197abbb6d1df8b899afb09a55febcedfe1a3a1b05ce5
extern "C" {
extern "C" { extern int DAT_0045B9A0[]; }
extern "C" { extern int DAT_004A2990; }
extern "C" int __cdecl FUN_0040F100(int, int, int);
extern "C" int __cdecl FUN_0040F170(int, int, int);
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" int __cdecl FUN_00419FE0(int, int, int);
extern "C" int __cdecl FUN_0041A090(void**);
extern "C" void** __cdecl FUN_0041A380(void**);

extern "C" void __cdecl GEX_Target(void** param_1, int param_2)
{
    int iVar3;
    unsigned int uVar4, uVar5, uVar8, uVar9;
    void* pGVar6;
    void** ppGVar7;
    int local_c, local_8;
    unsigned int local_18, local_14, local_4;

    param_1[0x1f] = (void*)((int)param_1[0x1f] + param_2 - 0x1c);
    pGVar6 = param_1[0x38];
    param_1[0x38] = (void*)((unsigned int)pGVar6 & 0xff7fffff);
    if ((((unsigned int)pGVar6 & 0x80) != 0) && (iVar3 = FUN_00419C00(param_1, 0, 0, &local_c, &local_8), iVar3 != 0)) {
        param_1[0x1e] = (void*)((int)param_1[0x1e] + local_c - 0x1c);
        param_1[0x1f] = (void*)((int)param_1[0x1f] + local_8 - 0x1c);
    }
    if ((((unsigned int)param_1[0x1b] & 0x20000) == 0) || (((unsigned int)param_1[0x38] & 0x400) != 0))
        goto LAB_EXIT;
    FUN_0041A380(param_1);
    uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] + 0x800), (unsigned int)param_1[0x1f]);
    uVar4 = DAT_0045B9A0[uVar4 * 8];
    uVar5 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] - 0x800), (unsigned int)param_1[0x1f]);
    if (((uVar4 & 0x800000) == 0) && ((DAT_0045B9A0[uVar5 * 8] & 0x800000) == 0)) {
        param_1[0x38] = (void*)((unsigned int)param_1[0x38] | 0x800000);
    }
    iVar3 = FUN_0041A090(param_1);
    if (iVar3 == 0) {
        if (param_2 < 0) {
            ppGVar7 = FUN_0041A380(param_1);
            if (((unsigned int)param_1[0x1b] & 0x40000000) == 0) pGVar6 = ppGVar7[1];
            else pGVar6 = (void*)-(int)ppGVar7[3];
            if (((unsigned int)param_1[0x38] & 0x400000) != 0) {
                pGVar6 = (void*)(((int)param_1[0x33] >> 8) * ((int)pGVar6 >> 8));
            }
            uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] + 0x800), (int)pGVar6 + (int)param_1[0x1f] - 0x1c);
            local_18 = DAT_0045B9A0[uVar4 * 8];
            uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] - 0x800), (int)pGVar6 + (int)param_1[0x1f] - 0x1c);
            local_14 = DAT_0045B9A0[uVar4 * 8];
            uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] + 0x800), (unsigned int)param_1[0x1f]);
            uVar4 = DAT_0045B9A0[uVar4 * 8];
            uVar5 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] - 0x800), (unsigned int)param_1[0x1f]);
        }
    }
LAB_EXIT:
    return;
}
}
