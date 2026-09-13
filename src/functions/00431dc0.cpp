// Adapted from pc_decomp_backup/src/functions/FUN_00431DC0.cpp
// Historical source SHA256: 0dff873cc3d250f3ad65b672c98dfb5dfce2ba9511fad8f511b0d151691cb39b
extern "C" {
extern "C" int __cdecl FUN_00428C80(int);

extern "C" void __cdecl GEX_Target(int param_1)
{
    *(int*)(param_1 + 0x50) = 0x1a;
    int iVar1 = FUN_00428C80(5);
    *(int*)(param_1 + 0xa0) = 2;
    *(int*)(param_1 + 0xd0) = 0x200000;
    *(int*)(param_1 + 0xdc) = 0xfff60000;
    *(int*)(param_1 + 0x9c) = iVar1 + 1;
}
}
