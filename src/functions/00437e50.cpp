typedef unsigned int uint;
// Adapted from pc_decomp_backup/src/functions/FUN_00437e50.cpp
// Historical source SHA256: 584a46053043714cc8feaf4e43d262d8fd4d81a5955440615ee8eb05b9274e04
extern "C" {
extern "C" void __cdecl FUN_004339C0(void**);
extern "C" int __cdecl GEX_Target(uint param_1,uint param_2)

{
  return ((param_2 & 0xffff0000) + (param_2 & 0xffff)) * ((int)param_1 >> 0x10) +
         ((int)param_2 >> 0x10) * (param_1 & 0xffff) +
         ((int)((param_2 & 0xffff) * (param_1 & 0xffff)) >> 0x10);
}
}
