// Adapted from pc_decomp_backup/src/functions/FUN_0043DB70.cpp
// Historical source SHA256: 17b5c06d76fb55f0a6438e58225cecae2f50cee33004fa047bd35f7ebda1d4f4
extern "C" {
extern "C" void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(void*, void*);
extern "C" void __cdecl FUN_00445140_InnerGraphics(void*);
extern "C" { extern int DAT_00464e48; }
extern "C" { extern int DAT_004A2B1C; }
extern "C" { extern int DAT_004A2B18; }
extern "C" { extern int DAT_004A2B14; }
extern "C" { extern unsigned char DAT_0046067C; }
extern "C" { extern int DAT_00467180; }
extern signed char DAT_00467170;
extern "C" { extern int DAT_00460038; }
extern "C" { extern int DAT_00464E3C; }
extern "C" { extern int DAT_00464E40; }
extern "C" { extern int DAT_00467178; }
extern "C" { extern int DAT_0046003C; }
extern "C" { extern int DAT_004A2B20; }
extern "C" void __cdecl GEX_Target(int param1) {
    *(int*)DAT_004A2B1C = 0;
    int local_Draw6 = DAT_00464e48;
    while (local_Draw6 != 0) {
        FUN_004451e0_LEV_SetUpDrawCacheWithFileData((void*)(local_Draw6 + 4), *(void**)(local_Draw6 + 0xc));
        local_Draw6 = *(int*)local_Draw6;
    }
    DAT_00464e48 = 0;
    DAT_004A2B1C = (int)&DAT_00464e48;
    *(int*)DAT_004A2B18 |= 0xffffff;
    *(int*)DAT_004A2B14 |= 0xffffff;
    if (DAT_0046067C != 0) {
        DAT_00460038 = (int)(&DAT_00467180 + (signed char)DAT_00467170);
        if (param1 != 0) FUN_00445140_InnerGraphics((void*)DAT_00460038);
        DAT_00464E3C = DAT_0046003C;
        DAT_00464E40 = (int)(&DAT_00467178 + (signed char)DAT_00467170 * 4);
        DAT_00467170 = DAT_00467170 ^ 1;
    }
    DAT_0046003C = 1;
    DAT_0046067C = 0;
    DAT_004A2B18 = (int)(&DAT_00467178 + (signed char)DAT_00467170 * 4);
    *(int*)DAT_004A2B18 &= 0xffffff;
    DAT_004A2B14 = (int)(&DAT_00467180 + (signed char)DAT_00467170);
    *(int*)DAT_004A2B14 &= 0xffffff;
    DAT_004A2B20 = 0;
}
}
