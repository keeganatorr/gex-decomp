// Adapted from pc_decomp_backup/src/functions/FUN_00429B40.cpp
// Historical source SHA256: 4b4042e795b7d419bf262be13b5d4bc7753925573647407e82bc06d7a9bf177c
extern "C" {
extern "C" { extern void** FUN_00458508; }
extern "C" void** __cdecl GEX_Target(int lev) { void** p = FUN_00458508; while (p) { if ((int)p[0x2] == 0x54 && (int)p[0x2b] == lev) return p; p = (void**)p[0x56]; } return 0; }
}
