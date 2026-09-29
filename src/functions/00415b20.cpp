// Adapted from pc_decomp_backup/src/functions/FUN_00415B20.cpp
// Historical source SHA256: ef9d4d0d2cb1a6308656946068d46d3ebc387a6317041a09bd9a170e325cf466
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" { extern int DAT_004a283c; }
extern "C" void __cdecl FUN_00415820(void**);

extern "C" void __cdecl InitPlayerGoThruTube_00415b20(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = (void*)0;
    param_1[0x26] = (void*)0;
    param_1[0x1c] = (void*)0x57;
    param_1[0x14] = (void*)0x30;
    param_1[0x27] = (void*)DAT_004a283c;
    param_1[0x1e] = (void*)((unsigned int)param_1[0x1e] & 0xfff00000 | 0x100000);
    param_1[0x1f] = (void*)((unsigned int)param_1[0x1f] & 0xfff00000 | 0x100000);
    FUN_00415820(param_1);
}
}
