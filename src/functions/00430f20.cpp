// Adapted from pc_decomp_backup/src/functions/FUN_00430F20.cpp
// Historical source SHA256: 303f895a4427bf0dc5a1ed235599af200c037b6bf9367645aa2784d7c380c292
extern "C" {
extern "C" { extern int DAT_004A2AD4; }
extern "C" int __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419840(void**);
extern "C" void __cdecl FUN_00419BE0(void**, void**);
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" void __cdecl FUN_004339C0(void**);
extern "C" int __cdecl FUN_00449E10(void);
extern "C" void __cdecl FUN_004322A0(int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar2, iVar4;
    void** ppGVar3;
    int local_c, local_8;
    unsigned int local_4;
    unsigned int uVar1, uVar6;

    if (param_1[0x26] == (void*)0x200) {
        uVar1 = FUN_00449E10();
        uVar6 = (int)uVar1 >> 0x1f;
        param_1[0x38] = (void*)((unsigned int)param_1[0x38] | 0x40);
        param_1[0x20] = (void*)((int)param_1[0x20] + (int)param_1[0x22] + -0xc - 4);
        param_1[0x23] = (void*)((int)param_1[0x23] + (int)param_1[0x25] + -0xc - 4);
        param_1[0x1e] = (void*)((int)param_1[0x20] + (int)param_1[0x1e] + -0xc - 4);
        param_1[0x1f] = (void*)((int)param_1[0x23] + (int)param_1[0x1f] + -0xc - 4);
        param_1[0x31] = (void*)(((int)param_1[0x31] + (int)param_1[0x2b] + -0xc) & 0xff0000);

        iVar2 = FUN_00419C00(param_1, 0, ((uVar1 ^ uVar6) - uVar6 & 3 ^ uVar6) - uVar6, &local_8, &local_c);
        if (iVar2 != 0) {
            local_8 = (int)param_1[0x1e] + local_8 + -0x1c;
            local_c = (int)param_1[0x1f] + local_c + -0x1c;
            ppGVar3 = (void**)FUN_004195D0(0x5c, local_8, local_c, DAT_004A2AD4);
            if (ppGVar3 != 0) {
                ppGVar3[0x1b] = (void*)((unsigned int)ppGVar3[0x1b] | 0x8000);
                ppGVar3[0x24] = (void*)0x7fff0000;
                ppGVar3[0x23] = 0;
                ppGVar3[0x25] = (void*)0xa000;
                ppGVar3[0x14] = (void*)0x1b;
                ppGVar3[0x26] = (void*)0x3;
                ppGVar3[0x1c] = (void*)0x30;
                ppGVar3[0x38] = (void*)((unsigned int)ppGVar3[0x38] | 0x40);
                FUN_00419BE0(ppGVar3, param_1);
            }
        }
        if (((0x2a00000 < (int)param_1[0x1f]) || (0x5800000 < (int)param_1[0x1e])) ||
           ((int)param_1[0x1e] < 0xe00000)) {
            FUN_00419840(param_1);
        }
    } else {
        param_1[0x38] = (void*)((unsigned int)param_1[0x38] | 0x40);
        FUN_004339C0(param_1);
        if (param_1[0x2a] != 0) {
            param_1[0x2a] = 0;
            iVar2 = 0;
            do {
                iVar4 = FUN_00419C00(param_1, 0, iVar2, &local_8, &local_c);
                if (iVar4 != 0) {
                    local_8 = (int)param_1[0x1e] + local_8 + -0x1c;
                    local_c = (int)param_1[0x1f] + local_c + -0x1c;
                    ppGVar3 = (void**)FUN_004195D0(0xe8, local_8, local_c, (int)param_1[3]);
                    if (ppGVar3 != 0) {
                        local_4 = FUN_00449E10();
                        uVar1 = (int)local_4 >> 0x1f;
                        ppGVar3[0x14] = (void*)0x3;
                        ppGVar3[0x15] = (void*)(iVar2 + 1);
                        ppGVar3[0x26] = (void*)0x200;
                        if (((local_4 ^ uVar1) - uVar1 & 1 ^ uVar1) == uVar1) {
                            ppGVar3[0x2b] = (void*)((8 - (((local_4 ^ uVar1) - uVar1 & 0xf ^ uVar1) - uVar1)) * 0x10000);
                        } else {
                            ppGVar3[0x2b] = (void*)(((((local_4 ^ uVar1) - uVar1 & 0xf ^ uVar1) - uVar1) + 8) * 0x10000);
                        }
                        ppGVar3[0x25] = (void*)0x10000;
                        uVar1 = (local_c - (int)param_1[0x1f]) + 0x140000;
                        ppGVar3[0x23] = (void*)(((int)local_4 % ((int)uVar1 >> 0x11)) * 0x10000 + ((int)(uVar1 & 0xfffe0001) >> 1));
                        ppGVar3[0x22] = 0;
                        ppGVar3[0x20] = (void*)(((int)local_4 % (local_8 - (int)param_1[0x1e] >> 0x12)) * 0x10000 + ((int)(local_8 - (int)param_1[0x1e] & 0xfffc0003U) >> 2));
                        ppGVar3[0x18] = (void*)&FUN_004322A0;
                        ppGVar3[0x38] = (void*)((unsigned int)ppGVar3[0x38] | 0x40);
                        FUN_00419BE0(ppGVar3, param_1);
                    }
                }
                iVar2 = iVar2 + 1;
            } while (iVar2 < 6);
        }
    }
}
}
