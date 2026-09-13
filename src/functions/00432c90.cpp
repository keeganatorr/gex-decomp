// Adapted from pc_decomp_backup/src/functions/FUN_00432C90.cpp
// Historical source SHA256: 10527ae618732998466cb6151548e9b6c8b1d9805b0091e3ecd460e790334bcd
extern "C" {
extern "C" void __cdecl FUN_004317B0(void**);
extern "C" void __cdecl FUN_0041E7E0(void**, int*, int*, int*);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (param_1[0x59] != 0) GEX_Target((void**)param_1[0x59]);
    if (param_1[0x58] != 0) GEX_Target((void**)param_1[0x58]);
    FUN_004317B0(param_1);
    param_1[0x17] = param_1[0x40];
    param_1[0x18] = param_1[0x41];
    param_1[0x19] = param_1[0x42];
    param_1[0x1b] = param_1[0x43];
    FUN_0041E7E0(param_1, (int*)param_1[0x5a], (int*)(((int)param_1[0x43] & 0xf00) >> 8), (int*)param_1[0x5b]);
}
}
