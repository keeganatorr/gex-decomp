extern "C" {
    void __cdecl FUN_00423CB0(void**);
    void __cdecl FUN_00405350(const char*);
    extern void* PTR_004a2a10;
    extern const char DAT_0045ab14[];
}

extern "C" void __cdecl InitPlayerOldMan_00423d20(void** param_1)
{
    void* pGVar1;
    void* pNVar2;
    void* pGVar3;

    param_1[0x1c] = (void*)0xB;
    pGVar1 = param_1[3];
    pGVar3 = PTR_004a2a10;
    param_1[4] = (void*)0x0;
    param_1[3] = pGVar3;
    pNVar2 = *(void**)((char*)PTR_004a2a10 + 4);
    if (pNVar2 != (void*)0x0 &&
        (pNVar2 = *(void**)pNVar2, pNVar2 != (void*)0x0) &&
        (pGVar3 = *(void**)pNVar2, pGVar3 != (void*)0x0)) {
        param_1[4] = pGVar3;
    }
    if (param_1[4] == (void*)0x0) {
        FUN_00405350(DAT_0045ab14);
    }
    param_1[3] = pGVar1;
    FUN_00423CB0(param_1);
}
