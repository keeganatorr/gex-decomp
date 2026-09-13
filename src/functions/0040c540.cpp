// Adapted from pc_decomp_backup/src/functions/FUN_0040C540.cpp
// Historical source SHA256: 54f78e697034e4e1894b989aecb3230d34568a3d344c34727a7223e320e6a463
extern "C" {
extern "C" { extern int DAT_0045601C; }
extern "C" { extern int DAT_00456020; }
extern "C" { extern int DAT_0045603C; }
extern "C" { extern int DAT_00456228; }
extern "C" { extern int DAT_0045622C; }
extern "C" { extern int DAT_00456230; }
extern "C" { extern int DAT_00456234; }
extern "C" { extern int DAT_00456238; }
extern "C" { extern unsigned char DAT_00455C08; }
extern "C" { extern unsigned char DAT_00455C0C; }
extern "C" { extern unsigned char DAT_00455C10; }
extern "C" { extern unsigned char DAT_00455C3C; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern unsigned char DAT_004A0284; }
extern "C" { extern unsigned char DAT_004A0285; }
extern "C" { extern unsigned char DAT_004A0288; }
extern "C" { extern unsigned char DAT_004A028B; }
extern "C" { extern unsigned char DAT_004A028C; }
extern "C" { extern unsigned char DAT_004A028F; }
extern "C" { extern unsigned char DAT_004A0292; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int DAT_004A2918; }
extern "C" { extern int DAT_004A291C; }
extern "C" { extern int DAT_004A2920; }
extern "C" { extern unsigned int DAT_004A2A74; }
extern "C" { extern unsigned int DAT_004A2A7C; }
extern "C" { extern int DAT_00462C68; }
extern "C" { extern unsigned char DAT_00462C70; }

extern "C" int __cdecl FUN_00402E70(int);
extern "C" int __cdecl FUN_00402EB0(void);
extern "C" void __cdecl FUN_00402F30(void);
extern "C" void __cdecl FUN_00402F70(void);
extern "C" void __cdecl FUN_004099B0(int);
extern "C" int** __cdecl FUN_0040C110(int, int);
extern "C" void __cdecl FUN_0040C940(void);
extern "C" void __cdecl FUN_0040CA70(int**, int*);
extern "C" void __cdecl FUN_0040CCA0(int**);
extern "C" void __cdecl FUN_0041A360(int, int);

extern "C" void __cdecl GEX_Target(int** param_1)
{
    int iVar3;
    int** ppGVar4;
    unsigned char bVar1;
    int* pGVar2, *pGVar5;
    unsigned char* buttonNumber;
    
    if (DAT_0045601C != 0 && (iVar3 = (int)FUN_00402EB0(), iVar3 != 0)) {
        FUN_00402E70(DAT_0045601C);
        DAT_0045601C = 0;
        FUN_00402F30();
        DAT_00456020 = 1;
    }
    
    if (param_1[0x28] == 0 || param_1[0x29] == 0) {
        FUN_0040CA70(param_1, (int*)param_1[0x2a]);
    } else {
        pGVar5 = param_1[0x2a];
        if (pGVar5 == (int*)0x15 && DAT_004A0294 != 0) {
            FUN_0040C940();
            DAT_00455C3C = 1;
            DAT_004A2A7C = 1;
            DAT_004A2A74 = 1;
            FUN_0041A360(0x44, 0xff);
            DAT_00455C08 = (unsigned char)DAT_004A291C;
            DAT_00455C0C = (unsigned char)DAT_004A2918;
            if (DAT_00462C70 != 0) {
                FUN_004099B0(1);
            }
            DAT_00455C10 = (unsigned char)DAT_004A2920;
            return;
        }
        if (DAT_004A0282 != 0) {
            FUN_0040CA70(param_1, (int*)param_1[0x28]);
            FUN_0040CCA0(param_1);
            FUN_0041A360(0x45, 0xff);
            DAT_00462C68 = 0xd2;
            return;
        }
        if (DAT_004A0283 != 0) {
            FUN_0040CA70(param_1, (int*)param_1[0x29]);
            FUN_0040CCA0(param_1);
            FUN_0041A360(0x45, 0xff);
            DAT_00462C68 = 0xd2;
            return;
        }
        pGVar2 = param_1[0x2b];
        if (pGVar2 == (int*)1) {
            if (DAT_004A028F != 0 || DAT_004A0281 != 0) {
                ppGVar4 = (int**)FUN_0040C110(0x7b, (int)pGVar5);
                pGVar5 = ppGVar4[0x2c];
                ppGVar4[0x2c] = 0;
                if (pGVar5 == 0) {
                    ppGVar4[0x2c] = (int*)1;
                }
                FUN_0041A360(0x42, 0xff);
                if (ppGVar4[0x26] == (int*)2) {
                    DAT_004A291C = (int)(ppGVar4[0x2c] == (int*)1);
                } else if (ppGVar4[0x26] == (int*)6) {
                    DAT_004A2918 = (int)(ppGVar4[0x2c] != (int*)1);
                    if (ppGVar4[0x2c] != (int*)1) {
                        DAT_004A2918 = 0;
                    }
                }
                if (ppGVar4[0x26] == (int*)4) {
                    if (ppGVar4[0x2c] != (int*)1) {
                        DAT_004A2920 = 0;
                        return;
                    }
                    FUN_0040C110(0x7b, 8);
                    DAT_004A2920 = 1;
                    return;
                }
            }
        } else if (pGVar2 == (int*)2) {
            if (DAT_004A028F == 0) {
                if (DAT_004A0281 == 0) {
                    if (DAT_004A0294 == 0) return;
                    ppGVar4 = (int**)FUN_0040C110(0x7b, 8);
                    bVar1 = 0; 
                    if (DAT_0045601C != 0) return;
                    if (DAT_00456020 != 0) FUN_00402F70();
                    FUN_00402E70((int)bVar1);
                    DAT_00462C70 = 1;
                    DAT_0045601C = 0;
                    return;
                }
                iVar3 = 1;
            } else {
                iVar3 = -1;
            }
            ppGVar4 = (int**)FUN_0040C110(0x7b, (int)pGVar5);
            pGVar5 = (int*)(*(int*)((int)ppGVar4[0x2c] + 0x78) + iVar3 + -0x1c);
            ppGVar4[0x2c] = pGVar5;
            if ((int)pGVar5 < 0) {
                ppGVar4[0x2c] = (int*)0x13;
            } else if ((int)pGVar5 > 0x13) {
                ppGVar4[0x2c] = 0;
            }
            FUN_0041A360(0x45, 0xff);
            return;
        } else if (pGVar2 != (int*)5 && pGVar2 == (int*)3) {
            if (DAT_004A0293 == 0 && DAT_004A0294 == 0 && DAT_004A0295 == 0 &&
                DAT_004A028C == 0 && DAT_004A0280 == 0 && DAT_004A0288 == 0 &&
                DAT_004A028B == 0 && DAT_004A0292 == 0) return;
            buttonNumber = (unsigned char*)&DAT_0045622C;
            FUN_0040CA70(param_1, (int*)buttonNumber);
            FUN_0041A360(0x45, 0xff);
            return;
        }
    }
}
}
