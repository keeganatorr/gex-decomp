// Adapted from pc_decomp_backup/src/functions/FUN_00418720.cpp
// Historical source SHA256: ca49cfe2cd3d05842e8d12ee9bc2d7f6e96d6b2122c58d7dc9fc6c6ab2104ba1
extern "C" {
extern "C" void __cdecl FUN_00419B80(int, int);

extern "C" unsigned char* __cdecl SCRIPT_SetDisplayPriority_00418720(unsigned char* str, int priority)
{
    FUN_00419B80(priority, str[0]);
    return str + 1;
}
}
