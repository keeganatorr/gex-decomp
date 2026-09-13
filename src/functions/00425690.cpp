// Adapted from pc_decomp_backup/src/functions/FUN_00425690.cpp
// Historical source SHA256: e8515356404a69114ea9d5d67fe7d38eab1c9c7dd7f46e71a254a0c21e72a34f
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004254B0(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = 0;
    p[0x26] = 0;
    p[0x28] = 0;
    p[0x1c] = (void*)0x12;
    p[0x14] = (void*)0x39;
    FUN_00420960(p);
    FUN_004254B0(p);
}
}
