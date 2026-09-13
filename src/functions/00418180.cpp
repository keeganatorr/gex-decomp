// Adapted from pc_decomp_backup/src/functions/FUN_00418180.cpp
// Historical source SHA256: 030e13063a81fc3403b7faac350150dc1b1f168e7b33f1684f69a13a2725b5d0
extern "C" {
extern void* DAT_0049FB94;
extern "C" int __cdecl FUN_00419C00(void*, unsigned int, unsigned int, int*, int*);

extern "C" void* __cdecl GEX_Target(unsigned char* param_1, void** param_2)
{
    int iVar1;
    int local_8;
    int local_4;

    if (param_2[0x57] == (void*)0x0) {
        iVar1 = FUN_00419C00(DAT_0049FB94, (unsigned int)*param_1, (unsigned int)param_1[1], &local_8, &local_4);
        if (iVar1 != 0) {
            param_2[0x1e] = (void*)(*(int*)(local_8 + 0x78) + (int)param_2[0x1e] - 0x1c);
            param_2[0x1f] = (void*)(*(int*)(local_4 + 0x78) + (int)param_2[0x1f] - 0x1c);
        }
    } else {
        iVar1 = FUN_00419C00(param_2[0x57], (unsigned int)*param_1, (unsigned int)param_1[1], &local_8, &local_4);
        if (iVar1 != 0) {
            param_2[0x1e] = (void*)local_8;
            param_2[0x1f] = (void*)local_4;
            return param_1 + 2;
        }
    }
    return param_1 + 2;
}
}
