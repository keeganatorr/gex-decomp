// Adapted from pc_decomp_backup/src/functions/FUN_00401DF0.cpp
// Historical source SHA256: 3c45a6d982f3634c8f9491e75cd8e964ec649c08b8f8817bdbc0be788a8a7db2
extern "C" {
extern "C" void __cdecl FUN_0040B860(void**);
extern "C" void __cdecl FUN_00405390(const char*, int);
extern "C" { extern int DAT_004A2924; }
extern "C" { extern const unsigned char DAT_004514D0[]; }
extern "C" void __cdecl SND_LoadSounds_00401df0(void** levelData) {
    FUN_0040B860(levelData);
    FUN_00405390((const char*)DAT_004514D0, DAT_004A2924);
}
}
