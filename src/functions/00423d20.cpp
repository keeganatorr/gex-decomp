// Adapted from pc_decomp_backup/src/functions/FUN_00423D20.cpp
// Historical source SHA256: 91f1248f596606575c800c6327a7f98d584e30893d420c3d238b84f1b0c24cdc
extern "C" {
extern "C" void __cdecl FUN_00423CB0(void**);
extern "C" void __cdecl FUN_00405350(const char*, int);

extern "C" { extern void* PTR_004a2a10; }
extern "C" { extern const char DAT_0045ab14[]; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar1;
    void* pNVar2;
    void* pGVar3;
    int unaff_EDI;

    param_1[0x1c] = (void*)0xB;
    pGVar3 = PTR_004a2a10;
    pGVar1 = param_1[3];
    param_1[4] = (void*)0x0;
    param_1[3] = pGVar3;
    pNVar2 = *(void**)((char*)PTR_004a2a10 + 4);
    if (pNVar2 != (void*)0x0 &&
        (pNVar2 = *(void**)pNVar2, pNVar2 != (void*)0x0) &&
        (pGVar3 = *(void**)pNVar2, pGVar3 != (void*)0x0)) {
        param_1[4] = pGVar3;
    }
    if (param_1[4] == (void*)0x0) {
        FUN_00405350(DAT_0045ab14, unaff_EDI);
    }
    param_1[3] = pGVar1;
    FUN_00423CB0(param_1);
}
}
