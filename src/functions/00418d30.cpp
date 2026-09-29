// Adapted from pc_decomp_backup/src/functions/FUN_00418D30.cpp
// Historical source SHA256: 0fd2a33b3242d567fa1db4c7bdfc972bd1307d3b91d296824795b0ec0ba791c5
extern "C" {
extern "C" void __cdecl FUN_0041FB80(unsigned int);

extern "C" unsigned char* __cdecl SCRIPT_ForceVoiceSituation_00418d30(unsigned char* param_1)
{
    FUN_0041FB80((unsigned int)*param_1);
    return param_1 + 1;
}
}
