// Adapted from pc_decomp_backup/src/functions/FUN_00446430.cpp
// Historical source SHA256: 235af694ff80ded8aecaa9eb6c06d8e59a344822bdb144b1840a603355c89bf4
extern "C" {
extern "C" { extern int DAT_00450008; }
extern "C" { extern int DAT_0045000C; }
extern "C" { extern int DAT_00450010; }
extern "C" { extern int DAT_00450014; }
extern "C" { extern int DAT_00450018; }
extern "C" { extern int DAT_0045001C; }
extern "C" { extern int DAT_004A2B24; }
extern "C" { extern unsigned int DAT_004A2F58; }
extern "C" { extern unsigned int DAT_004A2F5C; }
extern "C" { extern int DAT_004A2F60; }
extern "C" { extern int DAT_004A2F64; }
extern "C" { extern int DAT_004A2F78; }
extern "C" { extern int DAT_004A2F88; }
extern "C" { extern unsigned int DAT_004A2F8C; }
extern "C" { extern unsigned short* DAT_004A33AC; }

extern "C" void __cdecl GEX_Target(void* param_1)
{
    unsigned int uVar3;
    int iVar6;
    unsigned int* ppvBits2;
    unsigned int* ppvBits;
    unsigned int uVar4;
    unsigned int uVar5;

    DAT_004A2F58 = (unsigned int)((unsigned char*)param_1)[0x0c];
    DAT_004A2F5C = (unsigned int)((unsigned char*)param_1)[0x0d];
    DAT_004A2F60 = (int)((short*)((unsigned char*)param_1 + 8))[0];
    DAT_004A2F64 = (int)((short*)((unsigned char*)param_1 + 0xa))[0];
    DAT_004A2F8C = (unsigned int)((short*)((unsigned char*)param_1 + 0x10))[0];
    DAT_004A2F88 = (int)((short*)((unsigned char*)param_1 + 0x12))[0];

    if (((int)DAT_004A2F8C > 0) && (DAT_004A2F88 > 0) && (DAT_004A2F60 < 0x140)) {
        if (DAT_004A2F60 < 0) {
            uVar3 = DAT_004A2F60 + DAT_004A2F8C;
            if ((int)uVar3 < 1) {
                return;
            }
            DAT_004A2F60 = DAT_004A2F60 + (int)(DAT_004A2F8C - uVar3);
            DAT_004A2F58 = DAT_004A2F58 + (DAT_004A2F8C - uVar3);
            DAT_004A2F8C = uVar3;
            if (0x140 < (int)uVar3) {
                DAT_004A2F8C = 0x140;
            }
        }
        else if (0x13f < DAT_004A2F60 + (int)DAT_004A2F8C) {
            DAT_004A2F8C = DAT_004A2F8C - ((DAT_004A2F60 + (int)DAT_004A2F8C) - 0x140);
        }

        if (DAT_004A2F64 < 0xe8) {
            if (DAT_004A2F64 < 8) {
                iVar6 = DAT_004A2F64 + DAT_004A2F88 + -8;
                if ((iVar6 == 0) || (DAT_004A2F64 + DAT_004A2F88 < 8)) {
                    return;
                }
                DAT_004A2F64 = DAT_004A2F64 + (DAT_004A2F88 - iVar6);
                DAT_004A2F5C = DAT_004A2F5C + (DAT_004A2F88 - iVar6);
                DAT_004A2F88 = iVar6;
                if (0xe0 < iVar6) {
                    DAT_004A2F88 = 0xe0;
                }
            }
            else if (0xe7 < (unsigned int)(DAT_004A2F64 + DAT_004A2F88)) {
                DAT_004A2F88 = DAT_004A2F88 - ((DAT_004A2F64 + DAT_004A2F88) - 0xe8);
            }

            DAT_004A2B24 = (int)DAT_004A2F8C * -2 + 0x800;
            ppvBits = (unsigned int*)(DAT_004A2F64 * 0x800 + DAT_004A2F60 * 2 + (int)DAT_004A33AC);
            {
                unsigned int* piVar7 = (unsigned int*)(DAT_004A2F5C * 0x800 + (int)DAT_004A2F78 + DAT_004A2F58 * 2);
                unsigned int uVar3_local = DAT_004A2F8C;
                do {
                    while (3 < uVar3_local) {
                        unsigned int iVar6_v = *piVar7;
                        unsigned int uVar5_v = piVar7[1];
                        piVar7 += 2;
                        uVar4 = uVar3_local - 4;
                        {
                            unsigned short sVar2 = (unsigned short)iVar6_v;
                            unsigned int uVar3_v = sVar2;
                            if (uVar3_v != 0) {
                                if ((int)uVar3_v < 0) {
                                    sVar2 = ((unsigned short)(uVar3_v >> 1) & 0x3def) + (unsigned short)((*ppvBits & 0x7bde) >> 1);
                                }
                                *(unsigned short*)ppvBits = sVar2;
                            }
                            uVar3_v = iVar6_v >> 0x10;
                            if (uVar3_v != 0) {
                                if ((int)uVar3_v < 0) {
                                    uVar3_v = (uVar3_v >> 1 & 0x3def) + ((*(unsigned int*)((int)ppvBits + 2) & 0x7bde) >> 1);
                                }
                                *(unsigned short*)((int)ppvBits + 2) = (unsigned short)uVar3_v;
                            }
                            if ((unsigned short)uVar5_v != 0) {
                                unsigned int uVar3_w = uVar5_v;
                                if ((short)uVar5_v < 0) {
                                    uVar3_w = (uVar5_v >> 1 & 0x3def) + ((ppvBits[1] & 0x7bde) >> 1);
                                }
                                *(unsigned short*)(ppvBits + 1) = (unsigned short)uVar3_w;
                            }
                            uVar5_v = (int)uVar5_v >> 0x10;
                            ppvBits = ppvBits + 2;
                            uVar3_local = uVar4;
                            if (uVar5_v != 0) {
                                if ((int)uVar5_v < 0) {
                                    uVar5_v = (uVar5_v >> 1 & 0x3def) + ((*(unsigned int*)((int)ppvBits + 6 - 8) & 0x7bde) >> 1);
                                }
                                *(unsigned short*)((int)ppvBits + 6 - 8) = (unsigned short)uVar5_v;
                            }
                        }
                    }
                    for (; uVar3_local != 0; uVar3_local--) {
                        unsigned int uVar4_w = (int)*(int*)((int)piVar7 - 2) >> 0x10;
                        piVar7 = (unsigned int*)((int)piVar7 + 2);
                        if (uVar4_w != 0) {
                            if ((int)uVar4_w < 0) {
                                uVar4_w = (uVar4_w >> 1 & 0x3def) + ((*ppvBits & 0x7bde) >> 1);
                            }
                            *(unsigned short*)ppvBits = (unsigned short)uVar4_w;
                        }
                        ppvBits = (unsigned int*)((int)ppvBits + 2);
                    }
                    piVar7 = (unsigned int*)((int)piVar7 + DAT_004A2B24);
                    DAT_004A2F88--;
                    ppvBits = (unsigned int*)((int)ppvBits + DAT_004A2B24);
                    uVar3_local = DAT_004A2F8C;
                } while (DAT_004A2F88 != 0);
            }
        }
    }
}
}
