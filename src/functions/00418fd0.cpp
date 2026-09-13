// Adapted from pc_decomp_backup/src/functions/FUN_00418FD0.cpp
// Historical source SHA256: 6b3a58db52d03d8fa9383a94348e28973b432c58a54c3957670925080e4fb6fa
extern "C" {
extern "C" { extern unsigned int DAT_0049FB90; }

extern "C" unsigned char* __cdecl GEX_Target(unsigned char* param_1, void* param_2)
{
    unsigned int index1, index2;
    unsigned int* ptr;
    unsigned int val;
    
    index1 = param_1[0];
    index2 = param_1[1];
    val = DAT_0049FB90;
    ptr = *(unsigned int**)((char*)param_2 + index1 * 4 + 0x68);
    ptr[index2 + 0x1A] = val;
    
    return param_1 + 2;
}
}
