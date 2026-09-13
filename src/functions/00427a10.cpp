// Adapted from pc_decomp_backup/src/functions/FUN_00427A10.cpp
// Historical source SHA256: 45dd0f4e8b59f06e9de83ce4165682db0270c7af754013f91b44acf839328276
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00427980(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = p[0x20] = p[0x22] = 0;
    p[0x1c] = (void*)0x1D;
    p[0x14] = (void*)0x2C;
    FUN_00427980(p);
}
}
