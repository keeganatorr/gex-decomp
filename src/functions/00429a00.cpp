// Adapted from pc_decomp_backup/src/functions/FUN_00429A00.cpp
// Historical source SHA256: 46c847bd124590169f07159b8710ec084fde20cd9552050e4b55c8d923c13776
extern "C" {
extern "C" { extern unsigned char BYTE_ARRAY_004a2540[]; }
extern "C" { extern int FUN_0045ACC0; }

extern "C" void __cdecl GEX_Target(int param_1)
{
    int iVar1;
    unsigned int uVar2;

    iVar1 = *(int*)(param_1 + 0x9c);
    if (iVar1 == -1) {
        *(int*)(param_1 + 0x54) = -1;
    }
    else {
        uVar2 = *(unsigned int*)(param_1 + 0xa4);
        if ((uVar2 & 0x40000000) == 0) {
            if ((uVar2 & 0x200) == 0) {
                *(int*)(param_1 + 0x54) = 0;
            }
            else if ((BYTE_ARRAY_004a2540[iVar1] & 1) == 0) {
                *(int*)(param_1 + 0x54) = -1;
                *(unsigned int*)(param_1 + 0xa4) = uVar2 | 0x400;
            }
            else {
                *(int*)(param_1 + 0x54) = 0;
                *(unsigned int*)(param_1 + 0xa4) = uVar2 & 0xfffffbff;
            }
        }
        else {
            *(int*)(param_1 + 0x54) = -1;
            if ((BYTE_ARRAY_004a2540[iVar1] & 1) == 0) {
                *(unsigned int*)(param_1 + 0xa4) = uVar2 | 0x400;
            }
            else {
                *(unsigned int*)(param_1 + 0xa4) = uVar2 & 0xfffffbff;
            }
        }
    }
    if ((*(unsigned int*)(param_1 + 0xa4) & 0x20000000) != 0) {
        if ((BYTE_ARRAY_004a2540[iVar1] & 1) != 0) {
            FUN_0045ACC0 = 0;
            return;
        }
        FUN_0045ACC0 = -1;
    }
}
}
