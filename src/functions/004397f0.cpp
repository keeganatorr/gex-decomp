// Adapted from pc_decomp_backup/src/functions/FUN_004397F0.cpp
// Historical source SHA256: a0daff38a67813d2e208b22395c1f0764e507cc3b5220021567987bda7ea4e7b
// Behavior candidate; original bytes are not claimed to match.

extern "C" int* DAT_00464614;
extern "C" int DAT_00464658;
extern "C" int DAT_004646F0;
extern "C" int DAT_004646F8;
extern "C" int DAT_00464520;
extern "C" int DAT_00464524;
extern "C" int DAT_004645AC;
extern "C" int DAT_0046465C;
extern "C" int DAT_00464704;
extern "C" int DAT_0045FF10;
extern "C" int FUN_0045A5C8;
extern "C" int DAT_0045A7C8;
extern "C" int DAT_0045A9C8;
extern "C" int SciFiLevelStrings;
extern "C" int DAT_004645A8;
extern "C" int* FUN_004A27FC;
extern "C" int CAMERA_YPos_004A2A1C;

extern "C" void __cdecl FUN_00439640(int);
extern "C" void __cdecl FUN_00419BC0(int**, int**);
extern "C" void __cdecl FUN_00419BE0(int**, int**);
extern "C" void __cdecl FUN_0041A340(int**, int);

extern "C" int __cdecl FUN_004397f0_HuntDiveInner(void)
{
    int iVar7;
    unsigned int uVar8, uVar9;
    int* pGVar1, *pGVar6;
    int** gexObj = (int**)DAT_00464704;

    FUN_00439640((int)gexObj);
    pGVar1 = (int*)gexObj[0x28];

    if ((int)pGVar1 < 2) {
        if (pGVar1 == (int*)1 && DAT_00464520 % 5 == 0) {
            gexObj[0x15] = (int*)((int)gexObj[0x15] + 1);
            if ((int)gexObj[0x15] > 3) {
                gexObj[0x15] = (int*)4;
                gexObj[0x28] = (int*)2;
                FUN_00419BE0((int**)gexObj, (int**)DAT_00464614);
            }
            return 0;
        }
        if (pGVar1 == 0) {
            FUN_00419BC0((int**)gexObj, (int**)FUN_004A27FC);
            gexObj[0x15] = (int*)1;
            gexObj[0x28] = (int*)1;
            return 0;
        }
    } else {
        DAT_00464658 = DAT_00464658 + DAT_0046465C;
        if (DAT_00464658 < 0x8000) {
            DAT_00464658 = 0x8000;
        }
        if (DAT_004646F0 == 5) {
            CAMERA_YPos_004A2A1C = (int)((int)gexObj[0x1f] + -0x5000);
            if ((int)CAMERA_YPos_004A2A1C > 0x26d00000) {
                CAMERA_YPos_004A2A1C = 0x26d00000;
            }
            if (DAT_00464658 > 0xf0000) {
                DAT_00464658 = 0xf0000;
            }
        }
        iVar7 = DAT_00464658 + DAT_004646F8;
        if (DAT_004646F8 < DAT_00464524 + -0x20000 && DAT_00464524 + -0x20000 <= iVar7) {
            FUN_0041A340((int**)gexObj, 0x13e);
        }
        DAT_004646F8 = iVar7;

        if (DAT_004646F8 < DAT_00464524 + -0x20000) {
            if (DAT_004646F8 < 0xf0000) {
                FUN_0041A340((int**)gexObj, 0x13f);
                gexObj[0x28] = (int*)2;
            } else if (DAT_004646F8 < 0x1e0000) {
                gexObj[0x28] = (int*)3;
            } else if (DAT_004646F8 < 0x2d0000) {
                gexObj[0x28] = (int*)4;
            } else if (DAT_00464524 + -0xf0000 < DAT_004646F8) {
                gexObj[0x28] = (int*)8;
            } else if (DAT_00464524 + -0x1e0000 < DAT_004646F8) {
                gexObj[0x28] = (int*)7;
            } else if (DAT_00464524 + -0x2d0000 < DAT_004646F8) {
                gexObj[0x28] = (int*)6;
            } else {
                gexObj[0x28] = (int*)5;
            }
        } else {
            gexObj[0x28] = (int*)9;
        }

        if (DAT_00464524 >> 1 < DAT_004646F8 && DAT_004646F0 != 5) {
            DAT_0046465C = -0x6000;
        }
        gexObj[0x15] = (int*)(*(int*)((int)&DAT_0045FF10 + (int)gexObj[0x28] * 4));
    }

    // Trig table lookup
    if ((int)DAT_004645A8 < 0) {
        if ((int)DAT_004645A8 < -0x100) {
            unsigned int uV = (unsigned int)(-(int)DAT_004645A8) >> 0x1f;
            int tmp = (((-(int)DAT_004645A8 ^ uV) - uV) & 0xff ^ uV) - uV;
            if (tmp < 0x81) {
                if (tmp < 0x41) {
                    iVar7 = *(int*)((int)&FUN_0045A5C8 + tmp * 4);
                } else {
                    iVar7 = *(int*)((int)&DAT_0045A7C8 + (-tmp) * 4);
                }
            } else if (tmp + -0x80 < 0x41) {
                iVar7 = -*(int*)(SciFiLevelStrings + tmp * 4 + 4);
            } else {
                iVar7 = -*(int*)((int)&DAT_0045A9C8 + (-tmp) * 4);
            }
        } else if ((int)DAT_004645A8 < -0x80) {
            if ((int)(-0x80 - DAT_004645A8) < 0x41) {
                iVar7 = -*(int*)(SciFiLevelStrings + DAT_004645A8 * -4 + 4);
            } else {
                iVar7 = -*(int*)((int)&DAT_0045A9C8 + DAT_004645A8 * 4);
            }
        } else {
            if (-0x41 < (int)DAT_004645A8) {
                iVar7 = *(int*)((int)&FUN_0045A5C8 + DAT_004645A8 * 4);
                iVar7 = -iVar7;
            } else {
                iVar7 = *(int*)((int)&DAT_0045A7C8 + DAT_004645A8 * 4);
            }
        }
    } else if ((int)DAT_004645A8 < 0x101) {
        if (0x80 < (int)DAT_004645A8) {
            if ((int)(DAT_004645A8 - 0x80) < 0x41) {
                iVar7 = *(int*)(SciFiLevelStrings + DAT_004645A8 * 4 + 4);
            } else {
                iVar7 = *(int*)((int)&DAT_0045A9C8 + (-DAT_004645A8) * 4);
            }
            iVar7 = -iVar7;
        } else {
            if ((int)DAT_004645A8 < 0x41) {
                iVar7 = *(int*)((int)&FUN_0045A5C8 + DAT_004645A8 * 4);
            } else {
                iVar7 = *(int*)((int)&DAT_0045A7C8 + (-DAT_004645A8) * 4);
            }
        }
    } else {
        unsigned int uV = (unsigned int)DAT_004645A8 >> 0x1f;
        int tmp = (((DAT_004645A8 ^ uV) - uV) & 0xff ^ uV) - uV;
        if (0x80 < tmp) {
            if (tmp + -0x80 < 0x41) {
                iVar7 = *(int*)(SciFiLevelStrings + tmp * 4 + 4);
            } else {
                iVar7 = *(int*)((int)&DAT_0045A9C8 + (-tmp) * 4);
            }
            iVar7 = -iVar7;
        } else {
            if (tmp < 0x41) {
                iVar7 = *(int*)((int)&FUN_0045A5C8 + tmp * 4);
            } else {
                iVar7 = *(int*)((int)&DAT_0045A7C8 + (-tmp) * 4);
            }
        }
    }
    return 0;
}
