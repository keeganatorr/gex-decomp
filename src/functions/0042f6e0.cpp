// Adapted from pc_decomp_backup/src/functions/FUN_0042F6E0.cpp
// Historical source SHA256: f79976dadddfbebb93950cc41018037b3e59ce791d0983b7cc602f501225e983
extern "C" {
extern "C" void __cdecl FUN_0042F5F0(void**, int);
extern "C" void __cdecl FUN_004339C0(void**);
extern "C" void __cdecl FUN_0042f6e0(void** p) { p[0x31] = (void*)(((unsigned int)p[0x31] + 0x1e0000) & 0xff0000); FUN_0042F5F0(p, 0); FUN_004339C0(p); }
}
