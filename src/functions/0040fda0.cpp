// Adapted from pc_decomp_backup/src/functions/FUN_0040FDA0.cpp
// Historical source SHA256: 1ace7054537e04192b34ca2975511ab95b0ac0d7d3fb6b84e7a3f312019dc071
extern "C" {
extern "C" void* FUN_004096C0(int);
extern "C" void __cdecl FUN_0040FD50(int, int*, int*, int, int, int, int, int);

extern "C" int* __cdecl OBI_NewObjectIntroTracker_0040fda0(int param_1, int param_2, int* param_3, int* param_4, int param_5, int param_6, int param_7, int param_8, int param_9)
{
    int* mem = (int*)FUN_004096C0(0x3c);
    if (mem == 0) return 0;
    mem[0] = param_1;
    mem[2] = param_2;
    FUN_0040FD50((int)mem, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
    return mem;
}
}
