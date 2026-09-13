// Adapted from pc_decomp_backup/src/functions/FUN_004262C0.cpp
// Historical source SHA256: bb71b13c1121418f133423bdcf9aa363e563c4d05bb0f503786a39e2451a2699
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00426180(void**);
extern "C" { extern int DAT_0045a6d4; }

extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0xf;      
    p[0x14] = (void*)0x28;
    p[0x15] = (void*)0x3;
    p[0x25] = (void*)0x14000;
    p[0x21] = (void*)DAT_0045a6d4;
    p[0x26] = (void*)1;
    p[0x25] = (void*)0x14000;
    p[0x24] = (void*)0xe0000;
    FUN_00420960(p);
    FUN_00426180(p);
}
}
