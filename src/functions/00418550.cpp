// Adapted from pc_decomp_backup/src/functions/FUN_00418550.cpp
// Historical source SHA256: cab604aa78eb81603195d598f59dafd69377003605a55580e6828b471deedeba
extern "C" {
extern "C" { extern int FUN_0049FB90; }
extern "C" { extern unsigned int FUN_004A27BC; }
extern "C" { extern unsigned int FUN_004A27CC; }
extern "C" { extern unsigned int FUN_004A27C8; }
extern "C" { extern int FUN_004A27C0; }
extern "C" { extern int FUN_004A27C4; }
extern "C" { extern int FUN_004A27D0; }
extern "C" { extern int FUN_004A2990; }
extern "C" { extern unsigned int FUN_0045B9A0; }
extern "C" void __cdecl FUN_00405350(const char*, int);

extern "C" unsigned int __cdecl GEX_Target(unsigned int param_1) {
    unsigned int uVar4;
    int bVar3;
    int iVar5;
    int iVar6;
    int iVar8;
    int* piVar2;
    int** ppiVar7;
    unsigned short* puVar9;

    uVar4 = FUN_0049FB90;
    if (FUN_0049FB90 == 1) {
        bVar3 = 1;
        FUN_004A27BC = (unsigned int)(FUN_004A27BC == 0);
        FUN_004A27C0 = FUN_004A27C0 + 1;
    } else if (FUN_0049FB90 == 2) {
        bVar3 = 1;
        FUN_004A27CC = (unsigned int)(FUN_004A27CC == 0);
        FUN_004A27C4 = FUN_004A27C4 + 1;
    } else if (FUN_0049FB90 == 3) {
        bVar3 = 1;
        FUN_004A27C8 = (unsigned int)(FUN_004A27C8 == 0);
        FUN_004A27D0 = FUN_004A27D0 + 1;
    } else {
        bVar3 = 0;
        FUN_00405350((const char*)0x458e4c, FUN_0049FB90);
    }
    if (bVar3) {
        int* pLVar1 = *(int**)(FUN_004A2990 + 4);
        ppiVar7 = (int**)(pLVar1 + 12);
        for (iVar5 = pLVar1[12] * pLVar1[16]; iVar5 != 0; iVar5 = iVar5 + -1) {
            piVar2 = *ppiVar7;
            ppiVar7 = ppiVar7 + 1;
            if (piVar2 != (int*)0x0) {
                puVar9 = (unsigned short*)(piVar2 + 2);
                iVar6 = 0x40;
                do {
                    iVar8 = ((int)(*puVar9 & 0x1f) * 0x10) +
                            *(int*)(FUN_004A2990 + 0x14 + (((int)(*puVar9 & 0xffffffe7) >> 3) * 4));
                    if ((*(unsigned int*)((int)&FUN_0045B9A0 + (unsigned int)*(unsigned short*)(iVar8 + 6) * 0x20) & 0x300000) >> 0x14 == uVar4) {
                        *puVar9 = *(unsigned short*)(iVar8 + 10);
                    }
                    puVar9 = puVar9 + 1;
                    iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
            }
        }
    }
    return param_1;
}
}
