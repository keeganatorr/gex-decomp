// Adapted from pc_decomp_backup/src/functions/FUN_00437F40.cpp
// Historical source SHA256: e6abb6035c1b5a08d0cc758c42cb308ef05b1c99bcf0443f9c77df2af72f78e9
extern "C" {
extern "C" { extern int DAT_0045B9A0[]; }
extern "C" { extern int DAT_004A2990; }
extern "C" int __cdecl FUN_0040F100(int, int, int);
extern "C" int __cdecl FUN_0040F170(int, int, int);
extern "C" int __cdecl FUN_0040F1D0(int, void**);
extern "C" int __cdecl FUN_00419FE0(int, int, int);
extern "C" void** __cdecl FUN_0041A380(void**);
extern "C" void __cdecl FUN_00420FA0(void**);

extern "C" void __cdecl GEX_Target(void** param_1, int param_2)
{
    int uVar3;
    void** ppGVar4;
    int pGVar5;
    int objectType;
    int iVar7, iVar8;
    unsigned short uVar1, uVar2;
    int local_c, local_10;

    param_1[0x1e] = (void*)((int)param_1[0x1e] + param_2 - 0x1c);
    if ((param_1[0x37] == 0) && (param_2 != 0)) {
        objectType = FUN_0040F1D0(DAT_004A2990, param_1);
        if ((objectType < -0xfffff) || (objectType > 0xfffff)) {
            param_1[0x37] = (void*)objectType;
            param_1[0x38] = (void*)((unsigned int)param_1[0x38] | 0x1000);
        } else {
            param_1[0x37] = 0;
            param_1[0x1f] = (void*)(objectType + (int)param_1[0x1f] - 0x10);
        }
    }
    if (((unsigned int)param_1[0x38] & 0x4000) != 0) FUN_00420FA0(param_1);
    objectType = (int)param_1[0x1b];
    if ((objectType & 0x10000) == 0) return;
    if ((objectType & 0x1f000000) != 0) return;
    if (param_2 == 0) return;
    uVar3 = (unsigned int)objectType & 0x80000000;
    ppGVar4 = FUN_0041A380(param_1);
    objectType = (int)*ppGVar4;
    if ((objectType & 2) == 0) {
        if (((unsigned int)param_1[0x1b] & 0x40000000) == 0) {
            pGVar5 = (int)ppGVar4[1];
        } else {
            pGVar5 = -(int)ppGVar4[3];
        }
    } else {
        pGVar5 = (int)ppGVar4[8];
        iVar8 = (uVar3 != 0) ? (int)(*(int*)pGVar5 + -1) : 0;
        iVar7 = (uVar3 == 0) ? (int)(*(int*)pGVar5 + -1) : 0;
        if (param_2 < 0) iVar7 = iVar8;
        pGVar5 = (int)(*(int*)(pGVar5 + 4)) + (*(unsigned char*)(*(int*)(pGVar5) + iVar7 - 0x10) - 1) * 0x2000;
    }
    if (param_2 < 0) {
        if (uVar3 == 0) goto LAB_BLOCK;
        objectType = (int)ppGVar4[2];
    } else if (uVar3 == 0) {
        objectType = (int)ppGVar4[2];
        goto LAB_BLOCK;
    }
    objectType = -objectType;
LAB_BLOCK:
    if (((unsigned int)param_1[0x38] & 0x400000) != 0) {
        pGVar5 = ((int)param_1[0x33] >> 8) * (pGVar5 >> 8);
        objectType = ((int)param_1[0x32] >> 8) * (objectType >> 8);
    }
    uVar3 = FUN_0040F170(DAT_004A2990, objectType + (int)param_1[0x1e] - 0x1c, pGVar5 + (int)param_1[0x1f] - 0x1c);
    local_c = DAT_0045B9A0[uVar3 * 8];
    uVar3 = FUN_0040F170(DAT_004A2990, objectType + (int)param_1[0x1e] - 0x1c, (int)param_1[0x1f] - 0x80);
    local_10 = DAT_0045B9A0[uVar3 * 8];
    iVar8 = FUN_00419FE0(DAT_004A2990, objectType + (int)param_1[0x1e] - 0x1c, pGVar5 + (int)param_1[0x1f] - 0x1c);
    uVar1 = *(unsigned short*)(iVar8 + 2);
    iVar8 = FUN_00419FE0(DAT_004A2990, objectType + (int)param_1[0x1e] - 0x1c, (int)param_1[0x1f] - 0x80);
    uVar2 = *(unsigned short*)(iVar8 + 2);
    uVar3 = (objectType + (int)param_1[0x1e] - 0x1c) & 0x1fffff;
    if ((uVar1 & 0xfff) != 0 && (iVar8 = FUN_0040F100((int)DAT_004A2990, (unsigned int)uVar1, uVar3), (pGVar5 + (int)param_1[0x1f] - 0x1c & 0x1fffffU) < (unsigned int)iVar8)) {
        local_c = 0;
    }
    if ((uVar2 & 0xfff) != 0 && (iVar8 = FUN_0040F100((int)DAT_004A2990, (unsigned int)uVar2, uVar3), (unsigned int)((int)param_1[0x1f] - 0x80 & 0x1fffff) < (unsigned int)iVar8)) {
        local_10 &= 0xff7fffff;
    }
    if ((local_10 | local_c) & 0x800000) return;
    uVar3 = FUN_0040F170(DAT_004A2990, objectType + (int)param_1[0x1e] - 0x1c, (int)param_1[0x1f] + 0x800);
    if ((DAT_0045B9A0[uVar3 * 8] & 0xf000000) == 0x4000000) {
        param_1[0x1b] = (void*)((unsigned int)param_1[0x1b] & 0xedffffff | 0xd000000);
        return;
    }
    if ((DAT_0045B9A0[uVar3 * 8] & 0xf000000) == 0x8000000) {
        param_1[0x1b] = (void*)((unsigned int)param_1[0x1b] & 0xeeffffff | 0xe000000);
        return;
    }
    iVar8 = FUN_00419FE0(DAT_004A2990, objectType + (int)param_1[0x1e] - 0x1c, (int)param_1[0x1f]);
    if ((*(unsigned short*)(iVar8 + 2) & 0xfff) == 0) {
        uVar3 = FUN_0040F170(DAT_004A2990, (int)param_1[0x1e], (int)param_1[0x1f]);
        if (((DAT_0045B9A0[uVar3 * 8] & 0xf000000) != 0x4000000) && ((DAT_0045B9A0[uVar3 * 8] & 0xf000000) != 0x8000000)) {
            int uVar3_new = 0x2000000;
            if (param_2 < 0) uVar3_new = 0x1000000;
            param_1[0x1b] = (void*)(uVar3_new | (unsigned int)param_1[0x1b] & 0xe4ffffff | 0x4000000);
        }
    }
}
}
