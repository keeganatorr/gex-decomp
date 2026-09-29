extern "C" {
void __cdecl FUN_00420BC0(void**);
void __cdecl FUN_00427780(void**);
void __cdecl InitPlayerDuck_00427850(void** p)
{
    FUN_00420BC0(p);
    p[0x20] = 0;
    p[0x22] = 0;
    p[0x31] = 0;
    p[0x1c] = (void*)0x1E;
    p[0x14] = (void*)0x2C;
    p[0x15] = (void*)1;
    FUN_00427780(p);
}
}
