// Adapted from pc_decomp_backup/src/functions/FUN_00418020.cpp
// Historical source SHA256: 3d6f367f29fb5e65eed6bc64757d09ef9fefb83b7c1254c5796942de6cbac90b
extern "C" {
extern "C" { extern unsigned int FUN_0049FB90; }
extern "C" unsigned int __cdecl SCRIPT_SetLoadObject_00418020(unsigned int param_1, unsigned int** param_2)
{
    param_2[3] = (unsigned int*)FUN_0049FB90;
    return param_1;
}
}
