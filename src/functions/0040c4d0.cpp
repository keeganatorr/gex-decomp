// Adapted from pc_decomp_backup/src/functions/FUN_0040C4D0.cpp
// Historical source SHA256: 88053187526e322cf1e8fa2f42fd1af8309322543b4bab13d1e2b6ef8268a056
extern "C" {
extern "C" { extern int DAT_00462c70; }
extern "C" { extern int FUN_004A2994; }
extern "C" { extern int FUN_004A2A7C; }
extern "C" { extern int DAT_004a2920_LoadLevelUnk5; }
extern "C" { extern int DAT_00456020_MusicOnUnk; }
extern "C" { extern int DAT_0045601c_LevelMusicUnk; }
extern "C" { extern int DAT_00462c68; }

extern "C" void __cdecl GEX_Target(int param_1)
{
    DAT_00462c70 = 0;
    FUN_004A2994 = 0;
    FUN_004A2A7C = 1;
    *(int*)(param_1 + 0xb0) = 0;
    int* arr = (int*)0x004560f4;
    int count;
    do {
        *arr++ = 0;
        count = DAT_004a2920_LoadLevelUnk5;
    } while ((int)arr < 0x004561c8);
    *(int*)(param_1 + 0xb0) = 1;
    if (count == 0) *(int*)(param_1 + 0xb0) = 0;
    DAT_00456020_MusicOnUnk = 1;
    DAT_0045601c_LevelMusicUnk = 0;
    DAT_00462c68 = 0;
}
}
