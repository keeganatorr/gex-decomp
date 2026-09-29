// Adapted from pc_decomp_backup/src/functions/FUN_0041EC70.cpp
// Historical source SHA256: 578b1203168d1060cc2aa06b4be6401560d3651db638ff16b07d5de31877853a
extern "C" {
extern "C" void __cdecl FUN_00409430(void*, void*, int);
extern "C" void __cdecl FUN_00405390(const char*, int);
extern "C" void __cdecl FUN_0040B8C0(void*, int, int, int*);

extern "C" { extern const char DAT_00459730[]; }

extern "C" int __cdecl M1_OpenLevelFile_0041ec70(
    void* levelTileStruct, int sectionType, int levelDataPtr, int* outputDataPtr)
{
    union {
        int FileSize;
        char pad[16];
    } levFileHeader;

    FUN_00409430(levelTileStruct, &levFileHeader, sectionType);
    if ((unsigned int)levFileHeader.FileSize < 0x800) {
        FUN_00405390(DAT_00459730, sectionType);
        return 0;
    }
    FUN_0040B8C0(levelTileStruct, sectionType, levelDataPtr, outputDataPtr);
    return 1;
}
}
