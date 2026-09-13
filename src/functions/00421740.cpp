// Adapted from pc_decomp_backup/src/functions/FUN_00421740.cpp
// Historical source SHA256: 2d9b07085549404dd2f4f80afae29484b89231c213444a85d148153c1e0accbc
extern "C" {
extern "C" void __cdecl FUN_004216B0(void**);
extern "C" int __cdecl GEX_Target(void** p)
{
    unsigned int state = (unsigned int)p[0x38];
    if (((state & 0x200) >> 9) != ((state & 0x100) != 0))
        FUN_004216B0(p);
    return 0;
}
}
