// Adapted from pc_decomp_backup/src/functions/FUN_004344D0.cpp
// Historical source SHA256: 9b0e7eaf7133034e46b31a9917c5123be799db1325b02525829b62aef36fdc77
extern "C" {
extern "C" void __cdecl FUN_004344B0(int*);
extern "C" void __cdecl FUN_00434550(int*);

extern "C" void __cdecl GEX_Target(int* param_1)
{
    if (*(int*)(param_1 + 0xb4) & 2) {
        *(int*)(param_1 + 0x70) = 1;
        *(int*)(param_1 + 0x90) = 0x000e0000;
        *(int*)(param_1 + 0x94) = 0x00012000;
        *(int*)(param_1 + 0x8c) = 0;
        *(int*)(param_1 + 0x88) = 0;
        *(int*)(param_1 + 0x84) = 0x50000;
        *(int*)(param_1 + 0x80) = *(int*)(param_1 + 0x9c);
        FUN_004344B0(param_1);
        return;
    }
    FUN_00434550(param_1);
}
}
