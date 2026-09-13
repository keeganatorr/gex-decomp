// Adapted from pc_decomp_backup/src/functions/FUN_0040D8E0.cpp
// Historical source SHA256: 8fbc79b8e0e8fd9b162354b5ec2236fa795bde9fd53628749a7c7ada2f25d145
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void __cdecl FUN_0040D740(void**);
extern "C" void __cdecl GEX_Target(void** p) { if (!FUN_0040FCE0(p) && !((unsigned int)p[0x20] & 1)) FUN_0040D740(p); }
}
