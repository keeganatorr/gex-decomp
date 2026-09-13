// Adapted from pc_decomp_backup/src/functions/FUN_0043B2E0.cpp
// Historical source SHA256: e537acbe251ddc6054c7546585beaca2c1b2e57d81eaa4ccf59e2044775449b6
extern "C" {
extern "C" { extern int DAT_004a2824; }
extern "C" { extern int DAT_004a285c; }
extern "C" { extern int DAT_004a2880; }
extern "C" { extern int DAT_004a283c; }
extern "C" { extern int DAT_004a2844; }
extern "C" { extern int DAT_004a2834; }
extern "C" { extern int DAT_00460008[]; }
extern "C" { extern int DAT_0046000c[]; }

extern "C" void __cdecl GEX_Target(int param_1, int* param_2)
{
    int uVar1;

    if (*param_2 != 0) {
        DAT_004a2824 = 1;
        DAT_004a285c = ~*(unsigned int*)(param_1 + 0x9c) & 1;
        if ((**(unsigned int**)(param_1 + 0x170) & 0xffff) == 8) {
            DAT_004a2880 = 1;
            DAT_004a283c = *(int*)(param_1 + 0xa0);
        }
        uVar1 = *(int*)(param_1 + 0x54);
        *(int*)(param_1 + 0x54) = 0;
        DAT_004a2844 = DAT_00460008[*(int*)(param_1 + 0xa0) * 2] + *(int*)(param_1 + 0x78);
        DAT_004a2834 = DAT_0046000c[*(int*)(param_1 + 0xa0) * 2] + *(int*)(param_1 + 0x7c);
        *(int*)(param_1 + 0x54) = uVar1;
    }
}
}
