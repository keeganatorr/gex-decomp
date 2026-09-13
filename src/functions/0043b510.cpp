// Adapted from pc_decomp_backup/src/functions/FUN_0043B510.cpp
// Historical source SHA256: 356750c204404404ef6e12440cfcfe41a58e07ef420989beb54dda0ebc6e9cf8
extern "C" {
extern "C" void __cdecl FUN_00419840(void**);
extern "C" void __cdecl GEX_Target(void** p) { int* v = (int*)((int)p[0x2c] - 1); p[0x2c] = (void*)((int)v + 3); if ((int)p[0x2c] < 1) { p[0x2c] = (void*)3; p[0x15] = (void*)((int)p[0x15] + 1); if ((int)p[0x15] > 9) FUN_00419840(p); } }
}
