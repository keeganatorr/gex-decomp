// Adapted from pc_decomp_backup/src/functions/FUN_0040FD50.cpp
// Historical source SHA256: d66bf613efc61128eb03e696ce0dba40b2e1732b3d573fc8db98828128d1c962
extern "C" {
extern "C" void __cdecl GEX_Target(
    int param_1, int param_2, int* param_3, int param_4,
    int param_5, int param_6, int param_7, int param_8)
{
    *(int*)(param_1 + 4) = param_2;
    *(int*)(param_1 + 0xc) = param_5;
    *(int*)(param_1 + 0x10) = param_6;
    *(int*)(param_1 + 0x14) = -1;
    *(int*)(param_1 + 0x18) = -1;
    *(int*)(param_1 + 0x1c) = -1;
    *(int*)(param_1 + 0x20) = -1;
    *(int*)(param_1 + 0x24) = -1;
    *(int*)(param_1 + 0x28) = -1;
    *(int**)(param_1 + 0x2c) = param_3;
    *(int*)(param_1 + 0x30) = param_4;
    *(int*)(param_1 + 0x34) = param_7;
    *(int*)(param_1 + 0x38) = param_8;
}
}
