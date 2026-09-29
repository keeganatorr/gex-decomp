extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void* __cdecl FUN_00435D90(void**, void*, void*);
extern "C" void __cdecl FUN_00434260(void**);
extern "C" void __cdecl ob121DoIt_0043d3e0(void** param1) {
    param1[0x35] = param1[0x1e];
    param1[0x36] = param1[0x1f];
    param1[0x3f] = param1[0x1b];
    param1[0x3d] = param1[0x14];
    param1[0x3e] = param1[0x15];
    param1[0x39] = 0;
    param1[0x3a] = 0;
    param1[0x3b] = 0;
    param1[0x3c] = 0;
    ((unsigned int*)param1)[0x38] ^= ((((unsigned int*)param1)[0x38] * 2) ^ ((unsigned int*)param1)[0x38]) & 0x200;
    ((unsigned int*)param1)[0x38] &= 0xfffffeff;
    int iVar2 = FUN_0040FCE0(param1);
    if (iVar2 == 0) {
        if (param1[4] != 0)
            param1[4] = FUN_00435D90(param1, param1 + 4, param1[4]);
        if (param1[0xc] != 0)
            param1[0xc] = FUN_00435D90(param1, param1 + 0xc, param1[0xc]);
        if (param1[0x26] != 0) {
            void* pGVar1 = (void*)((unsigned int)param1[0x23] + (unsigned int)param1[0x26]);
            param1[0x23] = pGVar1;
            if ((int)pGVar1 >= 0x10000) {
                param1[0x23] = (void*)((unsigned int)pGVar1 - 0x10000);
                param1[0x15] = (void*)((unsigned int)param1[0x15] + 1);
            }
        }
        FUN_00434260(param1);
    }
    if (param1[0x45] == (void*)-1)
        param1[0x44] = 0;
    param1[0x45] = (void*)-1;
}
