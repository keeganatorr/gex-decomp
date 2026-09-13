// Adapted from pc_decomp_backup/src/functions/FUN_0043D230.cpp
// Historical source SHA256: 9d3fbdd7809da8dd9b1934b783a59ac82160ccbb0aa6392ba871e7ce387e1125
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(int*);
extern "C" void __cdecl FUN_00434260(int*);

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int v38;
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

    iRet = FUN_0040FCE0(param_1);
    if (iRet == 0) {
        if (*(int*)(param_1 + 0xa4) != 0) {
            FUN_00434260(param_1);
        }
        if (*(int*)(param_1 + 0x98) != 0) {
            int v26 = *(int*)(param_1 + 0x98) - 1;
            int v23 = *(int*)(param_1 + 0x8c);
            int newVal = v23 + v26 - 0xc;
            *(int*)(param_1 + 0x8c) = newVal;
            if (newVal > 0xffff) {
                *(int*)(param_1 + 0x8c) = newVal - 0x80;
                *(int*)(param_1 + 0x54) = *(int*)(param_1 + 0x54) + 1;
            }
        }
    }
    if (*(int*)(param_1 + 0x114) == -1) {
        *(int*)(param_1 + 0x110) = 0;
    }
    *(int*)(param_1 + 0x114) = -1;
}
}
