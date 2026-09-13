// Adapted from pc_decomp_backup/src/functions/FUN_004207E0.cpp
// Historical source SHA256: a316f9335517ef6e90bff76d37f69b00fc94c3a46332d1b204caf94d1a931f31
extern "C" {
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_00419FE0(int, int, unsigned int);
extern "C" { extern unsigned int FUN_0045B9A0; }
extern "C" unsigned int __cdecl GEX_Target(int p1, unsigned int p2) { int ba = FUN_00419FE0(FUN_004A2990, p1, p2); return *(unsigned int*)((char*)&FUN_0045B9A0 + (unsigned int)*(unsigned short*)(ba + 6) * 0x20) >> 0x1f; }
}
