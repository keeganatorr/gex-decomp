extern "C" void __cdecl GOB_ResetState_00420bc0(void**);
extern "C" void __cdecl GOB_KeepOutOfTiles_00420960(void**);
extern "C" int INT_0045a6d0;

extern "C" void __cdecl GEX_Target(void** param_1)
{
    GOB_ResetState_00420bc0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)0x10;
    param_1[0x14] = (void*)0x30;
    param_1[0x27] = (void*)0x14;
    int pGVar1 = INT_0045a6d0;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x21] = (void*)pGVar1;
    GOB_KeepOutOfTiles_00420960(param_1);
}
