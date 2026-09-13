// Adapted from pc_decomp_backup/src/functions/FUN_00414900.cpp
// Historical source SHA256: 78004aee0dd15aa80f1fb25643e5eb16dba84400557f850f08b11f50c485df3a
extern "C" {
extern "C" void __cdecl FUN_0041A340(int*, int);

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int v38;
    int* src;
    int iRet;

    *(int*)(param_1 + 0x35) = *(int*)(param_1 + 0x1e);
    *(int*)(param_1 + 0x36) = *(int*)(param_1 + 0x1f);
    *(int*)(param_1 + 0x3f) = *(int*)(param_1 + 0x1b);
    *(int*)(param_1 + 0x3d) = *(int*)(param_1 + 0x14);
    *(int*)(param_1 + 0x3e) = *(int*)(param_1 + 0x15);
    *(int*)(param_1 + 0x39) = 0;
    v38 = *(int*)(param_1 + 0x38);
    *(int*)(param_1 + 0x3a) = 0;
    *(int*)(param_1 + 0x3b) = 0;
    *(int*)(param_1 + 0x3c) = 0;
    v38 = (v38 * 2 ^ (unsigned int)v38) & 0x200 ^ (unsigned int)v38;
    *(int*)(param_1 + 0x38) = v38;
    *(int*)(param_1 + 0x38) = v38 & 0xfffffeff;

    if (*(int*)(param_1 + 0x98) == 0) {
        FUN_0041A340(param_1, 0x7d);
    }
    if (*(int*)(param_1 + 0x114) == -1) {
        *(int*)(param_1 + 0x110) = 0;
    }
    *(int*)(param_1 + 0x114) = -1;
}
}
