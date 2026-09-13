// Adapted from pc_decomp_backup/src/functions/FUN_0043DAD0.cpp
// Historical source SHA256: 6e7d2cdcc77cb54e0038c40291ee99f2d358425807cc441143d9bc7a446d1802
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1)
{
    unsigned int* p = (unsigned int*)param_1;
    unsigned int a, b;
    a = p[0x1E];
    b = p[0x1F];
    p[0x28] = a;
    p[0x27] = b;
}
}
