// Adapted from pc_decomp_backup/src/functions/FUN_00420210.cpp
// Historical source SHA256: ad43b2a60dedc73850fdf6f0940be540db9562a19f1e0ef24aa1603f99176663
extern "C" {
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_0040B8C0(void*, int, int*, int*);
extern "C" void __cdecl FUN_0040B940();
extern "C" void* __cdecl FUN_0040B390(int, unsigned int);
extern "C" void* __cdecl FUN_00420190(int, unsigned int);

extern "C" void* __cdecl GEX_Target(int param_1, int* param_2)
{
    int local_4;
    void* local_8;
    void* pGVar2;
    void* pNVar1;

    FUN_0040B8C0(*(void**)((int)DAT_004A2990 + 0), param_1, &local_4, (int*)&local_8);
    FUN_0040B940();
    pGVar2 = FUN_0040B390(local_4, *(unsigned int*)local_8);
    unsigned int* parallax = (unsigned int*)pGVar2;
    while (*parallax != 0) {
        *parallax = (unsigned int)FUN_00420190(local_4, *parallax);
        ++parallax;
    }
    *param_2 = local_4;
    return pGVar2;
}
}
