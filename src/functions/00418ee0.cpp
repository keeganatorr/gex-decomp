// Adapted from pc_decomp_backup/src/functions/FUN_00418EE0.cpp
// Historical source SHA256: 380a3547a5bc92d72ed993fa94e12d7502e1e5e621af38411eee328f0ff732bf
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F40(unsigned int**);
extern "C" { extern int FUN_0049FB90; }
extern "C" { extern int FUN_0045B808; }
extern "C" unsigned int* __cdecl GEX_Target(unsigned int* p) { unsigned int v = FUN_00417F40(&p); FUN_0049FB90 = *((int*)((char*)&FUN_0045B808 + v * 4) + FUN_0049FB90); return p; }
}
