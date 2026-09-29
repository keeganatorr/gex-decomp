// Adapted from pc_decomp_backup/src/functions/FUN_0043F2F0.cpp
// Historical source SHA256: 11287ead157d5a3c619ca7a260a389a26aa165a5c96755aabe1a67ffe52c4473
extern "C" {
extern "C" { extern int DAT_004A295C; }
extern "C" void __cdecl FUN_00405450();
extern "C" void __cdecl FUN_00406C30();
extern "C" void __cdecl GFX_Init_0043f2f0()
{ if (DAT_004A295C == 0) { FUN_00405450(); FUN_00406C30(); DAT_004A295C = 1; } }
}
