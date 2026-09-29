struct CDirectory;
struct M1Tile;

struct M1Level {
    CDirectory *lvl_dir;
    void *lvl_map;
    void *lvl_mapBlk;
    unsigned int field_0C;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1C;
    M1Tile *lvl_tiles;
};

extern "C" {
    void TracePrintf_Debug_00405390(const char *);
    void BLOC_LoadBlocks_0040b8c0(CDirectory *levelFileHandle, unsigned int levNumber, void **lvl_mapBlk, void **lvl_map);
    extern char s_M1_LoadLevel_00459720[];
    extern char s_Load_Map_00459714[];
    extern M1Tile gTiles_004a02f0[];
    extern int M1_IsLoadingMapLevel_004a296c;
    extern int M1_StreamingState_00463844;
    extern int level_004a2964;
    extern char lpValueName_00451778[];
    extern int M1_StreamedLevel_004638a4;
}

extern "C" void M1_LoadLevel_0041ebe0(CDirectory *levelFileHandle, M1Level *tilePointer, unsigned int levNumber)
{
    int loopCounter;
    unsigned int *zeroPtr;

    TracePrintf_Debug_00405390(s_M1_LoadLevel_00459720);

    zeroPtr = (unsigned int *)tilePointer;
    for (loopCounter = 9; loopCounter != 0; loopCounter = loopCounter - 1) {
        *zeroPtr = 0;
        zeroPtr++;
    }

    tilePointer->lvl_tiles = gTiles_004a02f0;
    tilePointer->lvl_dir = levelFileHandle;

    if (M1_IsLoadingMapLevel_004a296c == 0) {
        M1_StreamingState_00463844 = 0;
    } else {
        BLOC_LoadBlocks_0040b8c0(levelFileHandle, levNumber, &tilePointer->lvl_mapBlk, &tilePointer->lvl_map);
        M1_StreamingState_00463844 = 4;
    }

    *(void **)((char *)gTiles_004a02f0 - 0x18) = lpValueName_00451778;
    M1_StreamedLevel_004638a4 = level_004a2964;
    TracePrintf_Debug_00405390(s_Load_Map_00459714);
}
