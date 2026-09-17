extern "C" {
    void __cdecl FUN_00420BC0(void**);
    void __cdecl FUN_00415600(void**);
    extern int FUN_004A2800;
    extern int DAT_004a0214_HighJump;
    extern int FUN_004A287C;
    extern int DAT_004a2884;
    extern int FUN_0045A6D0;

    void __cdecl GEX_Target(void** param_1)
    {
        void* pGVar1;
        FUN_00420BC0(param_1);
        param_1[0x1c] = (void*)0x53;
        param_1[0x14] = (void*)0x27;
        param_1[0x15] = (void*)1;
        param_1[0x23] = (void*)FUN_004A2800;
        param_1[0x26] = (void*)(DAT_004a0214_HighJump == 0 ? 5 : 8);
        param_1[0x27] = (void*)FUN_004A2800;
        param_1[0x28] = (void*)FUN_004A287C;
        pGVar1 = (void*)DAT_004a2884;
        param_1[0x25] = (void*)0x14000;
        param_1[0x24] = (void*)0xe0000;
        param_1[0x20] = pGVar1;
        param_1[0x21] = (void*)FUN_0045A6D0;
        FUN_00415600(param_1);
    }
}
