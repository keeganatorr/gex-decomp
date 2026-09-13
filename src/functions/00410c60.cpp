// Adapted from pc_decomp_backup/src/functions/FUN_00410C60.cpp
// Historical source SHA256: 097350070450f6dac0bcd99aeb9d03599bd1472cf94ba5f41ae45dbb3c399bcc
extern "C" {
extern "C" { extern int DAT_004A2940; }
extern void* DAT_004A2990;
extern "C" { extern int DAT_004A2A1C; }
extern "C" { extern int DAT_004A2A2C; }
extern "C" { extern int DAT_004A2A38; }
extern "C" { extern int DAT_004A2A90; }
extern "C" { extern int DAT_004A2A9C; }

extern "C" void __cdecl GEX_Target()
{
    int iVar1;

    DAT_004A2A9C = DAT_004A2A38;
    DAT_004A2A38 = DAT_004A2A38 + DAT_004A2A90;
    DAT_004A2A2C = DAT_004A2A1C;
    DAT_004A2A1C = DAT_004A2A1C + DAT_004A2940;
    if (DAT_004A2A38 < 0) {
        DAT_004A2A38 = 0;
    }
    if (DAT_004A2A1C < 0) {
        DAT_004A2A1C = 0;
    }
    iVar1 = *(int*)(*(int*)((int)DAT_004A2990 + 4) + 4);
    if (iVar1 - 0x1400000 <= DAT_004A2A38) {
        DAT_004A2A38 = iVar1 - 0x1410000;
    }
    iVar1 = *(int*)(*(int*)((int)DAT_004A2990 + 4) + 8);
    if (iVar1 - 0xf00000 <= DAT_004A2A1C) {
        DAT_004A2A1C = iVar1 - 0xf10000;
    }
}
}
