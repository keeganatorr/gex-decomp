// Adapted from pc_decomp_backup/src/functions/FUN_00409680.cpp
// Historical source SHA256: c5129bc8e60baeea822072731ef6a92efcac520c28802a115b0454be2691a18d
extern "C" {
extern "C" void __cdecl FUN_004094F0(void*, void**, unsigned int);
extern "C" int __cdecl FUN_00409680_ReadFile(void* FileHandle, int fileHandle, void** FileOutputBytes, unsigned int NumberOfBytesToRead, void* param5) {
    *(int*)(fileHandle + 0x24) = 0;
    FUN_004094F0(FileHandle, FileOutputBytes, NumberOfBytesToRead);
    if (param5 != 0) ((void(*)(int))param5)(fileHandle + 8);
    return 1;
}
}
