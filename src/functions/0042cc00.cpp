// Adapted from pc_decomp_backup/src/functions/FUN_0042CC00.cpp
// Historical source SHA256: 683760c421ed1fd7f751dd37331d6b97d39f05a453f79065b52c9d31b227b1dd
extern "C" {
extern "C" void __cdecl FUN_0042CBB0(int *list, int *node);

extern "C" void __cdecl GEX_Target(int *param_1, int *param_2)
{
    FUN_0042CBB0(param_1 + 1, param_2);
}
}
