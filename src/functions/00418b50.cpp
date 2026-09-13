// Adapted from pc_decomp_backup/src/functions/FUN_00418B50.cpp
// Historical source SHA256: 7771412c77aeb51238a908bbf18d97be025655752a6b048a48137eb1022cf310
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F40(unsigned int**);
extern "C" void __cdecl FUN_0041A320(void**, int, int);
extern "C" unsigned int* __cdecl GEX_Target(unsigned int* p) { unsigned int s = FUN_00417F40(&p); unsigned int o = *p; FUN_0041A320((void**)*(unsigned int*)((int)p + 1), s, (o & 0xff) << 1); return (unsigned int*)((char*)p + 5); }
}
