// Adapted from pc_decomp_backup/src/functions/FUN_0040C1A0.cpp
// Historical source SHA256: 25165007a72354b0655c7a5aff3e0d64eac274bb283e94606b4d0850357e2b62
extern "C" {
extern "C" void** __cdecl FUN_0040C110(int, int);
extern "C" { extern int DAT_00456034; }

extern "C" int __cdecl GEX_Target(int param_1, unsigned int param_2)
{
    void** obj = FUN_0040C110(0x7b, param_1);
    if (param_2 & 1) obj[0x2d] = (void*)((unsigned int)obj[0x2d] & 0xfffffffe);
    if (param_2 & 2) obj[0x15] = 0;
    if (param_2 & 4) obj[0x15] = (void*)-1;
    if (param_2 & 8) DAT_00456034 = 0;
    if (param_2 & 0x10) return (int)obj[0x28];
    if (param_2 & 0x20) return (int)obj[0x29];
    return 0;
}
}
