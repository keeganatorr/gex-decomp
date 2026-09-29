struct LevelData {
    int field_0;
    int field_4;
    int field_8;
};

struct CurrentLevel {
    int field_0;
    LevelData* levelData;
};

extern "C" CurrentLevel* FUN_004A2990;
extern "C" unsigned short* __cdecl FUN_004404b0(LevelData*, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00419FE0(CurrentLevel*, unsigned int, unsigned int);

extern "C" void __cdecl SetTileToAlternate_0041b0e0(unsigned int param_1, unsigned int param_2) {
    if ((int)param_1 < 0) return;
    if ((int)param_2 < 0) return;
    LevelData* lv = FUN_004A2990->levelData;
    if ((int)param_1 >= lv->field_4) return;
    int field8 = lv->field_8;
    if ((int)param_2 >= field8) return;
    unsigned short* puVar2 = FUN_004404b0(lv, param_1, param_2);
    if (puVar2 == 0) return;
    int iVar3 = FUN_00419FE0(FUN_004A2990, param_1, param_2);
    if (iVar3 == 0) return;
    *puVar2 = *(unsigned short*)(iVar3 + 10);
}