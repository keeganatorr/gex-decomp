// Adapted from pc_decomp_backup/src/functions/FUN_00449500.cpp
// Historical source SHA256: 45e6496909b1a2ad801542c40bbc20b4b5c7fa2fe29d6fd21133acbccd27c278
extern "C" {
extern "C" { extern unsigned short* DAT_004A2F54; }
extern "C" { extern int DAT_004A2F6C; }
extern "C" { extern int DAT_004A2F78; }
extern "C" { extern unsigned short* DAT_004A33AC; }

extern "C" int __cdecl GEX_Target(int param_1, int param_2, unsigned int param_3, unsigned int param_4,
    int param_5, int param_6, unsigned int param_7, int param_8)
{
    int iVar1 = param_2 >> 16;
    if ((iVar1 <= 0) || (int)(param_1 >> 16) >= 0x140) return 0;
    int iVar6 = (param_2 - param_1) >> 16;
    if (iVar6 == 0) return 0;
    int iVar5 = param_1 >> 16;
    int iVar2 = (param_5 - (int)param_3) / iVar6;
    int iVar3 = (param_6 - (int)param_4) / iVar6;
    if (iVar5 < 0) {
        param_3 = (unsigned int)((int)param_3 + iVar2 * -iVar5);
        param_4 = (unsigned int)((int)param_4 + iVar3 * -iVar5);
        iVar6 = iVar6 + iVar5;
        iVar5 = (int)((param_7 & 0xffff001f) >> 5);
    } else {
        iVar5 = (int)((param_7 & 0xffff001f) >> 5) + iVar5 * 2;
    }
    DAT_004A2F54 = (unsigned short*)(iVar5 + (int)DAT_004A33AC);
    if (iVar1 > 0x13f) {
        iVar6 = iVar6 + (0x13f - iVar1);
    }
    if (param_8 == 0) {
        iVar6++;
        while (iVar6 > 0) {
            unsigned short uVar4;
            if ((param_3 & 0x10000) == 0) {
                uVar4 = *(unsigned short*)(DAT_004A2F6C + ((*(unsigned char*)(((int)(param_4 & 0xffff001f) >> 5) + ((int)param_3 >> 17) + DAT_004A2F78) & 0xf) * 2));
            } else {
                int idx = (unsigned int)((*(unsigned char*)(((int)(param_4 & 0xffff001f) >> 5) + ((int)param_3 >> 17) + DAT_004A2F78) & 0xf7) >> 3);
                uVar4 = *(unsigned short*)(idx + DAT_004A2F6C);
            }
            if (uVar4 != 0) *DAT_004A2F54 = uVar4;
            DAT_004A2F54++;
            param_3 = (unsigned int)((int)param_3 + iVar2);
            param_4 = (unsigned int)((int)param_4 + iVar3);
            iVar6--;
        }
    } else {
        iVar6++;
        while (iVar6 > 0) {
            unsigned short uVar4;
            if ((param_3 & 0x10000) == 0) {
                uVar4 = *(unsigned short*)(DAT_004A2F6C + ((*(unsigned char*)(((int)(param_4 & 0xffff001f) >> 5) + ((int)param_3 >> 17) + DAT_004A2F78) & 0xf) * 2));
            } else {
                int idx = (unsigned int)((*(unsigned char*)(((int)(param_4 & 0xffff001f) >> 5) + ((int)param_3 >> 17) + DAT_004A2F78) & 0xf7) >> 3);
                uVar4 = *(unsigned short*)(idx + DAT_004A2F6C);
            }
            if (uVar4 != 0) {
                if (uVar4 > 0x7fff) {
                    uVar4 = ((uVar4 & 0x7bde) >> 1) + ((*DAT_004A2F54 & 0x7bde) >> 1);
                }
                *DAT_004A2F54 = uVar4;
            }
            DAT_004A2F54++;
            param_3 = (unsigned int)((int)param_3 + iVar2);
            param_4 = (unsigned int)((int)param_4 + iVar3);
            iVar6--;
        }
    }
    return 0;
}
}
