// Adapted from pc_decomp_backup/src/functions/FUN_0043E800.cpp
// Historical source SHA256: c25720243dad74ba0ab6f31d5b7e63c0e70b875a95a2f5a992a91ba0e938bb26
extern "C" {
struct M1TileTable {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

extern "C" { extern M1TileTable* PTR_004a2ae4; }
extern "C" { extern M1TileTable* DAT_004a2adc_Tiles2; }
extern "C" { extern M1TileTable* DAT_004a2ae0_TilesBack1; }
extern "C" { extern int* PTR_004a2b1c; }

extern "C" void __cdecl GEX_Target(int param_1, short* param_2, int param_3, int param_4)
{
    short* psVar1;
    int iVar2;
    unsigned char bVar3;
    M1TileTable* pMVar4;
    M1TileTable* pMVar5;
    unsigned char bVar6;

    pMVar4 = PTR_004a2ae4 + 1;
    pMVar5 = PTR_004a2ae4;
    PTR_004a2ae4 = pMVar4;
    if (DAT_004a2adc_Tiles2 < pMVar4) {
        pMVar5 = DAT_004a2ae0_TilesBack1;
        PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 1;
    }
    *PTR_004a2b1c = (int)pMVar5;
    iVar2 = *PTR_004a2b1c;
    psVar1 = (short*)(iVar2 + 4);
    bVar6 = (unsigned char)((unsigned char)param_2[1] + 7U) & 0xf8;
    PTR_004a2b1c = (int*)iVar2;
    *(int*)(psVar1) = *(int*)(param_1 + 0xc);
    bVar3 = *(unsigned char*)((int)param_2 + 3);
    *(unsigned short*)(iVar2 + 10) = (unsigned short)bVar3;
    if (bVar3 < 0x20) {
        *(short*)(iVar2 + 6) = *(short*)(iVar2 + 6) + 1;
    }
    *(char*)(param_1 + 0x13) = *(char*)(iVar2 + 6);
    if (param_4 == 1) {
        *(unsigned short*)(iVar2 + 8) = (unsigned short)(bVar6 >> 1);
        if (bVar6 < 0x20) {
            *psVar1 = *psVar1 + 1;
        }
        bVar3 = ((unsigned char)*psVar1 & 0x3f) * 2;
    } else if (param_4 == 2) {
        *(unsigned short*)(iVar2 + 8) = (unsigned short)bVar6;
        if (bVar6 < 0xe) {
            *psVar1 = *psVar1 + 2;
        }
        bVar3 = (unsigned char)*psVar1 & 0x3f;
    } else {
        *(unsigned short*)(iVar2 + 8) = (unsigned short)(bVar6 >> 2);
        if (bVar6 < 0x40) {
            *psVar1 = *psVar1 + 1;
        }
        bVar3 = (char)*psVar1 << 2;
    }
    *(unsigned char*)(param_1 + 0x12) = bVar3;
    *(unsigned short*)(param_1 + 0x10) =
         (unsigned short)(*(unsigned int*)(param_1 + 0xc) >> 0x14) & 0x10 |
         (unsigned short)(*(unsigned int*)(param_1 + 0xc) >> 6) & 0xf | (short)param_4 << 7;
    *(int*)(iVar2 + 0xc) = *param_2 + (int)param_3;
}
}
