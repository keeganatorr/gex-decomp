// Adapted from pc_decomp_backup/src/functions/FUN_00420C10.cpp
// Historical source SHA256: 78ce47449edde9783442ce2c309e09c5ba0ecec9b1b1d1a98ae82d784a4b70dc
extern "C" {
extern "C" unsigned int __cdecl FUN_0040F170(unsigned int, unsigned int, unsigned int);
extern "C" { extern unsigned int DAT_0045B9A0; }
extern "C" { extern unsigned int DAT_004A2990; }
extern "C" unsigned int __cdecl GEX_Target(unsigned int p1, unsigned int p2) { unsigned int id = FUN_0040F170(DAT_004A2990, p1, p2); return *(unsigned int*)((char*)&DAT_0045B9A0 + id * 0x20); }
}
