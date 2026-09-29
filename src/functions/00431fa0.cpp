// Adapted from pc_decomp_backup/src/functions/FUN_00431FA0.cpp
// Historical source SHA256: 22c4e85d8f5029eaa71228139f6ec1cc8595f0e9f41a925b7dada2f4198910d7
extern "C" {
extern int DAT_0045B210;
extern int DAT_00463FE8;
extern int DAT_00463FEC;
extern int DAT_004A2AD4;

extern "C" int __cdecl FUN_0041A380(int param_1);
extern "C" unsigned int __cdecl FUN_00428C60();
extern "C" int __cdecl FUN_00428C80(int a);
extern "C" int __cdecl FUN_004195D0(int a, int b, int c, int d);
extern "C" void __cdecl FUN_00419BE0(int a, int b);
extern "C" void __cdecl FUN_0042E850(int param_1);
extern "C" void __cdecl FUN_00441150(int param_1);
extern "C" void __cdecl FUN_00419A80(int param_1);

extern "C" int __cdecl FUN_00431fa0(int* param_1, int param_2)
{
    int ppGVar6;
    int pGVar2;
    int iVar9;
    int ppGVar8;
    unsigned int uVar7;
    int pNVar3;
    unsigned short* puVar14;
    unsigned short* puVar15;
    int local_c;
    int iVar11;
    unsigned short uVar1;
    int pGVar10;
    int pGVar4, pGVar5;
    int _result;
    int* _rptr;
    int _dummy1, _dummy2;
    
    _rptr = &_result;
    _dummy1 = 0;
    _dummy2 = 0;
    *_rptr = 0;
    
    ppGVar6 = FUN_0041A380((int)param_1);
    if (ppGVar6 == 0) { _result = 0; return _result; }
    
    param_1[0x30] = (int)(param_1 + 0x47);
    param_1[0x33] = (int)(&param_1[0x32] - 1);
    
    if (param_1[0x28] != 0x20) {
        param_1[0x28] = (int)((int*)param_1[0x28] + 1);
    }
    
    if (param_2 == 0) {
        uVar7 = FUN_00428C60();
        if ((uVar7 & 7) == 0) {
            pGVar2 = param_1[0x2b];
            ppGVar8 = DAT_004A2AD4;
            uVar7 = FUN_00428C60();
            iVar9 = (int)(*(int*)(pGVar2 + (int)((uVar7 & 0xf) * -0x80) + 8) + 2) +
                    (int)(param_1 + 0x1f) + 0x37f * 4 + 3 + 0x3 * 4;
            
            pGVar2 = param_1[0x2a];
            uVar7 = FUN_00428C60();
            ppGVar8 = FUN_004195D0(0x5c,
                (int)(*(int*)(pGVar2 + (int)((uVar7 & 0xf) * -0x80) + 8) + 2) +
                (int)(param_1 + 0x1e) + 0x37f * 4 + 3 + 0x3 * 4,
                iVar9, ppGVar8);
            
            if (ppGVar8 != 0) {
                *(int*)(ppGVar8 + 0x6c) = *(int*)(ppGVar8 + 0x6c) | 0xc000;
                *(int*)(ppGVar8 + 0x84) = 0x7fff0000;
                uVar7 = FUN_00428C60();
                *(int*)(ppGVar8 + 0x80) = (uVar7 & 0xf) * 0x8000 + -0x38000;
                *(int*)(ppGVar8 + 0x90) = 0x7fff0000;
                iVar9 = FUN_00428C80(0x40000);
                *(int*)(ppGVar8 + 0x8c) = -iVar9;
                *(int*)(ppGVar8 + 0x94) = 0x4000;
                *(int*)(ppGVar8 + 0x50) = 0x1b;
                *(int*)(ppGVar8 + 0x98) = 0x6;
                *(int*)(ppGVar8 + 0x70) = 0x30;
                if (((unsigned int)param_1[0x38] & 0x40) != 0) {
                    *(int*)(ppGVar8 + 0xe0) = *(int*)(ppGVar8 + 0xe0) | 0x40;
                }
                FUN_00419BE0(ppGVar8, (int)param_1);
            }
        }
    }
    
    if (*(int*)(ppGVar6 + 0x18) != 0) {
        pNVar3 = *(int*)(*(int*)(ppGVar6 + 0x18) + 4);
        if (pNVar3 != 0) {
            pGVar2 = param_1[0x28];
            puVar14 = (unsigned short*)(*(int*)(DAT_0045B210 + param_2 * 4) + param_1[0x27] * 2 + 4);
            
            if (puVar14[pGVar2] == (unsigned short)-1) {
                if (((unsigned int)param_1[0x38] & 0x20000) == 0) {
                    FUN_00419A80((int)param_1);
                }
                _result = 1;
                return _result;
            }
            
            if (*(char*)(pNVar3 + 8 - 4) == '\0') {
                puVar15 = (unsigned short*)((int)param_1 + 0x11e);
                param_1[0x46] = -256;
                *(unsigned short*)(param_1[0x30] + 4) = 0;
                pGVar10 = 1;
                
                if ((int)pGVar2 > 1) {
                    do {
                        uVar1 = *puVar14;
                        puVar14++;
                        *puVar15 = uVar1;
                        puVar15++;
                        pGVar10 = pGVar2;
                        pGVar2--;
                    } while (pGVar2 != 0);
                    pGVar2 = param_1[0x28];
                }
                
                puVar14 = (unsigned short*)(*(int*)(pNVar3 + 8) + pGVar10 * 2);
                if (pGVar10 < 0x10) {
                    iVar9 = 0x10 - pGVar10;
                    do {
                        uVar1 = *puVar14;
                        puVar14++;
                        *puVar15 = uVar1;
                        puVar15++;
                        iVar9--;
                    } while (iVar9 != 0);
                }
            } else {
                puVar15 = (unsigned short*)&DAT_00463FEC;
                iVar9 = 0;
                param_1[0x30] = (int)&DAT_00463FEC;
                DAT_00463FE8 = -255;
                
                do {
                    local_c = 0;
                    pGVar10 = pGVar2;
                    if ((int)pGVar2 > 0) {
                        do {
                            *puVar15 = *puVar14;
                            puVar15++;
                            pGVar10--;
                            puVar14++;
                            local_c = pGVar2;
                        } while (pGVar10 != 0);
                    }
                    
                    puVar14 = (unsigned short*)(pNVar3 + 8 - 28 + local_c * 2 + iVar9 * 2);
                    
                    if (local_c < 0x20) {
                        iVar11 = 0x20 - local_c;
                        do {
                            uVar1 = *puVar14;
                            puVar14++;
                            *puVar15 = uVar1;
                            puVar15++;
                            iVar11--;
                        } while (iVar11 != 0);
                    }
                    
                    iVar9 = iVar9 + 0x20;
                } while (iVar9 < 0x100);
                
                *(unsigned short*)(param_1[0x30] + 4) = 0;
            }
            
            if (((unsigned int)param_1[0x38] & 0x40) == 0) {
                FUN_00441150((int)param_1);
            } else {
                pGVar2 = param_1[0x1e];
                pGVar10 = param_1[0x1f];
                pGVar4 = param_1[0x32];
                pGVar5 = param_1[0x33];
                FUN_0042E850((int)param_1);
                FUN_00441150((int)param_1);
                param_1[0x1e] = pGVar2;
                param_1[0x1f] = pGVar10;
                param_1[0x32] = pGVar4;
                param_1[0x33] = pGVar5;
            }
        }
    }
    
    param_1[0x27] = (int)((int*)param_1[0x27] + 1);
    _result = 0;
    return _result;
}
}
