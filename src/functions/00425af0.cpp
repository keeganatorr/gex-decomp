// Adapted from pc_decomp_backup/src/functions/FUN_00425AF0.cpp
// Historical source SHA256: 8a30313930622e1bd3707d73949c8c14ac9b5c7d7fb8803990b17e46bc275024
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_004206B0(int);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00425980(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = 0;
    p[0x1c] = (void*)0x11;
    p[0x14] = (void*)0x3B;
    p[0x25] = (void*)0x14000;
    p[0x24] = (void*)0xE0000;
    if (FUN_004206B0(0x47) == 0) *(int*)0x004A0218 = 0x66;
    FUN_00420960(p);
    FUN_00425980(p);
}
}
