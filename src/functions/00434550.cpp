// Adapted from pc_decomp_backup/src/functions/FUN_00434550.cpp
// Historical source SHA256: d20cc76a648764b94cd8769ae72e049f13ddcd1b6d90cafa326995351b58640a
extern "C" {
extern "C" void __cdecl FUN_00434540(int dummy);

extern "C" void __cdecl GEX_Target(int param_1)
{
    *(int*)(param_1 + 0x70) = 2;
    FUN_00434540(param_1);
}
}
