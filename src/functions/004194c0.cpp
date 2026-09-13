// Adapted from pc_decomp_backup/src/functions/FUN_004194C0.cpp
// Historical source SHA256: 21577cc378e1ad5a3d9c3eab3d80820b79cb9bdaa3d04798ad383d60a3ec2d54
extern "C" {
extern "C" void __cdecl FUN_0042CC50(void**);
extern "C" void* __cdecl FUN_004096C0(int size);
extern "C" void __cdecl FUN_0042CC00(void**, void**);

extern "C" { extern void* FUN_004A27B0; }
extern "C" { extern void* FUN_004A27A0; }
extern "C" { extern void* FUN_004A28A0; }
extern "C" { extern void* DAT_004a2918_LevelObjectsListEnd; }

extern "C" void __cdecl GEX_Target()
{
    int objectCount = 100;
    FUN_0042CC50((void**)&FUN_004A27B0);
    FUN_004A27A0 = FUN_004096C0(0xc990);
    int* freeMemory = (int*)FUN_004A27A0;
    do {
        FUN_0042CC00((void**)&FUN_004A27B0, (void**)freeMemory);
        objectCount--;
        freeMemory = freeMemory + 0x81;
    } while (objectCount != 0);
    void*** gOb_Ptr = (void***)&FUN_004A28A0;
    do {
        FUN_0042CC50((void**)gOb_Ptr);
        gOb_Ptr = gOb_Ptr + 3;
    } while (gOb_Ptr < (void***)&DAT_004a2918_LevelObjectsListEnd);
}
}
