// Adapted from pc_decomp_backup/src/functions/FUN_00423A00.cpp
// Historical source SHA256: 788d8e079d16248591404672b5bdc6671d7a282f0f37123f9cf9667df39b533a
extern "C" {
extern "C" void __cdecl FUN_00423780(void**);
extern "C" int __cdecl GEX_Target(void** p)
{
    FUN_00423780(p);
    int count = 4 - ((((unsigned int)p[0x31] + 0x1000) & 0x400000) == 0);
    for (int i = 0; i < count; ++i)
        if (((unsigned char*)0x004A2820)[i] == 0) return 0;
    return 1;
}
}
