// Adapted from pc_decomp_backup/src/functions/FUN_0042E8B0.cpp
// Historical source SHA256: 24a69edc1ae2ed76848cc1b300d242341500937c87e27b907885361168b0e5fb
extern "C" {
extern "C" { extern int DAT_00455B88; }
extern "C" { extern int DAT_0045B098; }
extern "C" { extern int DAT_0049fba0; }
extern "C" void* __cdecl FUN_00433590(void**, void*, void*, int);

extern "C" int __cdecl GEX_Target(void** param_1, int param_2)
{
    int* ps;
    void** pd;
    int i;
    void* pSVar1;

    if (param_2 == 4) {
        DAT_00455B88 = 1;
    }
    if (DAT_0045B098 != param_2) {
        ps = (int*)((int)&DAT_0049fba0 + param_2 * 0x20);
        pd = param_1 + 4;
        i = 8;
        do {
            *pd = (void*)*ps;
            ps++;
            pd++;
            i--;
        } while (i != 0);
    }
    pSVar1 = FUN_00433590(param_1, param_1 + 4, (void*)param_1[4], 0);
    param_1[4] = pSVar1;
    DAT_0045B098 = param_2;
    if (param_1[4] != (void*)0x0) {
        return 0;
    }
    ps = (int*)((int)&DAT_0049fba0 + param_2 * 0x20);
    pd = param_1 + 4;
    i = 8;
    do {
        *pd = (void*)*ps;
        ps++;
        pd++;
        i--;
    } while (i != 0);
    return 1;
}
}
