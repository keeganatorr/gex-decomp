// Adapted from pc_decomp_backup/src/functions/FUN_00412AF0.cpp
// Historical source SHA256: f4638e4782312535e8d141a3c9b07f187e3f78683b59922814e46847db019d2b
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00412A50(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x26] = p[0x27] = p[0x29] = 0;
    p[0x1c] = (void*)0x33;
    p[0x14] = (void*)0x45;
    p[0x15] = 0;
    FUN_00412A50(p);
}
}
