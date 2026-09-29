// Adapted from pc_decomp_backup/src/functions/FUN_004180A0.cpp
// Historical source SHA256: 2e7a87bedd8359989b1d490d9efcd1b4672fc92daced09946773e9cae1b2b788
extern "C" {
extern "C" void __cdecl FUN_0040F2E0(int obj, int param);

extern "C" unsigned int __cdecl SCRIPT_InitObject_004180a0(unsigned int param_1, int param_2)
{
    FUN_0040F2E0(param_2, 0);
    return param_1;
}
}
