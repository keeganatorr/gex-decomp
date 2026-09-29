// Adapted from pc_decomp_backup/src/functions/FUN_00418F10.cpp
// Historical source SHA256: 0ac30670abce8558f072cf1eecc1b0c5f2da27f586cbcdbf3269bd763da2cbf9
extern "C" {
extern "C" { extern unsigned int FUN_0049FB90; }
extern "C" unsigned int __cdecl SCRIPT_SetFrameGroup_00418f10(unsigned int param_1, unsigned int* param_2)
{
    param_2[0x14] = FUN_0049FB90;
    return param_1;
}
}
