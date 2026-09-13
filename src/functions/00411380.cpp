// Adapted from pc_decomp_backup/src/functions/FUN_00411380.cpp
// Historical source SHA256: 16f3e3244d49bb966dd4e0ec58138907ca41fb44b9da7e6ae4fa7b24672b33f7
extern "C" {
extern "C" { extern int DAT_00411A00; }
extern "C" { extern int DAT_00411A24; }
extern "C" { extern int DAT_00458C78; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern unsigned char DAT_004A0284; }
extern "C" { extern unsigned char DAT_004A0285; }
extern "C" { extern unsigned char DAT_004A0288; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int DAT_004A2864; }
extern "C" { extern int DAT_004A2990; }

extern "C" int __cdecl FUN_0040F100(int, int, int);
extern "C" int __cdecl FUN_00411230(int*, unsigned int**, unsigned int**, unsigned int**);
extern "C" void __cdecl FUN_004120C0(int**);
extern "C" void __cdecl FUN_00411FF0(int**, int, int);
extern "C" void __cdecl FUN_004123C0(int**);
extern "C" void __cdecl FUN_004125B0(int**);
extern "C" void __cdecl FUN_00412960(int**);
extern "C" void __cdecl FUN_00413170(int**);
extern "C" void __cdecl FUN_004138B0(int**);
extern "C" int __cdecl FUN_00419FE0(int, int, unsigned int);
extern "C" unsigned int __cdecl FUN_00420C40(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00421CD0(int**);
extern "C" int __cdecl FUN_00421F90(int**);
extern "C" void __cdecl FUN_004252B0(int**);

extern "C" void __cdecl GEX_Target(int** param_1)
{
    int iVar2, iVar7;
    unsigned int uVar6;
    int* pGVar3;
    int* pGVar4;
    int* pGVar5;
    int* pGVar8;
    int local_3c;
    unsigned int* local_30;
    unsigned int* local_2c;
    unsigned int* local_28[4];
    int local_10;
    int local_c;
    int local_4;
    
    FUN_00421CD0(param_1);
    
    if (DAT_004A0284 != 0 || DAT_00458C78 != 0 || (iVar2 = FUN_00421F90(param_1), iVar2 == 0)) {
        FUN_004138B0(param_1);
        return;
    }
    if (DAT_004A0293 != 0) {
        FUN_00412960(param_1);
        return;
    }
    if (DAT_004A0295 != 0) {
        FUN_00413170(param_1);
        return;
    }
    
    local_3c = 0;
    uVar6 = -(unsigned int)(DAT_004A0288 == 0) & 0xfffe0000;
    iVar7 = uVar6 + 0x70000;
    iVar2 = FUN_00411230((int*)DAT_004A2864, local_28, &local_2c, &local_30);
    if (iVar2 == 0) {
        FUN_004252B0(param_1);
        return;
    }
    pGVar4 = param_1[0x1e];
    pGVar3 = param_1[0x1f];
    
    switch (((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c | (int)param_1[0x31] >> 0x15) {
    case 0:
        if (DAT_004A0282 != 0) {
            pGVar8 = (int*)((int)pGVar3 - iVar7 - 0xc00);
            uVar6 = FUN_00420C40(DAT_004A2990, (unsigned int)pGVar4, (unsigned int)pGVar8);
            if (uVar6 == 0xc0000000) {
                DAT_004A2864 = 0;
                FUN_00411FF0(param_1, 0, 1);
            } else if ((int)pGVar8 < (int)local_30) {
                DAT_004A2864 = 0;
                FUN_004125B0(param_1);
            } else {
                param_1[0x1e] = pGVar4;
                param_1[0x1f] = (int*)((int)pGVar3 - iVar7);
                local_3c = 1;
            }
        } else if (DAT_004A0283 != 0) {
            pGVar8 = (int*)((int)pGVar3 + iVar7 + 0xc00);
            uVar6 = FUN_00420C40(DAT_004A2990, (unsigned int)pGVar4, (unsigned int)pGVar8);
            if (uVar6 == 0xc0000000) {
                DAT_004A2864 = 0;
                FUN_00411FF0(param_1, 0, 2);
            } else if ((int)pGVar8 < (int)local_30) {
                param_1[0x1e] = pGVar4;
                param_1[0x1f] = (int*)((int)pGVar3 + iVar7);
                local_3c = 1;
            } else {
                DAT_004A2864 = 0;
                FUN_004125B0(param_1);
            }
        }
        break;
    case 2:
        if (DAT_004A0281 != 0) {
            pGVar8 = (int*)((int)pGVar4 + uVar6 - 0x1c + 0xc00);
            uVar6 = FUN_00420C40(DAT_004A2990, (unsigned int)pGVar8, (unsigned int)pGVar3);
            if (uVar6 == 0xc0000000) {
                DAT_004A2864 = 0;
                FUN_00411FF0(param_1, 1, 0);
            } else if ((int)pGVar8 < local_c) {
                param_1[0x1e] = (int*)((int)pGVar4 + uVar6 - 0x1c);
                param_1[0x1f] = pGVar3;
                local_3c = 1;
            } else {
                FUN_004123C0(param_1);
            }
        }
        break;
    case 4:
        if (DAT_004A0283 != 0) {
            pGVar8 = (int*)((int)pGVar3 + uVar6 - 0x1c);
            pGVar3 = (int*)((int)pGVar4 + 0x80);
            iVar2 = FUN_00419FE0(DAT_004A2990, (int)pGVar3, (unsigned int)(pGVar8 + 0xc00));
            if ((*(unsigned short*)(iVar2 + 2) != 0) &&
                (iVar2 = FUN_0040F100((int)(*(int**)DAT_004A2990), (unsigned int)*(unsigned short*)(iVar2 + 2), (unsigned int)pGVar3 & 0x1f0000), iVar2 != 0) &&
                (iVar2 + -0x10000 <= (int)((unsigned int)(pGVar8 + 0xc00) & 0x1f0000))) {
                FUN_004120C0(param_1);
                return;
            }
            iVar2 = FUN_00419FE0(DAT_004A2990, (int)pGVar3, (unsigned int)(pGVar8 + -0x400));
            if ((*(unsigned short*)(iVar2 + 2) != 0) &&
                (iVar2 = FUN_0040F100((int)(*(int**)DAT_004A2990), (unsigned int)*(unsigned short*)(iVar2 + 2), (unsigned int)pGVar3 & 0x1f0000), iVar2 != 0)) {
                param_1[0x1e] = (int*)((int)pGVar4 + 0x80);
                param_1[0x1f] = (int*)((int)(pGVar8 + -0x400) + iVar2);
                local_3c = 1;
            }
        }
        break;
    }
    
    if (local_3c != 0) {
        param_1[0x14] = (int*)0x3c;
        param_1[0x15] = 0;
        param_1[0x26] = 0;
    }
}
}
