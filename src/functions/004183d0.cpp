// Adapted from pc_decomp_backup/src/functions/FUN_004183D0.cpp
// Historical source SHA256: 7c43d3224edc9a0f1612e785fc62e9bc006daf9ec66d933bcaa1f8d4c73711cb
extern "C" {
extern "C" unsigned char* __cdecl SCRIPT_CopyFieldToParent_004183d0(unsigned char* param_1, void** param_2)
{
    void* parent;
    unsigned int idx;
    void* value;
    unsigned char* result;
    
    idx = *param_1;
    result = param_1 + 1;
    value = param_2[idx + 0x1a];
    parent = param_2[0x57];
    if (parent != 0) {
        ((void**)parent)[idx + 0x1a] = value;
    }
    return result;
}
}
