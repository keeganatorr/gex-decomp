// Adapted from pc_decomp_backup/src/functions/FUN_00432D10.cpp
// Historical source SHA256: 645ae94d85a536697a76d326fda52db921d98a25a0991a3ec66acc49f836a655
extern "C" {
extern "C" void __cdecl FUN_00432C90(void**);
extern "C" void __cdecl GEX_Target(void** p) { void* c; while (c = p[0x57], c) p = (void**)c; FUN_00432C90(p); }
}
