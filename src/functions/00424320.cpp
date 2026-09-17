extern "C" { extern int DAT_0045A6D0; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004242E0(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0x28;
    p[0x15] = 0;
    p[0x14] = (void*)0x40;
    p[0x21] = (void*)DAT_0045A6D0;
    p[0x26] = 0;
    FUN_004242E0(p);
}
