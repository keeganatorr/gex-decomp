// Adapted from pc_decomp_backup/src/functions/FUN_004184F0.cpp
// Historical source SHA256: 433e85a0c9a4b5e6fb95b508bcad260bdbf209b14a06a3aa51af2956d6137daa
extern "C" {
extern "C" { extern void* DAT_00458C90[]; }

extern "C" unsigned char* __cdecl SCRIPT_SetDoitRoutine_004184f0(unsigned char* param_1, void* param_2)
{
    unsigned int idx;
    unsigned char* result;
    void* val;
    
    idx = param_1[0];
    result = param_1 + 1;
    val = DAT_00458C90[idx];
    *(void**)((char*)param_2 + 0x5C) = val;
    return result;
}
}
