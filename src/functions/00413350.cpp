extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00413230(void**);
extern "C" int DAT_004a0218_pState;
extern "C" void __cdecl InitPlayerSideSpinAround_00413350(void** p)
{
    FUN_00420BC0(p);
    p[0x1c] = (void*)0x49;
    p[0x26] = 0;
    p[0x14] = (void*)0x55;
    p[0x15] = (void*)3;
    DAT_004a0218_pState = 0x67;
    FUN_00413230(p);
}
