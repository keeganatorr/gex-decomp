// Adapted from pc_decomp_backup/src/functions/FUN_004208D0.cpp
// Historical source SHA256: 479bb61fdd086a9189a365800028e0b911f0556446f3d27366872d868ea25eb6
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1, void* param_2)
{
    unsigned int val;
    unsigned int* ptr;
    
    ptr = (unsigned int*)((char*)param_2 + 0x1c);
    val = (*ptr & 0x1fffff) + 0x10000;
    *(unsigned int*)((char*)param_1 + 0x78) = *(unsigned int*)((char*)param_1 + 0x78) - val;
}
}
