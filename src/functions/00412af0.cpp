extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00412A50(void**);
extern "C" void __cdecl InitPlayerFaceSpin_00412af0(void** p)
{
    FUN_00420BC0(p);
    p[0x26] = 0;
    p[0x27] = 0;
    p[0x29] = 0;
    p[0x1c] = (void*)0x33;
    p[0x14] = (void*)0x45;
    p[0x15] = 0;
    FUN_00412A50(p);
}
}
