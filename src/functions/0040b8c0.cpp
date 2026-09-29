// Adapted from pc_decomp_backup/src/functions/FUN_0040B8C0.cpp
// Historical source SHA256: 6f5bbe583b1846829aa6cabdca2ac638ed22bb48ec235eb84a26818f35878b7d
extern "C" {
extern "C" { extern int FUN_00462728; }
extern "C" { extern int FUN_00462714; }
extern "C" void __cdecl FUN_0040B460();

struct LoadRequest {
    int* nextTilePtr;
    int* currentTilePtr;
    int remainingBlocks;
    int loadedBlocks;
    int totalBlocks;
    int file[4];
    void* directory;
    int levelNumber;
    int initialized;
    int reserved;
};

extern "C" void __cdecl BLOC_LoadBlocks_0040b8c0(void* levelFileHandle, int levNumber,
                                        int* nextTilePtr, int* currentTilePtr)
{
    *currentTilePtr = 0;
    LoadRequest* request = ((LoadRequest*)0x00462a58) + FUN_00462728;
    request->nextTilePtr = nextTilePtr;
    request->currentTilePtr = currentTilePtr;
    request->levelNumber = levNumber;
    request->directory = levelFileHandle;
    request->initialized = 0;
    request->reserved = 0;
    FUN_00462728++;
    if (FUN_00462728 == 10) FUN_00462728 = 0;
    FUN_00462714++;
    FUN_0040B460();
}
}
