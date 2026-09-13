// Adapted from pc_decomp_backup/src/functions/FUN_0041A500.cpp
// Historical source SHA256: ec8c62d9cf36c88622a906d8376690d219ec24f7093b9d04431f89e85b8bbde2
extern "C" {
extern "C" void __cdecl FUN_00405350(const char*, const char*);

extern "C" void* __cdecl GEX_Target(int* object)
{
    int* animation = (int*)object[3];
    int frame = object[0x15];
    int group = object[0x14];
    if (animation == 0 || frame < 0 || group < 0)
        return 0;

    if (animation[2] != 0) {
        if (group >= animation[3]) {
            FUN_00405350((const char*)0x00458FB0, (const char*)object[2]);
            return 0;
        }
        int* frameCounts = (int*)animation[4];
        if (frameCounts == 0 || frame > frameCounts[group]) {
            FUN_00405350((const char*)0x00458F78, (const char*)object[2]);
            return 0;
        }
    }

    int** groups = (int**)animation[0];
    if (groups == 0 || groups[group] == 0)
        return 0;
    int* frames = groups[group];
    int result = frames[frame];
    if (result == 0) {
        object[0x15] = 0;
        result = frames[0];
    }
    return (void*)result;
}
}
