extern "C" {
    void __cdecl FUN_00420BC0(void**);
    void __cdecl FUN_00420960(void**);
    void __cdecl FUN_00424E80(void**);
    extern int FUN_0045A6D0;
    extern int FUN_004A2A0C;
    extern unsigned char DAT_004a0294;

    void __cdecl GEX_Target(void** param_1)
    {
        FUN_00420BC0(param_1);
        param_1[0x1c] = (void*)0xd;
        param_1[0x27] = (void*)2;
        int pGVar1 = FUN_0045A6D0;
        param_1[0x25] = (void*)0x14000;
        param_1[0x21] = (void*)pGVar1;
        param_1[0x26] = (void*)1;
        param_1[0x25] = (void*)0x14000;
        param_1[0x24] = (void*)0xe0000;
        FUN_00420960(param_1);
        int demo = FUN_004A2A0C;
        DAT_004a0294 = 0;
        if (demo != 0) {
            FUN_00424E80(param_1);
        }
    }
}
