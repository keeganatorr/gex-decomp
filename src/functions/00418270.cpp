// Adapted from pc_decomp_backup/src/functions/FUN_00418270.cpp
// Historical source SHA256: 1daf86401bf1dc5835c25733e02ca73c55e502220697610705b55156740ddbc8
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F00(unsigned char**);
extern "C" int __cdecl FUN_00449E10();
extern "C" { extern int DAT_0049FB90; }
extern "C" unsigned char* __cdecl SCRIPT_Random_00418270(unsigned char* p) { unsigned int m = FUN_00417F00(&p); DAT_0049FB90 = FUN_00449E10() % (int)m; return p; }
}
