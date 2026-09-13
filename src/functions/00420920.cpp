// Adapted from pc_decomp_backup/src/functions/FUN_00420920.cpp
// Historical source SHA256: 65c6c8baff3024eb1e06f0527af3d27602aceaa04342c3acf2a34cc7257cdc18
extern "C" {
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl GEX_Target(void** p, int p2) { if (!FUN_00421560_DrawCharacter(FUN_004A2990, p)) { p[0x1f] = (void*)(((unsigned int)p[0x1f] & 0xff000000) + ((*(unsigned int*)(p2 + 0x24) & 0x1fffff) - 0x1c)); } }
}
