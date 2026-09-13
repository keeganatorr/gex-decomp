// Adapted from pc_decomp_backup/src/functions/FUN_004330C0.cpp
// Historical source SHA256: 45206ce27740c3a2104d7aa92298cbff608e230454d13ad19e91196ff72868d6
extern "C" {
extern "C" void __cdecl FUN_00431730(void**);
extern "C" void __cdecl FUN_0041E7C0(void**);
extern "C" void __cdecl FUN_00433070();

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (param_1[0x59] != 0) GEX_Target((void**)param_1[0x59]);
    if (param_1[0x58] != 0) GEX_Target((void**)param_1[0x58]);
    FUN_00431730(param_1);
    param_1[0x40] = param_1[0x17];
    param_1[0x41] = param_1[0x18];
    param_1[0x42] = param_1[0x19];
    param_1[0x43] = param_1[0x1b];
    param_1[0x17] = 0;
    param_1[0x18] = (void*)&FUN_00433070;
    param_1[0x19] = 0;
    FUN_0041E7C0(param_1);
}
}
