struct LevelDataStruct {
    int field_0x0;
    int field_0x4_CameraX;
    int field_0x8_CameraY;
};

struct GexTileStruct {
    void* handle_0x0_LevelData;
    LevelDataStruct* f_0x4_levelData;
    void* f_0x8_gOb_Tiles_gexTileStruct;
    int f_0xc_xTile;
    int field_0x10_yTile;
    void* field_0x14_TileData;
    void* field_0x18_TileInner;
    GexTileStruct* field_0x1c_ptr;
    int field_0x20_gTiles;
    int field_0x24_object_ptr_unk;
};

extern "C" {
    extern GexTileStruct* M1_CurrentLevel_004a2990;
    extern int __cdecl FUN_00440430_CheckWallCollisionInner(void*, void*, int, int);

    int __cdecl GOB_GetBlockAddress_00419fe0(GexTileStruct* param_1, int param_2, unsigned int param_3)
    {
        if (param_2 >= 0 &&
            param_2 < M1_CurrentLevel_004a2990->f_0x4_levelData->field_0x4_CameraX &&
            (int)param_3 >= 0 &&
            M1_CurrentLevel_004a2990->f_0x4_levelData->field_0x8_CameraY > (int)param_3) {
            return FUN_00440430_CheckWallCollisionInner(
                param_1->f_0x4_levelData,
                param_1->field_0x14_TileData,
                param_2, param_3);
        }
        return *(int*)param_1->field_0x14_TileData;
    }
}
