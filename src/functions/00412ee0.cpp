// Adapted from pc_decomp_backup/src/functions/FUN_00412EE0.cpp
// Historical source SHA256: 46615ce9fa6b14321e6b073ca9e699427a3eb042663b649305e6dd03f9bd12fa
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" { extern int DAT_00462E80; }
extern "C" int __cdecl FUN_00412A00(int);
extern "C" void __cdecl FUN_00412DE0(void**);

extern "C" void __cdecl InitPlayerFaceUnspin_00412ee0(void** param_1)
{
    int iVar1;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x35;
    param_1[0x26] = (void*)0;
    param_1[0x14] = (void*)0x45;
    param_1[0x15] = (void*)0x5;
    param_1[0x31] = (void*)DAT_00462E80;
    iVar1 = FUN_00412A00((int)param_1);
    DAT_00462E80 = iVar1;
    FUN_00412DE0(param_1);
}
}
