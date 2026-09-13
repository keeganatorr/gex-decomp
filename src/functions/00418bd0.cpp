// Adapted from pc_decomp_backup/src/functions/FUN_00418BD0.cpp
// Historical source SHA256: 7b9142e76386b4dca72620cbb185203ba09ebbd249790ef8cadbc0152165476d
extern "C" {
extern "C" void __cdecl FUN_00441150(void*);
extern "C" int __cdecl GEX_Target(int p1, void** p2) { p2[0x38] = (void*)((unsigned int)p2[0x38] | 0x1000000); FUN_00441150(p2); return p1; }
}
