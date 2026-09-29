// Adapted from pc_decomp_backup/src/functions/FUN_00418CF0.cpp
// Historical source SHA256: 5cbac517a8fe1a372f6237e6632f714e466def952bdc6a8d26b3b763d10986b3
extern "C" {
extern "C" void __cdecl FUN_0041F8C0(unsigned int);

extern "C" unsigned char* __cdecl SCRIPT_AddVoiceEntries_00418cf0(unsigned char* param_1)
{
    FUN_0041F8C0((unsigned int)*param_1);
    return param_1 + 1;
}
}
