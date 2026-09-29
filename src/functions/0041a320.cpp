// Adapted from pc_decomp_backup/src/functions/FUN_0041A320.cpp
// Historical source SHA256: 4e1ca55aa4ef160f4c6f95c323ef146fb6cd5bd560fd68570ccfead03ca01f8a
extern "C" {
extern "C" void __cdecl FUN_0041A250(void**, int, int, int);

extern "C" void __cdecl SND_PlaySoundWithVolume_0041a320(void** param_1, int param_2, int param_3)
{
    FUN_0041A250(param_1, param_2, param_3 >> 1, 0x40);
}
}
