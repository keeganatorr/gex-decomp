extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00426D20(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x26] = 0;
    p[0x20] = 0;
    p[0x22] = 0;
    p[0x1c] = (void*)0x1A;
    p[0x14] = (void*)0x32;
    p[0x15] = (void*)3;
    FUN_00426D20(p);
}
