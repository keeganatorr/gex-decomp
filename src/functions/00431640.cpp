// Adapted from pc_decomp_backup/src/functions/FUN_00431640.cpp
// Historical source SHA256: 0db5293eb521d6f268d82a326dcf0df028bea7d7c497eae5dac6f8d92dd59003
extern "C" {
extern "C" void __cdecl FUN_0042f5f0(void**, int);
extern "C" void __cdecl FUN_00437310(void**);

extern "C" { extern int DAT_0045b130; }

extern "C" void __cdecl GEX_Target(void** param_1, int* param_2)
{
    int iVar1;

    if (*param_2 != 0 &&
        param_1[0x26] == (void*)0x80 &&
        ((*(unsigned char*)((int)param_1[0x5e] + 5) & 0xf) == 2) &&
        ((unsigned int)(*(int**)param_1[0x5d])[0] & 0xffff) == 1 &&
        (int)param_1[0x28] < 0) {
        DAT_0045b130 = 1;
        iVar1 = 0x14;
        do {
            FUN_0042f5f0(param_1, 0);
            iVar1 = iVar1 - 1;
        } while (iVar1 != 0);
        FUN_00437310(param_1);
        param_1[0x28] = (void*)0x14;
    }
}
}
