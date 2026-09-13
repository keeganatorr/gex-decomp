// Adapted from pc_decomp_backup/src/functions/FUN_0041DD50.cpp
// Historical source SHA256: 86a4ba477791db4bd3c16e357e556070de8181b2949b95e43498da2ac9533def
extern "C" {
extern int DAT_0046368C;
extern int DAT_00463690;
extern "C" int __cdecl FUN_0041CB80(int* param_1, int** local_28);

extern "C" int __cdecl GEX_Target(int* param_1, int param_2)
{
    int iVar4;
    int pGVar7;
    int pGVar2;
    int pNVar5;
    int local_bc;
    int local_b8;
    int pGVar12;
    int pGVar9;
    int pGVar8;
    int pNVar6;
    int pNVar15;
    int pGVar11;
    int pGVar13;
    int pNVar16;
    int local_58[12];
    int local_28[10];
    
    int local_b0;
    int local_ac;
    int* local_a8;
    int local_a4;
    int local_a0;
    int local_9c;
    int local_98;
    int local_94;
    int local_90;
    int local_8c;
    int local_88;
    int local_84;
    int* local_80;
    int local_7c;
    int local_78;
    int local_74;
    int local_70;
    int local_6c;
    int local_68;
    int local_64;
    int local_60;
    int local_5c;
    
    DAT_00463690 = DAT_00463690 + 1;
    iVar4 = FUN_0041CB80(param_1, &local_a8);
    if (iVar4 == 0) {
        return 0;
    }
    
    iVar4 = FUN_0041CB80((int*)param_2, &local_80);
    if (iVar4 == 0) {
        return 0;
    }
    
    if (((local_8c < local_68) || (local_84 < local_60)) || ((local_64 < local_90) || (local_5c < local_88))) {
        return 0;
    }
    
    DAT_0046368C = DAT_0046368C + 1;
    
    pGVar7 = local_a8[4];
    if (pGVar7 != 0) {
        pGVar2 = local_80[4];
        if (pGVar2 != 0) {
            pNVar5 = *(int*)(pGVar7 + 4);
            while (pNVar5 != (int)0x80000000) {
                if (local_98 == 0) {
                    local_bc = *(int*)(pGVar7 + 4);
                    pGVar12 = *(int*)(pGVar7 + 0xc);
                } else {
                    local_bc = -*(int*)(pGVar7 + 0xc);
                    pGVar12 = -*(int*)(pGVar7 + 4);
                }
                
                if (local_94 == 0) {
                    local_b8 = *(int*)(pGVar7 + 8);
                    pGVar9 = *(int*)(pGVar7 + 0x10);
                } else {
                    local_b8 = -*(int*)(pGVar7 + 0x10);
                    pGVar9 = -*(int*)(pGVar7 + 8);
                }
                
                pNVar5 = local_b8;
                
                if (local_a4 != 0) {
                    if (local_a4 == 0x400000) {
                        local_b8 = local_bc;
                        pGVar9 = pGVar12;
                        pGVar11 = -pNVar5;
                        local_bc = -pGVar9;
                    } else if (local_a4 == 0x800000) {
                        pGVar9 = -local_b8;
                        pGVar11 = -local_bc;
                        local_bc = -pGVar12;
                        local_b8 = -pGVar9;
                    } else if (local_a4 == 0xc00000) {
                        pGVar9 = -local_bc;
                        local_bc = local_b8;
                        local_b8 = -pGVar12;
                    } else {
                        pGVar11 = pGVar12;
                        pGVar13 = pGVar9;
                    }
                } else {
                    pGVar11 = pGVar12;
                    pGVar13 = pGVar9;
                }
                
                if (*(int*)(pGVar2 + 4) != (int)0x80000000) {
                    local_58[0] = (int)&pGVar11 + local_a0;
                    pGVar8 = pGVar2;
                    
                    do {
                        if (local_70 == 0) {
                            pNVar5 = *(int*)(pGVar8 + 4);
                            pGVar12 = *(int*)(pGVar8 + 0xc);
                        } else {
                            pNVar5 = -*(int*)(pGVar8 + 0xc);
                            pGVar12 = -*(int*)(pGVar8 + 4);
                        }
                        
                        if (local_6c == 0) {
                            pNVar15 = *(int*)(pGVar8 + 8);
                            pGVar9 = *(int*)(pGVar8 + 0x10);
                        } else {
                            pNVar15 = -*(int*)(pGVar8 + 0x10);
                            pGVar9 = -*(int*)(pGVar8 + 8);
                        }
                        
                        pNVar6 = pNVar5;
                        pGVar11 = pGVar12;
                        pGVar13 = pGVar9;
                        pNVar16 = pNVar15;
                        
                        if (local_7c != 0) {
                            if (local_7c == 0x400000) {
                                pNVar6 = -pGVar9;
                                pGVar11 = -pNVar15;
                                pGVar13 = pGVar12;
                                pNVar16 = pNVar5;
                            } else if (local_7c == 0x800000) {
                                pNVar6 = -pGVar12;
                                pGVar11 = -pNVar5;
                                pGVar13 = -pNVar15;
                                pNVar16 = -pGVar9;
                            } else if (local_7c == 0xc00000) {
                                pNVar16 = -pGVar12;
                                pGVar13 = -pNVar5;
                                pNVar6 = pNVar15;
                                pGVar11 = pGVar9;
                            }
                        }
                        
                        if (((int)&pNVar6 + local_78 <= local_58[0]) &&
                            ((int)&pNVar16 + local_74 > local_58[0] - local_a0 + (int)&pGVar11)) {
                            break;
                        }
                        
                        pGVar8 = *(int*)(pGVar8 + 4);
                    } while (pGVar8 != (int)0x80000000);
                }
                
                pGVar7 = *(int*)(pGVar7 + 4);
            }
        }
    }
    
    return 0;
}
}
