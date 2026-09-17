extern "C" {
extern int DAT_00459084;
extern int DAT_004A2A98;
extern int DAT_004A2710;
void __cdecl FUN_00405350(int, int, int);
void __cdecl FUN_0041FA80(int);

void __cdecl GEX_Target(void** LevelRelated, int* param_2)
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
        unsigned char* door_ptr = (unsigned char*)((int)&DAT_004A2710 + DAT_004A2A98);
        int current_val = 0;
        current_val = *door_ptr;
        if (current_val != CameraID) {
            *door_ptr = (unsigned char)CameraID;
            LevelRelated[0x27] = 0;
            LevelRelated[0x28] = 0;
            LevelRelated[0x15] = 0;
            LevelRelated[0x26] = (void*)1;
            LevelRelated[0x14] = 0;
            FUN_0041FA80(0x4a);
        }
    }
}
}
