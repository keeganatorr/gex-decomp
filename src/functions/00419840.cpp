// Adapted from pc_decomp_backup/src/functions/FUN_00419840.cpp
// Historical source SHA256: ad3d5323605f6f12e4f40b16d89c62aa4d0f79f835b9edf6320ae238cbe127fc
extern "C" {
extern "C" void __cdecl FUN_0040F2E0(void*, int);
extern "C" void __cdecl FUN_00419520(void*);

extern "C" void __cdecl GEX_Target(void* object)
{
    unsigned int address = (unsigned int)object;
    if (address < 0x01000000 || address >= 0x08000000) return;
    int child = *(int*)((char*)object + 0x18c);
    if (child != 0 && ((*(unsigned int*)((char*)object + 0x6c) & 0x80000) == 0)) {
        *(unsigned int*)((char*)child + 4) &= 0xffff7fff;
    }
    FUN_00419520(object);
}
}
