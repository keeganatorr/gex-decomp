// Adapted from pc_decomp_backup/src/functions/FUN_00423CB0.cpp
// Historical source SHA256: 269bd2ce958b39e84a91c60523e175f512fa70c6709641438afd83dcb337f8c4
extern "C" {
extern "C" int __cdecl FUN_00421560(void*, void**);
extern "C" void __cdecl FUN_0041FBC0();
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_00433900(void**);
extern "C" void __cdecl FUN_00424090(void**);

extern "C" { extern int DAT_004A2964; }
extern "C" { extern void* DAT_004A2990; }
extern "C" { extern void* DAT_004A2AD4; }
extern "C" { extern int DAT_004A0260; }

extern "C" void __cdecl PlayerOldMan_00423cb0(void** objectType)
{
    int iVar1;

    if (DAT_004A2964 != 0x44) {
        iVar1 = FUN_00421560(DAT_004A2990, objectType);
        if (iVar1 == 0) {
            FUN_0041FBC0();
            FUN_004250B0(objectType);
            return;
        }
    }
    FUN_00433900(objectType);
    if (objectType[4] == (void*)0) {
        objectType[3] = DAT_004A2AD4;
        if (DAT_004A0260 != 0) {
            DAT_004A0260 = 0;
            FUN_0041FBC0();
        }
        FUN_00424090(objectType);
    }
}
}
