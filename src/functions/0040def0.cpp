// Adapted from pc_decomp_backup/src/functions/FUN_0040DEF0.cpp
// Historical source SHA256: 2a0404fa4aaf6d5d7125199f5a011acd3e23903b246d138c325d2edd7ec72161
extern "C" {
extern "C" { extern unsigned char DAT_00455C34; }
extern "C" { extern unsigned char DAT_00455C1C; }
extern "C" { extern unsigned char DAT_00455C3C; }
extern "C" { extern unsigned char DAT_00456338; }
extern "C" { extern unsigned char DAT_0045633C; }
extern "C" { extern unsigned char DAT_00456340; }
extern "C" { extern unsigned char DAT_0045A17D; }
extern "C" { extern unsigned char DAT_0045A17E; }
extern "C" { extern unsigned char DAT_0045ACC4; }
extern "C" { extern int DAT_00455B38; }
extern "C" { extern int DAT_00455C08; }
extern "C" { extern int DAT_00455C0C; }
extern "C" { extern int DAT_00455C10; }
extern "C" { extern int DAT_00462C7C; }
extern "C" { extern int DAT_00462C80; }
extern "C" { extern int DAT_004A026C; }
extern "C" { extern int DAT_004A2AC8; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern unsigned char DAT_004A0284; }
extern "C" { extern unsigned char DAT_004A0285; }
extern "C" { extern unsigned char DAT_004A0286; }

extern "C" int __cdecl FUN_00402F70(int**);
extern "C" int __cdecl FUN_00404F70(int**, int, int);
extern "C" int __cdecl FUN_004098D0(int**, int, int, int);
extern "C" int __cdecl FUN_004099B0(int);
extern "C" int __cdecl FUN_0040B9F0(int**, int);
extern "C" int** __cdecl FUN_0040C110(int, int);
extern "C" int __cdecl FUN_0040C1A0(int, int);
extern "C" void __cdecl FUN_0040E2F0(int**);
extern "C" void __cdecl FUN_0040E3F0(int**);
extern "C" void __cdecl FUN_0040E520(void);
extern "C" void __cdecl FUN_0041A360(int, int);
extern "C" int __cdecl FUN_00429940(int**, int);
extern "C" { extern int DAT_00463068; }

extern "C" void __cdecl GEX_Target(int** param_1)
{
    int iVar2;
    int** ppGVar3;
    unsigned int uVar4;
    int* pGVar1;
    
    if (DAT_0045633C == 0) {
        FUN_0040E520();
        pGVar1 = param_1[0x1c];
        if (pGVar1 == 0) {
            if ((int)((int)param_1[0x2d] + 3) <= DAT_004A2AC8) {
                param_1[0x27] = (int*)0x12c0000;
                param_1[0x28] = (int*)0xf00000;
                param_1[0x2a] = (int*)0xfe0000;
                param_1[0x23] = (int*)0xc90000;
                param_1[0x25] = 0;
                param_1[0x20] = (int*)0x10000;
                param_1[0x1c] = (int*)1;
            }
        } else if (pGVar1 == (int*)1) {
            FUN_0040E3F0(param_1);
            if ((int)((int)param_1[0x2d] + 5) <= DAT_004A2AC8) {
                param_1[0x1c] = (int*)((int)param_1[0x1c] + 1);
            }
        } else if (pGVar1 == (int*)2) {
            FUN_0040E3F0(param_1);
            FUN_0040E2F0(param_1);
        }
        if (DAT_00455C1C != 0 && DAT_004A0286 != 0) {
            DAT_00455C3C = 0;
        }
        if (DAT_004A0284 == 0) {
            uVar4 = (unsigned int)(DAT_004A0285 == 0) - 1 & 0x20;
        } else {
            uVar4 = 0x10;
        }
        if (param_1[0x2c] != 0 && uVar4 != 0) {
            pGVar1 = (int*)FUN_0040C1A0((int)param_1[0x2c], uVar4 | 4);
            param_1[0x2c] = pGVar1;
            FUN_0040C1A0((int)pGVar1, 10);
            FUN_0041A360(0x45, 0xff);
        }
        if (1 == 0) { 
        }
        
        if (DAT_004A0284 == 0 && DAT_00455C34 != 0x0d) {
            if (DAT_004A0282 != 0) {
                if (DAT_00455C1C != 0) {
                    if (DAT_00455C34 == 0) {
                        DAT_00455C08 = DAT_00455C08 + -1;
                    } else if (DAT_00455C34 == 0x1b) {
                        DAT_00455C3C = 0;
                    }
                }
            } else if (DAT_004A0283 != 0) {
                DAT_00455C08 = DAT_00455C08 + 1;
            } else if (DAT_004A0281 != 0) {
                if (DAT_00455C34 == 0) {
                    DAT_00455C08 = DAT_00455C08 + -1;
                }
            } else if (DAT_004A0280 != 0 && DAT_00455C34 != 0) {
                FUN_004098D0(param_1, DAT_00455C34, DAT_00455C08, DAT_00462C7C);
                FUN_0040B9F0(param_1, DAT_00462C7C);
                if (DAT_00462C7C == 0 && DAT_00462C80 == 0) {
                    FUN_004099B0(0);
                }
                if (DAT_00463068 == 0) {
                    FUN_0040B9F0(param_1, DAT_00462C7C);
                    if (DAT_00462C7C == 0 && DAT_00462C80 == 0) {
                        FUN_004099B0(0);
                    }
                }
                DAT_00462C7C = 0;
            }
        }
    }
}
}
