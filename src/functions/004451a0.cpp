// Adapted from pc_decomp_backup/src/functions/FUN_004451a0_GFXInit4.cpp
// Historical source SHA256: b7d8e6521807e9da789d720f8e2a2e297cc487078619e20669be62048efc87cb
extern "C" {
extern "C" { extern int DAT_004a2f84; }
extern "C" void __cdecl FUN_00406C30();
extern "C" int __cdecl GEX_Target(int p) { DAT_004a2f84 = 0; *(int*)0x004a2f74 = -1; *(int*)0x004a2f7c = -1; *(int*)0x004a2f80 = -1; *(int*)0x004a2f70 = -1; FUN_00406C30(); return p; }
}
