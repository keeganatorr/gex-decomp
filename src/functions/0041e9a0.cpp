// Adapted from pc_decomp_backup/src/functions/FUN_0041E9A0.cpp
// Historical source SHA256: 0faab8beb6d571bf0be40a300feabdc74b83e2c9c57023342062413e03c66a30
extern "C" {
extern "C" void** __cdecl FUN_0042CC20(void**);
extern "C" void __cdecl FUN_0042CC00(void**, void**);
extern "C" { extern int DAT_004A23C0; }
extern "C" { extern int DAT_00463728; }
extern "C" void __cdecl GEX_Target(void** p) { void** obj; while (obj = FUN_0042CC20(p), obj) { FUN_0042CC00((void**)&DAT_00463728, obj); DAT_004A23C0--; } }
}
