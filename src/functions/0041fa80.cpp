// Adapted from pc_decomp_backup/src/functions/FUN_0041FA80.cpp
// Historical source SHA256: fbee59f18dc3dbc376b7c2ff01c516f5305197345a75923488c22ce7c57635c2
extern "C" {
extern "C" unsigned int __cdecl FUN_0041FB50();
extern "C" void __cdecl FUN_00401AD0(unsigned int);
extern "C" void __cdecl FUN_0041F8B0(int);

extern "C" { extern int DAT_004A02D0[2]; }
extern "C" { extern int DAT_004638B8; }
extern "C" { extern int DAT_004638BC; }
extern "C" { extern int DAT_004639D8; }

extern "C" unsigned int __cdecl GEX_Target(int param_1)
{
    unsigned int uVar1;

    uVar1 = FUN_0041FB50();
    if (uVar1 != 0 && (DAT_004A02D0[0] == param_1 || DAT_004A02D0[1] == param_1)) {
        uVar1 = (unsigned int)(DAT_004A02D0[1] == param_1);
        FUN_00401AD0(uVar1);
        DAT_004A02D0[uVar1] = 0;
        DAT_004638B8 = uVar1;
        DAT_004638BC = 0;
        DAT_004639D8 = 0x5a;
        FUN_0041F8B0(param_1);
        return 1;
    }
    return 0;
}
}
