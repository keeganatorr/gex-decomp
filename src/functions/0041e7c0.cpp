// Adapted from pc_decomp_backup/src/functions/FUN_0041E7C0.cpp
// Historical source SHA256: 06e81956a862aa1674f61baf879d7c9d1dde2eb28bcedb88f2088b88aa0f5afa
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1)
{
    unsigned int* p = (unsigned int*)param_1;
    if (p[0x60] != 0) {
        *(int*)(p[0x60] + 8) = 0;
        p[0x60] = 0;
    }
}
}
