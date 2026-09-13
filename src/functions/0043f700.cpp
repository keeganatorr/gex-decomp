// Adapted from pc_decomp_backup/src/functions/FUN_0043F700.cpp
// Historical source SHA256: 4780aa9463da95768681b164206e33fdcd76e76e64317c4fe139eb5869c68898
extern "C" {
extern "C" void* __cdecl FUN_00409630(void*, int);
extern "C" void __cdecl FUN_004451e0_LEV_SetUpDrawCacheWithFileData(void*, void*);
extern "C" void __cdecl FUN_0043eb50_LoadTilePoss(void*, int);
extern "C" { extern void* DAT_004a2af4; }
extern "C" { extern int DAT_0046a664; }
extern "C" { extern int DAT_0046a668; }
extern "C" { extern int DAT_0046a66c; }
extern "C" void __cdecl GEX_Target(void* LoadedLevel, void* idl_file_handle, int LEV) {
    char* ll = (char*)LoadedLevel;
    ll[8] = 0x20;
    ll[9] = 0x7f;
    *(int*)(ll + 0x10) = -1;
    void* fileMemory = FUN_00409630(idl_file_handle, LEV);
    *(void**)(ll + 4) = fileMemory;
    *(void**)(ll + 0) = (void*)((int)fileMemory + 4);
    if (DAT_004a2af4 == 0) DAT_004a2af4 = LoadedLevel;
    short dc[8];
    dc[0] = 0x3f0;
    dc[1] = 0x180;
    dc[2] = *(short*)((int)fileMemory + 0x324) >> 2;
    dc[3] = *(short*)((int)fileMemory + 0x326);
    FUN_004451e0_LEV_SetUpDrawCacheWithFileData(dc, (void*)((int)fileMemory + 0x328));
    DAT_0046a664 = (char)dc[0] << 2;
    DAT_0046a668 = (char)dc[1];
    DAT_0046a66c = (short)((dc[0] & 0x3c0) >> 2 | dc[1] & 0x100) >> 4;
    FUN_0043eb50_LoadTilePoss(dc, 1);
}
}
