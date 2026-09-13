// Adapted from pc_decomp_backup/src/functions/FUN_0041AB10.cpp
// Historical source SHA256: 70a86f320da36a70a856d7ab5bb0d144a866ec222336c3d4cb7a82baba91d9f4
extern "C" {
extern "C" { extern int DAT_00459084; }
extern "C" { extern int DAT_004A2A98; }
extern "C" { extern int DAT_004A2710; }
extern "C" void __cdecl FUN_00405350(int, int, int);
extern "C" void __cdecl FUN_0041FA80(int);

extern "C" void __cdecl GEX_Target(void** LevelRelated, int* param_2)
{
    int CameraID;
    unsigned int flags_shifted;
    unsigned int nd_val;

    if (*param_2 == 0) return;

    flags_shifted = (*(unsigned int*)((int)LevelRelated[0x5e] + 0x6c) & 0xf00) >> 8;
    nd_val = *(unsigned int*)LevelRelated[0x5d] & 0xffff;

    if (nd_val != 1) return;
    if (flags_shifted != 2) return;

    CameraID = (int)LevelRelated[0x2d];
    if (CameraID <= 0) {
        FUN_00405350((int)&DAT_00459084, (int)LevelRelated[0x1e] >> 16, (int)LevelRelated[0x1f] >> 16);
        return;
    }

    {
        unsigned int level_id = *(unsigned int*)&DAT_004A2A98;
        unsigned char* door_base = (unsigned char*)&DAT_004A2710;
        int ebx_val;
        unsigned char current_val;
        ebx_val = 0;
        current_val = *(unsigned char*)(door_base + level_id);
        if (ebx_val + (int)current_val != CameraID) {
            *(unsigned char*)(door_base + level_id) = (unsigned char)CameraID;
            LevelRelated[0x27] = (void*)0;
            LevelRelated[0x28] = (void*)0;
            ((unsigned char*)LevelRelated)[0x54] = 0;
            LevelRelated[0x26] = (void*)1;
            LevelRelated[0x14] = (void*)0;
            FUN_0041FA80(0x4a);
        }
    }
}
}
