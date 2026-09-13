// Adapted from pc_decomp_backup/src/functions/FUN_0042AD40.cpp
// Historical source SHA256: 12f943dda5c1d6ff507a2d9e4e0dc4192639dbc3fb399d4bce1adb5afa0f347e
extern "C" {
extern int DAT_0045ACD0;
extern int DAT_0045ACF0;
extern int DAT_0045ACF4;
extern int DAT_0045AD00;
extern int DAT_0045AD20;
extern int DAT_0045AD24;
extern unsigned char DAT_004A2540;
extern unsigned char FUN_004577B0;

extern "C" int __cdecl FUN_0040C110(int a, int b);
extern "C" unsigned int __cdecl FUN_00428C60();
extern "C" void __cdecl FUN_0041A360(int a, int b);
extern "C" void __cdecl FUN_004372F0(int param_1);

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int pGVar2;
    int ppGVar5;
    unsigned int uVar6;
    unsigned int uVar7;
    int pGVar3;
    int pGVar4;
    int ppGVar1;
    
    pGVar2 = param_1[0x2b];
    if ((pGVar2 & 0x20) != 0) {
        ppGVar5 = FUN_0040C110(0xdc, (unsigned int)param_1[0x27] & 0xffff);
        pGVar2 = *(int*)(ppGVar5 + 0x27 * 4);
        uVar7 = *(unsigned short*)((int)&FUN_004577B0 + pGVar2 * 8) & 0xf;
        
        if ((((*(int*)(ppGVar5 + 0x29 * 4) & 0x200) == 0) || ((*(int*)(ppGVar5 + 0x29 * 4) & 0x400) == 0)) ||
           ((*(int*)(pGVar2 + 0x2512 * 4 + 0x48) & 3) == 3)) {
            
            if ((*(int*)(pGVar2 + 0x2512 * 4 + 0x48) & 2) == 0) {
                if ((*(int*)(pGVar2 + 0x2512 * 4 + 0x48) & 1) == 0) {
                    uVar6 = (unsigned int)param_1[0x2b] & 0xffffff01;
                    param_1[0x2b] = (int)(uVar6 | 1);
                    pGVar3 = DAT_0045ACD0;
                    if ((*(int*)(ppGVar5 + 0x29 * 4) & 0x40000000) == 0) {
                        param_1[0x15] = DAT_0045ACD0;
                        param_1[0x28] = (int)(((*(int*)(pGVar3 + 8) + DAT_0045AD00 + -0x1d) * 0x10000) | ((unsigned int)pGVar3 & 0xffff));
                        param_1[0x2a] = (int)((unsigned int)param_1[0x2a] & 0xffff4000 | 0x4000);
                        uVar6 = FUN_00428C60();
                        param_1[0x2d] = (int)((uVar6 & 0x5f) << 0x10);
                    } else {
                        param_1[0x15] = -1;
                        param_1[0x2b] = (int)(uVar6 | 0x41);
                    }
                } else {
                    uVar6 = (unsigned int)param_1[0x2b] & 0xffffff03;
                    ppGVar1 = (int)(param_1 + 0x15);
                    param_1[0x2b] = (int)(uVar6 | 3);
                    if ((*(int*)(ppGVar5 + 0x29 * 4) & 0x40000000) == 0) {
                        pGVar3 = *(int*)((int)&DAT_0045ACD0 + uVar7 * 4);
                        *(int*)(ppGVar1) = pGVar3;
                        param_1[0x28] = (int)(((*(int*)(pGVar3 + 8) + *(int*)((int)&DAT_0045AD00 + uVar7 * 4) + -0x1d) * 0x10000) | ((unsigned int)pGVar3 & 0xffff));
                        param_1[0x2a] = (int)((unsigned int)param_1[0x2a] & 0xffff4000 | 0x4000);
                        *(int*)(ppGVar1) = (int)(*(int*)(pGVar3 + 8) + (*(int*)(ppGVar5 + 0x26 * 4) % *(int*)((int)&DAT_0045AD00 + uVar7 * 4)) + -0x1c);
                        uVar6 = FUN_00428C60();
                        param_1[0x2d] = (int)((uVar6 & 0x5f) << 0x10);
                    } else {
                        *(int*)(ppGVar1) = -1;
                        param_1[0x2b] = (int)(uVar6 | 0x43);
                    }
                    param_1[0x2c] = (int)((unsigned int)param_1[0x2c] & 0xffff);
                }
            } else {
                pGVar3 = param_1[0x2b];
                param_1[0x2b] = (int)((unsigned int)pGVar3 & 0xffffff05 | 5);
                pGVar4 = DAT_0045ACF0;
                if ((*(int*)(ppGVar5 + 0x29 * 4) & 0x40000000) == 0) {
                    param_1[0x15] = DAT_0045ACF0;
                    param_1[0x28] = (int)(((*(int*)(pGVar4 + 8) + DAT_0045AD20 + -0x1d) * 0x10000) | ((unsigned int)pGVar4 & 0xffff));
                    param_1[0x2a] = (int)((unsigned int)param_1[0x2a] & 0xffff4000 | 0x4000);
                } else {
                    param_1[0x15] = -1;
                    param_1[0x2b] = (int)((unsigned int)pGVar3 & 0xffffff05 | 0x45);
                }
            }
        } else {
            pGVar3 = param_1[0x2b];
            param_1[0x15] = -1;
            param_1[0x2b] = (int)((unsigned int)pGVar3 & 0xffffff11 | 0x11);
            if ((*(int*)(ppGVar5 + 0x29 * 4) & 0x40000000) != 0) {
                param_1[0x2b] = (int)((unsigned int)pGVar3 & 0xffffff11 | 0x51);
            }
        }
        param_1[0x27] = (int)((unsigned int)param_1[0x27] & 0xffff | (pGVar2 << 0x10));
        param_1[0x2c] = (int)((unsigned int)param_1[0x2c] & 0xffff0000 | uVar7);
        param_1[0x29] = (int)(param_1[0x15] << 0x10);
        return;
    }
    
    if (((pGVar2 & 0xf) == 1) && ((*(unsigned char*)((int)&DAT_004A2540 + ((unsigned int)param_1[0x27] >> 0x10)) & 1) != 0)) {
        if ((pGVar2 & 0x40) == 0) {
            FUN_0041A360(0x9b, 0xff);
            param_1[0x15] = DAT_0045ACF4;
            if ((param_1[0x2b] & 0x10) != 0) {
                FUN_004372F0((int)param_1);
            }
            pGVar2 = param_1[0x15];
            param_1[0x2b] = (int)((unsigned int)param_1[0x2b] & 0xffffff02 | 2);
            param_1[0x28] = (int)(((*(int*)(pGVar2 + 8) + DAT_0045AD24 + -0x1d) * 0x10000) | ((unsigned int)pGVar2 & 0xffff));
            param_1[0x29] = (int)(pGVar2 << 0x10);
            param_1[0x2a] = (int)((unsigned int)param_1[0x2a] & 0xffff8000 | 0x8000);
        } else {
            param_1[0x15] = -1;
            param_1[0x2b] = (int)((unsigned int)pGVar2 & 0xffffff03 | 3);
        }
        param_1[0x2c] = (int)((unsigned int)param_1[0x2c] & 0xffff);
        return;
    }
}
}
