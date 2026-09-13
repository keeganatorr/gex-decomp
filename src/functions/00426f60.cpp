// Adapted from pc_decomp_backup/src/functions/FUN_00426F60.cpp
// Historical source SHA256: d8f3dca3b46c7035fa7a5677d72ca7bdc314aa2d0c2d5d3d28c5e942bd94852e
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00426DF0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x19;
    param_1[0x14] = (void*)0x32;
    param_1[0x15] = (void*)0x2;
    param_1[0x26] = (void*)0;
    iVar1 = 0xfffd0000;
    if ((int)param_1[0x20] < 0) {
        iVar1 = 0x30000;
    }
    param_1[0x22] = (void*)iVar1;
    FUN_00426DF0(param_1);
}
}
