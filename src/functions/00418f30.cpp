// Adapted from pc_decomp_backup/src/functions/FUN_00418F30.cpp
// Historical source SHA256: dc1e9ccdb09026dbd7f46794f6113512e278b81d57849efdd411861f3280a784
extern "C" {
extern "C" { extern unsigned int DAT_0049FB90; }
extern "C" unsigned int __cdecl SCRIPT_SetFrameIndex_00418f30(unsigned int param_1, unsigned int* param_2)
{
    param_2[0x15] = DAT_0049FB90;
    return param_1;
}
}
