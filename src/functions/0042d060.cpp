// Adapted from pc_decomp_backup/src/functions/FUN_0042D060.cpp
// Historical source SHA256: c181e139d9ada71af01fbf22246f4898c4cdc40efe0a6b0b24eca1f53d59e1b5
extern "C" {
extern int DAT_0045B9AC;
extern int DAT_0045B9B0;
extern int DAT_004A01E0;
extern int DAT_004A01E4;
extern int DAT_004A01E8;
extern int DAT_004A01EC;
extern int DAT_004A01F0;
extern int DAT_004A2990;

extern "C" int __cdecl FUN_0041CB80(int* param_2, int** local_28);
extern "C" void* __cdecl FUN_0042CC90(int* param_2, int param_3);
extern "C" void* __cdecl FUN_0042CE70(int levelData, int tileData, unsigned int a, unsigned int b);

extern "C" int __cdecl GEX_Target(int* param_1, int* param_2, int param_3)
{
    int bounds[10];
    int iVar2;
    unsigned short uVar1;
    int pGVar6;
    int pGVar7;
    int pGVar3;
    int bVar8;
    int pcVar5;
    int levelDataAddr;
    int tileDataAddr;
    int puVar4;
    
    DAT_004A01EC = 0;
    DAT_004A01F0 = 0;
    DAT_004A01E4 = 0;
    DAT_004A01E8 = -1;
    
    iVar2 = FUN_0041CB80(param_2, (int**)bounds);
    if (iVar2 == 0) {
        return 0;
    }
    
    bVar8 = (int)param_2[0x1e] - (int)param_2[0x35] < 0;
    pGVar3 = bounds[9] - 0x80000;
    pGVar7 = bounds[8] + 0x80000;
    
    levelDataAddr = *(int*)(DAT_004A2990 + 4);
    tileDataAddr = *(int*)(DAT_004A2990 + 0x14);
    
    do {
        DAT_004A01EC = DAT_004A01EC + 1;
        FUN_0041CB80(param_2, (int**)bounds);
        
        if (bVar8) {
            pGVar6 = bounds[6];
        } else {
            pGVar6 = bounds[7];
        }
        
        puVar4 = (int)FUN_0042CE70(levelDataAddr, tileDataAddr, (unsigned int)pGVar6, (unsigned int)pGVar7);
        
        if (puVar4 != 0) {
            param_2[0x61] = pGVar6;
            param_2[0x62] = pGVar7;
            uVar1 = *(unsigned short*)(puVar4 + 6);
            
            if (uVar1 < 0x7e) {
                if (bVar8) {
                    pcVar5 = *(int*)((char*)&DAT_0045B9AC + (unsigned int)uVar1 * 0x20);
                } else {
                    pcVar5 = *(int*)((char*)&DAT_0045B9B0 + (unsigned int)uVar1 * 0x20);
                }
                
                if (pcVar5 != 0) {
                    iVar2 = ((int (*)(int*, int))pcVar5)(param_2, puVar4);
                    if (iVar2 != 0 && param_3 != 0) {
                        DAT_004A01E4 = 1;
                        iVar2 = ((int (*)(int*, int))param_3)(param_2, puVar4);
                        if (iVar2 == 0) {
                            goto FUN_0042D1B1;
                        }
                    }
                }
            }
        }
        
        if (DAT_004A01EC == 1 && DAT_004A01E0 == 0) {
            DAT_004A01F0 = 1;
        }
        
        if (pGVar3 == pGVar7) goto FUN_0042D1B1;
        
        pGVar7 = pGVar7 + 0x200000;
        if (pGVar3 < pGVar7) {
            pGVar7 = pGVar3;
        }
    } while (1);
    
FUN_0042D1B1:
    pGVar7 = bounds[8] + 0x80000;
    while (1) {
        FUN_0041CB80(param_2, (int**)bounds);
        
        if (bVar8) {
            pGVar6 = bounds[7];
        } else {
            pGVar6 = bounds[6];
        }
        
        puVar4 = (int)FUN_0042CE70(levelDataAddr, tileDataAddr, (unsigned int)pGVar6, (unsigned int)pGVar7);
        
        if (puVar4 != 0) {
            param_2[0x61] = pGVar6;
            param_2[0x62] = pGVar7;
            uVar1 = *(unsigned short*)(puVar4 + 6);
            
            if (uVar1 < 0x7e) {
                if (bVar8) {
                    pcVar5 = *(int*)((char*)&DAT_0045B9B0 + (unsigned int)uVar1 * 0x20);
                } else {
                    pcVar5 = *(int*)((char*)&DAT_0045B9AC + (unsigned int)uVar1 * 0x20);
                }
                
                if (pcVar5 != 0) {
                    iVar2 = ((int (*)(int*, int))pcVar5)(param_2, puVar4);
                    if (iVar2 != 0 && param_3 != 0) {
                        ((int (*)(int*, int))param_3)(param_2, puVar4);
                    }
                }
            }
        }
        
        if (pGVar3 == pGVar7) break;
        pGVar7 = pGVar7 + 0x200000;
        if (pGVar3 < pGVar7) {
            pGVar7 = pGVar3;
        }
    }
    
    DAT_004A01E4 = 0;
    FUN_0041CB80(param_2, (int**)bounds);
    
    if (!bVar8) {
        bounds[6] = bounds[7];
    }

    param_2[0x61] = bounds[6];
    FUN_0042CC90(param_2, param_3);
    return 0;
}
}
