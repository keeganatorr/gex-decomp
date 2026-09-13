// Adapted from pc_decomp_backup/src/functions/FUN_00418D70.cpp
// Historical source SHA256: 8bb76d5af89c08ded573719e11e7a675bb83f62f605ba6c295466c5d8328effe
extern "C" {
extern "C" void __cdecl FUN_00420770(void**, unsigned int);

extern "C" void* __cdecl GEX_Target(unsigned char* param_1, int param_2)
{
    unsigned char bVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int local_8;
    int local_4;

    bVar1 = *param_1;
    iVar5 = *(int*)(param_2 + 0x15c);
    if (iVar5 != 0) {
        iVar4 = 0;
        iVar3 = 0;
        local_8 = *(int*)(param_2 + 0x78);
        local_4 = *(int*)(param_2 + 0x7c);
        iVar2 = *(int*)(iVar5 + 0x15c);
        while (iVar2 != 0) {
            iVar4 = iVar4 + *(int*)(iVar5 + 0x78);
            iVar3 = iVar3 + *(int*)(iVar5 + 0x7c);
            iVar5 = *(int*)(iVar5 + 0x15c);
            iVar2 = *(int*)(iVar5 + 0x15c);
        }
        *(int*)(param_2 + 0x78) = *(int*)(iVar5 + 0x78) + iVar4 + local_8;
        *(int*)(param_2 + 0x7c) = *(int*)(iVar5 + 0x7c) + iVar3 + local_4;
    }
    FUN_00420770((void**)param_2, (unsigned int)bVar1);
    if (iVar5 != 0) {
        *(int*)(param_2 + 0x78) = local_8;
        *(int*)(param_2 + 0x7c) = local_4;
    }
    return param_1 + 1;
}
}
