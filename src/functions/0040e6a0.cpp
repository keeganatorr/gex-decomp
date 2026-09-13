// Adapted from pc_decomp_backup/src/functions/FUN_0040E6A0.cpp
// Historical source SHA256: ecdd32456bf639b837139e8e8264fdac2db20ca7744830fe15cc62b5893df91d
extern "C" {
extern "C" { extern unsigned char DAT_00455C08; }
extern "C" { extern unsigned char DAT_00455C0C; }
extern "C" { extern unsigned char DAT_00455C10; }
extern "C" { extern unsigned char DAT_00456338; }
extern "C" { extern unsigned char DAT_0045633C; }
extern "C" { extern unsigned char DAT_00456340; }
extern "C" { extern int DAT_00462C7C; }
extern "C" { extern int DAT_00462C80; }
extern "C" { extern int DAT_00487FD4; }
extern "C" { extern unsigned char DAT_00487FF8; }
extern "C" { extern unsigned char DAT_004A0204; }
extern "C" { extern unsigned char DAT_004A0200; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" { extern unsigned char DAT_004A0283; }
extern "C" { extern unsigned char DAT_004A0284; }
extern "C" { extern unsigned char DAT_004A0285; }
extern "C" { extern unsigned char DAT_004A028F; }
extern "C" { extern int DAT_004A2918; }
extern "C" { extern int DAT_004A291C; }
extern "C" { extern int DAT_004A2920; }
extern "C" { extern int DAT_004A2A7C; }
extern "C" { extern int DAT_004A2AC8; }
extern "C" { extern int DAT_00487FE4; }

extern "C" void __cdecl FUN_004099B0(int);
extern "C" void __cdecl FUN_0040B9F0(void);
extern "C" void __cdecl FUN_0040C340(int**);
extern "C" int** __cdecl FUN_0040C110(int, int);
extern "C" void __cdecl FUN_0041A360(int, int);
extern "C" int __cdecl FUN_004295C0(char*);
extern "C" void __cdecl FUN_00429940(void);

extern "C" void __cdecl GEX_Target(int** param_1)
{
    unsigned char* pbVar1;
    unsigned char bVar5;
    int** ppGVar6;
    int iVar7, iVar8;
    int* pGVar2, *pGVar3, *pGVar4;
    int local_8, local_4;
    unsigned char local_a;
    unsigned char local_9;
    
    pGVar2 = param_1[0x1e];
    pGVar3 = param_1[0x27];
    local_8 = (int)param_1[0x1f];
    local_4 = (int)param_1[0x15];
    param_1[0x15] = (int*)-1;
    
    if (DAT_00462C80 < DAT_004A2AC8) {
        DAT_00456338 = 0;
        
        if (DAT_004A0284 == 0 && DAT_00487FD4 != 0x0d) {
            if (DAT_004A0285 == 0 && DAT_00487FD4 != 0x1b) {
                if (DAT_004A0282 == 0 && DAT_00487FD4 != 0x26) {
                    if (DAT_004A0283 == 0 && DAT_00487FD4 != 0x28) {
                        if (DAT_004A028F == 0 && DAT_00487FD4 != 0x25 && DAT_00487FD4 != 0x08) {
                            if (DAT_004A0281 == 0 && DAT_00487FD4 != 0x27) {
                                if ((0x60 < DAT_00487FD4 && DAT_00487FD4 < 0x6c) || (0x40 < DAT_00487FD4 && DAT_00487FD4 < 0x5b)) {
                                    if (DAT_00487FD4 > 0x5a) {
                                        DAT_00487FD4 = DAT_00487FD4 - 0x20;
                                    }
                                    if (DAT_00462C7C != 7 || *(unsigned char*)((int)&DAT_004A0204 + 3) != (unsigned char)DAT_00487FD4) {
                                        FUN_0041A360(0x45, 0xff);
                                    }
                                    iVar7 = DAT_00462C7C;
                                    *(unsigned char*)((int)&DAT_004A0200 + DAT_00462C7C) = (unsigned char)DAT_00487FD4;
                                    if (iVar7 < 7) {
                                        DAT_00462C7C = iVar7 + 1;
                                    }
                                } else if (DAT_00462C7C < 7) {
                                    DAT_00462C7C = DAT_00462C7C + 1;
                                    FUN_0041A360(0x45, 0xff);
                                }
                            } else if (DAT_00462C7C != 0) {
                                DAT_00462C7C = DAT_00462C7C - 1;
                                FUN_0041A360(0x45, 0xff);
                            }
                        } else {
                            pbVar1 = (unsigned char*)((int)&DAT_004A0200 + DAT_00462C7C);
                            bVar5 = *(unsigned char*)((int)&DAT_004A0200 + DAT_00462C7C) - 1;
                            *pbVar1 = bVar5;
                            if (bVar5 < 0x41) {
                                *pbVar1 = 0x5a;
                            }
                            FUN_0041A360(0x45, 0xff);
                        }
                    } else {
                        pbVar1 = (unsigned char*)((int)&DAT_004A0200 + DAT_00462C7C);
                        bVar5 = *(unsigned char*)((int)&DAT_004A0200 + DAT_00462C7C) + 1;
                        *pbVar1 = bVar5;
                        if (bVar5 > 0x5a) {
                            *pbVar1 = 0x41;
                        }
                        FUN_0041A360(0x45, 0xff);
                    }
                } else {
                    param_1[0x1e] = (int*)0x280000;
                    param_1[0x1f] = (int*)0x500000;
                    param_1[0x27] = (int*)&DAT_004A0200;
                    param_1[0x15] = 0;
                    FUN_0040C340(param_1);
                    param_1[0x18] = (int*)&FUN_0040C340;
                    DAT_0045633C = 0;
                    ppGVar6 = FUN_0040C110(0x7b, 1);
                    ppGVar6[0x2d] = (int*)((unsigned int)ppGVar6[0x2d] & 0xfffffffe);
                    ppGVar6 = FUN_0040C110(0x7b, 2);
                    ppGVar6[0x2d] = (int*)((unsigned int)ppGVar6[0x2d] & 0xfffffffe);
                    ppGVar6 = FUN_0040C110(0x7b, 4);
                    ppGVar6[0x2d] = (int*)((unsigned int)ppGVar6[0x2d] | 1);
                    ppGVar6[0x18] = (int*)&FUN_0040C340;
                    FUN_0041A360(0x44, 0xff);
                    DAT_00487FF8 = 0;
                }
            } else {
                iVar7 = FUN_004295C0((char*)&DAT_004A0200);
                if (iVar7 == 0) {
                    FUN_0041A360(0x76, 0xff);
                    DAT_00456338 = 1;
                    DAT_00462C80 = DAT_004A2AC8 + 0x1e;
                } else {
                    FUN_00429940();
                    DAT_00455C08 = (unsigned char)DAT_004A291C;
                    DAT_00455C0C = (unsigned char)DAT_004A2918;
                    FUN_004099B0(1);
                    DAT_004A2A7C = 1;
                    DAT_00455C10 = (unsigned char)DAT_004A2920;
                    FUN_0040B9F0();
                    DAT_00487FF8 = 0;
                }
            }
        }
    }
    
    pGVar4 = (int*)(int)&DAT_00487FE4;
    if (DAT_00456338 == 0) {
        param_1[0x27] = (int*)&local_a;
        local_9 = 0;
        param_1[0x1e] = (int*)0x280000;
        param_1[0x1f] = (int*)0x500000;
        iVar7 = 0;
        do {
            iVar8 = iVar7 + 1;
            param_1[0x15] = (int*)((DAT_00462C7C == iVar7) - 1);
            local_a = *(unsigned char*)((int)&DAT_004A0200 + iVar7);
            FUN_0040C340(param_1);
            param_1[0x1e] = (int*)((int)param_1[0x1e] + 0x900);
            iVar7 = iVar8;
        } while (iVar8 < 8);
    } else {
        param_1[0x1e] = (int*)0x280000;
        param_1[0x1f] = (int*)0x500000;
        param_1[0x15] = 0;
        param_1[0x27] = pGVar4;
        FUN_0040C340(param_1);
    }
    
    param_1[0x27] = pGVar3;
    param_1[0x1e] = pGVar2;
    param_1[0x1f] = (int*)local_8;
    param_1[0x15] = (int*)local_4;
}
}
