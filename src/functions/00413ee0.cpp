// Adapted from pc_decomp_backup/src/functions/FUN_00413EE0.cpp
// Historical source SHA256: ca6c7197916fd7a48313b0c9f517be9da32008d431a1324d132dad6929ff151c
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00413ED0(void**);
extern "C" void __cdecl GEX_Target(void** p) { FUN_00420BC0(p); p[0x1c] = (void*)0x59; FUN_00420960(p); FUN_00413ED0(p); }
}
