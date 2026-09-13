// Adapted from pc_decomp_backup/src/functions/FUN_0041CA10.cpp
// Historical source SHA256: 5a9a3c8a4bf8938f5441073b7b08ce69f89e63e98d8cf9cc87e83753c08a4605
extern "C" {
extern "C" void __cdecl FUN_0042CC50(void**);
extern "C" void* __cdecl FUN_004096C0(int size);
extern "C" void __cdecl FUN_0042CC00(void**, void**);

extern "C" { extern void* FUN_00463728; }
extern "C" { extern void* FUN_00463680; }
extern "C" { extern void* FUN_00463698; }
extern "C" { extern void* DAT_0046371d_ObjectListEnd; }

extern "C" void __cdecl GEX_Target()
{
    int* loaded_gOb;
    void** ppGVar1;
    int iVar2;

    FUN_0042CC50((void**)&FUN_00463728);
    FUN_0042CC50((void**)&FUN_00463680);
    iVar2 = 100;
    loaded_gOb = (int*)FUN_004096C0(0x4b0);
    do {
        FUN_0042CC00((void**)&FUN_00463728, (void**)loaded_gOb);
        iVar2 = iVar2 - 1;
        loaded_gOb = loaded_gOb + 3;
    } while (iVar2 != 0);
    ppGVar1 = (void**)&FUN_00463698;
    do {
        FUN_0042CC50(ppGVar1);
        ppGVar1 = ppGVar1 + 3;
    } while (ppGVar1 < (void**)&DAT_0046371d_ObjectListEnd);
}
}
