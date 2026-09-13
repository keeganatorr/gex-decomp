// Adapted from pc_decomp_backup/src/functions/FUN_00411230.cpp
// Historical source SHA256: 85d348173c6db7cc24049f0b2df78006a3ac4525317d1f2eb67521632267c7f7
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int**);
extern "C" { extern void** DAT_004a2864; }
extern "C" int __cdecl GEX_Target(int param1, unsigned int** param2, unsigned int** param3, unsigned int** param4) {
    if (DAT_004a2864 == 0) return 0;
    int iVar2 = FUN_0041CB80(DAT_004a2864, (int**)param2);
    if (iVar2 == 0) return 0;
    *param3 = (unsigned int*)param2[8];
    *param4 = (unsigned int*)param2[8];
    if ((*param2[0] & 2) != 0) {
        unsigned int uVar1 = *param2[8];
        iVar2 = 0;
        if (param2[4] != 0) iVar2 = *(int*)(uVar1 + 8) - 1;
        unsigned int uVar3 = *(unsigned char*)(iVar2 + 0xc + uVar1);
        if (uVar3 != 0) *param3 = (unsigned int*)(*(int*)(uVar1 + 4) + (uVar3 - 1) * 0x10000 + (int)param2[3]);
        iVar2 = 0;
        if (param2[4] == 0) iVar2 = *(int*)(uVar1 + 8) - 1;
        uVar3 = *(unsigned char*)(iVar2 + 0xc + uVar1);
        if (uVar3 != 0) *param4 = (unsigned int*)(*(int*)(uVar1 + 4) + (uVar3 - 1) * 0x10000 + (int)param2[3]);
    }
    return 1;
}
}
