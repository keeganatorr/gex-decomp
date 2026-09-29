// Adapted from pc_decomp_backup/src/functions/FUN_0042DDA0.cpp
// Historical source SHA256: 4e9d5089918e8e986579b8c7805290434973dfe317007b90fcef68526293b350
extern "C" {
extern "C" void __cdecl FUN_0042DCF0(void**, int);
extern "C" void __cdecl FUN_0042D6E0(void**, int);

extern "C" void __cdecl FUN_0042dda0_Object_unk(void** param_1, int param_2)
{
    int p2 = param_2;
    void** p1 = param_1;
    FUN_0042DCF0(p1, p2);
    FUN_0042D6E0(p1, p2);
}
}
