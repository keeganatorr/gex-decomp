// Adapted from pc_decomp_backup/src/functions/FUN_00418530.cpp
// Historical source SHA256: 39380a43f895ff8fe3cd98decb7d75a08f08e1a8ee65aa0b445255db7b89c662
extern "C" {
extern "C" { extern void* DAT_00458CB0[]; }

extern "C" unsigned char* __cdecl SCRIPT_SetDrawRoutine_00418530(unsigned char* param_1, void* param_2)
{
    unsigned int idx;
    unsigned char* result;
    void* val;
    
    idx = param_1[0];
    result = param_1 + 1;
    val = DAT_00458CB0[idx];
    *(void**)((char*)param_2 + 0x60) = val;
    return result;
}
}
