// Adapted from pc_decomp_backup/src/functions/FUN_00418D60.cpp
// Historical source SHA256: da1510ab97afcf2d34605fcd1d0f038fe7bd4b0fb90834cad1af813d60afef08
extern "C" {
extern "C" { extern int DAT_0049FB90; }

extern "C" unsigned int __cdecl FUN_0041FB50(void);

extern "C" unsigned int __cdecl SCRIPT_VoiceFinished_00418d60(unsigned int param_1)
{
    DAT_0049FB90 = FUN_0041FB50();
    return param_1;
}
}
