// Adapted from pc_decomp_backup/src/functions/FUN_00418D10.cpp
// Historical source SHA256: e361f962e55b61669cb27337d15213b9ecd312d21fd8e124ce76e8f84fd11cd5
extern "C" {
extern "C" void __cdecl FUN_0041FA80(unsigned int);

extern "C" unsigned char* __cdecl SCRIPT_PlayVoice_00418d10(unsigned char* param_1)
{
    FUN_0041FA80((unsigned int)*param_1);
    return param_1 + 1;
}
}
