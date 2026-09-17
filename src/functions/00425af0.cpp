extern "C" {
extern void __cdecl FUN_00420BC0(void**);
extern int __cdecl FUN_004206B0(int);
extern void __cdecl FUN_00420960(void**);
extern void __cdecl FUN_00425980(void**);
extern int DAT_004a0218_pState;

void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = 0;
    p[0x26] = 0;
    p[0x1c] = (void*)0x11;
    p[0x14] = (void*)0x3B;
    p[0x25] = (void*)0x14000;
    p[0x24] = (void*)0xE0000;
    if (FUN_004206B0(0x47) == 0)
        DAT_004a0218_pState = 0x66;
    FUN_00420960(p);
    FUN_00425980(p);
}
}
