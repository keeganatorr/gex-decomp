// Adapted from pc_decomp_backup/src/functions/FUN_00415820.cpp
// Historical source SHA256: e711c4d9b94a7b099dccf7f3e73696166335cf58454a6e4da242527969641e72
// Behavior candidate; original bytes are not claimed to match.

extern "C" int DAT_00455BB4;
extern "C" int DAT_00455BB8;
extern "C" int DAT_00455BBC;
extern "C" int DAT_00455BC0;
extern "C" int DAT_00455BC4;
extern "C" int DAT_00455BC8;
extern "C" int DAT_00455BCC;
extern "C" int DAT_00455BD0;
extern "C" int DAT_00458910;
extern "C" int DAT_00458914;
extern "C" int DAT_00458918;
extern "C" int DAT_0045891C;
extern "C" int DAT_00458920;
extern "C" unsigned char DAT_004A0280;
extern "C" unsigned char DAT_004A0281;
extern "C" unsigned char DAT_004A0282;
extern "C" unsigned char DAT_004A0283;
extern "C" int DAT_004A2990;
extern "C" int DAT_004A2AC8;

extern "C" unsigned int __cdecl FUN_0040F170(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0041A250(int**, int, int, int);
extern "C" void __cdecl FUN_0041A340(int**, int);
extern "C" void __cdecl FUN_0041FA80(int);

extern "C" void __cdecl PlayerGoThruTube_00415820(int** param_1)
{
    int iVar2;
    unsigned int uVar4;
    int* pGVar1;
    int* pGVar5;
    int bVar3;

    DAT_00455BB4 = 0x9f0000;
    bVar3 = 0;
    DAT_00455BB8 = 0xa10000;
    DAT_00455BCC = 0x9f0000;
    DAT_00455BD0 = 0xa10000;
    DAT_00455BC4 = 0x9f0000;
    DAT_00455BC8 = 0xa10000;
    DAT_00455BBC = 0x770000;
    DAT_00455BC0 = 0x790000;
    FUN_0041FA80(0x49);

    if (param_1[0x26] == 0) {
        param_1[0x26] = (int*)1;
        pGVar5 = param_1[0x27];
    } else {
        uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)param_1[0x1e], (unsigned int)param_1[0x1f]);
        switch (uVar4) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
            pGVar5 = (int*)(uVar4 - 0x58);
            break;
        case 0x5c:
        case 0x5d:
        case 0x5e:
        case 0x5f:
            pGVar5 = (int*)(uVar4 - 0x5c);
            if (DAT_004A0280 == 0 || param_1[0x27] == (int*)1) {
                if (DAT_004A0281 == 0 || param_1[0x27] == 0) {
                    if (DAT_004A0282 == 0 || param_1[0x27] == (int*)3) {
                        if (DAT_004A0283 != 0 && param_1[0x27] != (int*)2) {
                            uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)param_1[0x1e], (unsigned int)((int)param_1[0x1f] + 0x1000));
                            if (uVar4 == 0x5b) {
                                pGVar5 = (int*)3;
                            }
                        }
                    } else {
                        uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)param_1[0x1e], (unsigned int)((int)param_1[0x1f] + -0x1000));
                        if (uVar4 == 0x5a) {
                            pGVar5 = (int*)2;
                        }
                    }
                } else {
                    uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] + 0x1000), (unsigned int)param_1[0x1f]);
                    if (uVar4 == 0x59) {
                        pGVar5 = (int*)1;
                    }
                }
            } else {
                uVar4 = FUN_0040F170(DAT_004A2990, (unsigned int)((int)param_1[0x1e] + -0x1000), (unsigned int)param_1[0x1f]);
                if (uVar4 == 0x58) {
                    pGVar5 = (int*)0;
                }
            }
            break;
        case 0x60:
            pGVar5 = param_1[0x27];
            break;
        default:
            FUN_0041A250(param_1, 0xed, 0x80, 0x60);
            pGVar5 = param_1[0x27];
            bVar3 = 1;
            param_1[0x20] = (int*)(DAT_00458910 + (int)pGVar5 * 0x14);
            pGVar1 = (int*)(DAT_00458914 + (int)pGVar5 * 0x14);
            param_1[0x22] = 0;
            param_1[0x1d] = (int*)0x10;
            param_1[0x23] = pGVar1;
            break;
        case 0x74:
        case 0x75:
        case 0x76:
        case 0x77:
            pGVar5 = (int*)(uVar4 - 0x74);
        }
    }

    if ((DAT_004A2AC8 & 7) == 0) {
        FUN_0041A340(param_1, 0xee);
    }

    pGVar1 = param_1[0x27];
    if (pGVar1 != pGVar5) {
        if (((((unsigned int)param_1[0x1e] & 0x1f0000) < 0xc0000) ||
             (0x140000 < ((unsigned int)param_1[0x1e] & 0x1f0000))) ||
            (((unsigned int)param_1[0x1f] & 0x1f0000) < 0xc0000) ||
            (0x140000 < ((unsigned int)param_1[0x1f] & 0x1f0000))) {
            pGVar5 = pGVar1;
        }
    }

    iVar2 = (int)pGVar5 * 0x14;
    param_1[0x1e] = (int*)((int)(*(int**)((int)param_1[0x1e] + 0x78)) + *(int*)((int)&DAT_00458910 + (int)pGVar5 * 0x14) + -0x1c);
    param_1[0x1f] = (int*)((int)(*(int**)((int)param_1[0x1f] + 0x78)) + *(int*)((int)&DAT_00458914 + iVar2) + -0x1c);
    param_1[0x32] = (int*)(DAT_00458918 + iVar2);
    param_1[0x33] = (int*)(DAT_0045891C + iVar2);
    param_1[0x31] = (int*)(DAT_00458920 + iVar2);

    if (pGVar1 == pGVar5) {
        param_1[0x15] = (int*)((int)param_1[0x15] + 1);
    } else {
        param_1[0x15] = (int*)-1;
    }

    param_1[0x27] = pGVar5;
    if (bVar3) {
        param_1[0x31] = 0;
    }
}
