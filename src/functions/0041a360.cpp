// Adapted from pc_decomp_backup/src/functions/FUN_0041A360.cpp
// Historical source SHA256: 5f48a9fe667c6e4f58c79ab5198d9b11a3b1069ad2d8f4ff90eca72517486fb1
extern "C" {
extern "C" void __cdecl FUN_00401B50(int, int, int, int, int, int);

extern "C" void __cdecl SND_PlaySoundNoPosition_0041a360(int a, int b)
{
    FUN_00401B50(a, 0, 0, b >> 1, 0x40, 1000);
}
}
