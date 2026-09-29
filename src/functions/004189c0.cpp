// Adapted from pc_decomp_backup/src/functions/FUN_004189C0.cpp
// Historical source SHA256: c825ab79e674f4f7d245ac41770faa5a73770c2df65ee6eba2a73d98627380b5
extern "C" {
extern "C" { extern int DAT_0049FB90; }
extern "C" void* __cdecl FUN_00437B70(void**);

extern "C" int __cdecl SCRIPT_TurtleHeadAttack_004189c0(int param_1, void** param_2)
{
    int result = (int)FUN_00437B70(param_2);
    int ecx_dummy = param_1;
    DAT_0049FB90 = result;
    return ecx_dummy;
}
}
