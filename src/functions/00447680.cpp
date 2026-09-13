// Adapted from pc_decomp_backup/src/functions/FUN_00447680.cpp
// Historical source SHA256: 4428362a6fbb5d0048d84c27a0ad4521e3f38638f7a3950c863a8af74b2ade43
extern "C" {
extern unsigned short *DAT_004a2f54_ppvBitsUnk;
extern int FUN_004A33AC;
extern int DAT_004a2f6c_DrawTilesTileHolder;
extern int DAT_004a2f78_TileRelated;

extern "C" void __cdecl GEX_Target(int param_1, int param_2, int param_3, unsigned int param_4, int param_5, int param_6, unsigned int param_7, int param_8)
{
    unsigned short uVar1;
    int iVar2, iVar3, iVar4, iVar5, iVar6;

    iVar2 = param_2 >> 0x10;
    if (iVar2 > 0) {
        iVar5 = param_1 >> 0x10;
        if (iVar5 < 0x140) {
            iVar6 = (param_2 - param_1) >> 0x10;
            if (iVar6 != 0) {
                iVar3 = (param_5 - param_3) / iVar6;
                iVar4 = (int)(param_6 - param_4) / iVar6;
                if (iVar5 < 0) {
                    param_3 = param_3 + (-iVar5) * iVar3;
                    param_4 = param_4 + (-iVar5) * iVar4;
                    iVar6 = iVar6 + iVar5;
                    iVar5 = (int)(param_7 & 0xffff001f) >> 5;
                } else {
                    iVar5 = ((int)(param_7 & 0xffff001f) >> 5) + iVar5 * 2;
                }
                DAT_004a2f54_ppvBitsUnk = (unsigned short *)(iVar5 + (int)FUN_004A33AC);
                if (iVar2 > 0x13f) {
                    iVar6 = iVar6 + (0x13f - iVar2);
                }
                if (param_8 == 0) {
                    iVar6 = iVar6 + 1;
                    if (iVar6 > 0) {
                        do {
                            unsigned char tileIndex = *(unsigned char *)(((int)(param_4 & 0xffff001f) >> 5) + (param_3 >> 0x10) + DAT_004a2f78_TileRelated);
                            uVar1 = *(unsigned short *)(DAT_004a2f6c_DrawTilesTileHolder + (unsigned int)tileIndex * 2);
                            if (uVar1 != 0) {
                                *DAT_004a2f54_ppvBitsUnk = uVar1;
                            }
                            DAT_004a2f54_ppvBitsUnk = DAT_004a2f54_ppvBitsUnk + 1;
                            param_3 = param_3 + iVar3;
                            param_4 = param_4 + iVar4;
                            iVar6 = iVar6 - 1;
                        } while (iVar6 != 0);
                    }
                } else {
                    iVar6 = iVar6 + 1;
                    if (iVar6 > 0) {
                        do {
                            unsigned char tileIndex = *(unsigned char *)(((int)(param_4 & 0xffff001f) >> 5) + (param_3 >> 0x10) + DAT_004a2f78_TileRelated);
                            uVar1 = *(unsigned short *)(DAT_004a2f6c_DrawTilesTileHolder + (unsigned int)tileIndex * 2);
                            if (uVar1 != 0) {
                                if (uVar1 < 0x8000) {
                                    *DAT_004a2f54_ppvBitsUnk = uVar1;
                                } else {
                                    *DAT_004a2f54_ppvBitsUnk = ((*DAT_004a2f54_ppvBitsUnk & 0x7bde) >> 1) + ((uVar1 & 0x7bde) >> 1);
                                }
                            }
                            DAT_004a2f54_ppvBitsUnk = DAT_004a2f54_ppvBitsUnk + 1;
                            param_3 = param_3 + iVar3;
                            param_4 = param_4 + iVar4;
                            iVar6 = iVar6 - 1;
                        } while (iVar6 != 0);
                    }
                }
            }
        }
    }
}
}
