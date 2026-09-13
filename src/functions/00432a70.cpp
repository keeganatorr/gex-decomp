// Adapted from pc_decomp_backup/src/functions/FUN_00432A70.cpp
// Historical source SHA256: 6a3470c46bbd01fd4b25b0244ceefad26137bc8170cbf97a2a426a76b2168ccd
extern "C" {
extern "C" int __cdecl FUN_00428C80(int);

extern "C" int __cdecl GEX_Target(void** p)
{
    int i;
    p[0x14] = (void*)0x1f;
    i = FUN_00428C80(4) + 2;
    p[0x34] = (void*)0x200000;
    p[0x37] = (void*)0xfff60000;
    p[0x28] = (void*)2;
    p[0x27] = (void*)i;
    return i;
}
}
