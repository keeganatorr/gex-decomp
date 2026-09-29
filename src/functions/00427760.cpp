// Adapted from pc_decomp_backup/src/functions/FUN_00427760.cpp
// Historical source SHA256: 62be92934fa50d4a67905aa65ae924314f153293dee374fd1a5f65737f4e6083
extern "C" {
extern "C" void __cdecl FUN_004276E0(int obj);

extern "C" void __cdecl InitPlayerTailSlash_00427760(int param_1)
{
    *(int*)(param_1 + 0x54) = 0;
    FUN_004276E0(param_1);
}
}
