// Adapted from pc_decomp_backup/src/functions/FUN_004457B0.cpp
// Historical source SHA256: e4171b486ac8c4d748cbb552dcd01da07032b6cf0d91c81d39e12369302f86be
extern "C" {
extern "C" { extern int DAT_004A2B24; }
extern "C" { extern int DAT_004A2B30; }
extern "C" { extern unsigned int DAT_004A2F58; }
extern "C" { extern unsigned int DAT_004A2F5C; }
extern "C" { extern int DAT_004A2F60; }
extern "C" { extern int DAT_004A2F64; }
extern "C" { extern void* DAT_004A2F6C; }
extern "C" { extern int DAT_004A2F78; }
extern "C" { extern int DAT_004A2F88; }
extern "C" { extern unsigned int DAT_004A2F8C; }
extern "C" { extern unsigned short* DAT_004A33AC; }

extern "C" void* __cdecl FUN_00402400(unsigned char, unsigned char, unsigned char, unsigned int, int);

extern "C" void __cdecl FUN_004457b0_DrawTilesInner2(void* param_1)
{
    DAT_004A2F58 = (unsigned int)*(unsigned char*)((int)param_1 + 0xc);
    DAT_004A2F5C = (unsigned int)*(unsigned char*)((int)param_1 + 0xd);
    DAT_004A2F60 = (int)*(short*)((int)param_1 + 0x8);
    DAT_004A2F64 = (int)*(short*)((int)param_1 + 0xa);
    DAT_004A2F8C = (unsigned int)*(short*)((int)param_1 + 0x10);
    DAT_004A2F88 = (int)*(short*)((int)param_1 + 0x12);
    
    void* puVar5 = FUN_00402400(
        *(unsigned char*)((int)param_1 + 0x4),
        *(unsigned char*)((int)param_1 + 0x5),
        *(unsigned char*)((int)param_1 + 0x6),
        (unsigned int)*(unsigned short*)((int)param_1 + 0xe),
        0x100);
    DAT_004A2F6C = puVar5;
    
    if ((DAT_004A2F8C > 0) && (DAT_004A2F88 > 0) && (DAT_004A2F60 < 0x140)) {
        if (DAT_004A2F60 < 0) {
            unsigned int uVar6 = DAT_004A2F60 + DAT_004A2F8C;
            if ((int)uVar6 < 1) return;
            DAT_004A2F60 = DAT_004A2F60 + (int)(DAT_004A2F8C - uVar6);
            DAT_004A2F58 = DAT_004A2F58 + (DAT_004A2F8C - uVar6);
            DAT_004A2F8C = uVar6;
            if (uVar6 > 0x140) DAT_004A2F8C = 0x140;
        } else if (DAT_004A2F60 + (int)DAT_004A2F8C > 0x13f) {
            DAT_004A2F8C = DAT_004A2F8C - ((DAT_004A2F60 + (int)DAT_004A2F8C) - 0x140);
        }
        
        if (DAT_004A2F64 < 0xe8) {
            if (DAT_004A2F64 < 8) {
                int iVar7 = DAT_004A2F64 + DAT_004A2F88 - 8;
                if (iVar7 == 0 || DAT_004A2F64 + DAT_004A2F88 < 8) return;
                DAT_004A2F64 = DAT_004A2F64 + (DAT_004A2F88 - iVar7);
                DAT_004A2F5C = DAT_004A2F5C + (DAT_004A2F88 - iVar7);
                DAT_004A2F88 = iVar7;
                if (iVar7 > 0xe0) DAT_004A2F88 = 0xe0;
            } else if ((unsigned int)(DAT_004A2F64 + DAT_004A2F88) > 0xe7) {
                DAT_004A2F88 = DAT_004A2F88 - ((DAT_004A2F64 + DAT_004A2F88) - 0xe8);
            }
            DAT_004A2B30 = 0x800 - (int)DAT_004A2F8C;
            DAT_004A2B24 = (int)DAT_004A2F8C * -2 + 0x800;
            
            unsigned char* pbVar8 = (unsigned char*)(DAT_004A2F5C * 0x800 + DAT_004A2F78 + DAT_004A2F58);
            unsigned short* puVar10 = (unsigned short*)(DAT_004A2F64 * 0x800 + DAT_004A2F60 * 2 + (int)DAT_004A33AC);
            unsigned int uVar6 = DAT_004A2F8C;
            
            do {
                while (uVar6 > 1) {
                    unsigned int uVar3 = uVar6 - 2;
                    unsigned char bVar1 = *pbVar8;
                    unsigned char* pbVar9 = pbVar8 + 1;
                    pbVar8 = pbVar8 + 2;
                    uVar6 = *(unsigned int*)((int)puVar5 + (unsigned int)bVar1 * 2 - 2);
                    unsigned int uVar2 = *(unsigned int*)((int)puVar5 + (unsigned int)*pbVar9 * 2 - 2);
                    if (uVar6 >> 16 != 0) *puVar10 = (unsigned short)(uVar6 >> 16);
                    unsigned short* puVar4 = puVar10 + 2;
                    uVar6 = uVar3;
                    if (uVar2 >> 16 != 0) puVar10[1] = (unsigned short)(uVar2 >> 16);
                    puVar10 = puVar4;
                }
                // The pinned loop uses the carry from subtracting two: only
                // an odd pixel count reaches this single-pixel tail.
                if (uVar6 != 0) {
                    uVar6 = *(unsigned int*)((int)puVar5 + (unsigned int)*pbVar8 * 2 - 2);
                    if (uVar6 >> 16 != 0) *puVar10 = (unsigned short)(uVar6 >> 16);
                    pbVar8++;
                    puVar10++;
                }
                pbVar8 = pbVar8 + DAT_004A2B30;
                DAT_004A2F88--;
                puVar10 = (unsigned short*)((int)puVar10 + DAT_004A2B24);
                uVar6 = DAT_004A2F8C;
            } while (DAT_004A2F88 != 0);
        }
    }
}
}
