// Adapted from pc_decomp_backup/src/functions/FUN_00418510.cpp
// Historical source SHA256: 0264bf12cf2f8bb3deec30c0d4c35354b5037618cb57fcc520945f80c5116d5d
extern "C" {
extern "C" { extern void* DAT_00458CA0[]; }

extern "C" unsigned char* __cdecl SCRIPT_SetClidRoutine_00418510(unsigned char* param_1, void** param_2)
{
    unsigned int idx;
    idx = *param_1;
    param_2[0x19] = DAT_00458CA0[idx];
    return param_1 + 1;
}
}
