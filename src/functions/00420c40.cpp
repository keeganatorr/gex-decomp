// Adapted from pc_decomp_backup/src/functions/FUN_00420C40.cpp
// Historical source SHA256: 5912e21adcf533743baf471ac43b01793cf8c2d379e4c6c123de7c2919b82d50
extern "C" {
extern "C" unsigned int __cdecl FUN_0040F170(unsigned int, unsigned int, unsigned int);
extern "C" { extern unsigned int DAT_0045B9A0; }
extern "C" unsigned int __cdecl GEX_Target(unsigned int p1, unsigned int p2, unsigned int p3) { unsigned int id = FUN_0040F170(p1, p2, p3); return *(unsigned int*)((char*)&DAT_0045B9A0 + id * 0x20) & 0xef008000; }
}
