extern "C" {
    void __cdecl FUN_00420BC0(void**);
    void __cdecl FUN_00420960(void**);
    void __cdecl FUN_00413F10(void**);
    extern unsigned char DAT_004a0282;
    extern unsigned char DAT_004a0285;

    void __cdecl InitPlayerBounceRise_00414030(void** param_1)
    {
        void* pGVar1;
        int iVar2;
        int iVar3;
        int iVar4;
        int iVar5;

        FUN_00420BC0(param_1);

        param_1[0x1c] = (void*)5;
        param_1[0x26] = (void*)5;
        param_1[0x14] = (void*)0x2e;
        param_1[0x15] = (void*)9;

        /* short-circuit && so both failure edges target the single else store */
        if (DAT_004a0282 != 0 && DAT_004a0285 != 0) {
            param_1[0x23] = (void*)0xfff20000;
        } else {
            param_1[0x23] = (void*)0xfff60000;
        }

        param_1[0x25] = (void*)0x14000;
        param_1[0x24] = (void*)0xe0000;
        param_1[0x27] = param_1[0x23];

        pGVar1 = param_1[0x44];
        if (pGVar1 != 0) {
            iVar2 = *(int*)((char*)pGVar1 + 0x78);
            iVar3 = *(int*)((char*)pGVar1 + 0xd4);
            iVar4 = iVar2 - iVar3;      /* difference formed before the xpos load */
            iVar5 = (int)param_1[0x20];
            param_1[0x44] = (void*)0;
            param_1[0x20] = (void*)(iVar5 + iVar4);
        }

        FUN_00420960(param_1);
        FUN_00413F10(param_1);
    }
}
