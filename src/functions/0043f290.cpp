// Adapted from pc_decomp_backup/src/functions/FUN_0043F290.cpp
// Historical source SHA256: 45fbb77c7477e50aa5453caac84e5bd1f018fdf9b1073c5e294a83facfc9713e
extern "C" {
extern "C" void __cdecl FUN_00445240(int);
extern "C" void __cdecl FUN_00445270(void*);
extern "C" void __cdecl GEX_Target(void)
{
    int& buffer = *(int*)0x004A2B08;
    buffer ^= 1;
    FUN_00445240(0x0046A560 + buffer * 0x14);
    FUN_00445270((void*)(0x0046A588 + buffer * 0x5C));
}
}
