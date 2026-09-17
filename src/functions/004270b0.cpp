extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00426FC0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x18;
    param_1[0x14] = (void*)0x32;
    param_1[0x15] = (void*)0;
    param_1[0x26] = (void*)0;
    param_1[0x22] = (void*)0;
    param_1[0x27] = (void*)((0 < (int)param_1[0x20]) - ((int)param_1[0x20] < 0));
    FUN_00426FC0(param_1);
}
