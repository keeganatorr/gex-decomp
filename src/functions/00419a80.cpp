// Adapted from pc_decomp_backup/src/functions/FUN_00419A80.cpp
// Historical source SHA256: 97aebe08310d6ea726b0379829f23b0e4a6e88412b8305ab38e5c4def3d8a526
extern "C" {
extern "C" void __cdecl FUN_00419840(void**);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" void __cdecl GEX_Target(void** p) { if (((unsigned int)p[0x1b] & 0x2000)) FUN_00419840(p); else FUN_00419520(p); }
}
