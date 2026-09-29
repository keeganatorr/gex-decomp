extern "C" int __cdecl FUN_0040FCE0(void*);
extern "C" void __cdecl FUN_00434260(void*);
extern "C" void* __cdecl FUN_00435D90(void*, void*, void*);

extern "C" void __cdecl ob89DoIt_0043ce90(void* param_1)
{
    int iRet;
    *(int*)((char*)param_1 + 0xd4) = *(int*)((char*)param_1 + 0x78);
    *(int*)((char*)param_1 + 0xd8) = *(int*)((char*)param_1 + 0x7c);
    *(int*)((char*)param_1 + 0xfc) = *(int*)((char*)param_1 + 0x6c);
    *(int*)((char*)param_1 + 0xf4) = *(int*)((char*)param_1 + 0x50);
    *(int*)((char*)param_1 + 0xf8) = *(int*)((char*)param_1 + 0x54);
    *(int*)((char*)param_1 + 0xe4) = 0;
    *(int*)((char*)param_1 + 0xe8) = 0;
    *(int*)((char*)param_1 + 0xec) = 0;
    *(int*)((char*)param_1 + 0xf0) = 0;
    *(unsigned int*)((char*)param_1 + 0xe0) ^= ((*(unsigned int*)((char*)param_1 + 0xe0) * 2 ^ *(unsigned int*)((char*)param_1 + 0xe0)) & 0x200);
    *(unsigned int*)((char*)param_1 + 0xe0) &= 0xfffffeff;
    iRet = FUN_0040FCE0(param_1);
    if (iRet == 0) {
        if (*(int*)((char*)param_1 + 0xa4) != 0) {
            FUN_00434260(param_1);
        }
        if (*(int*)((char*)param_1 + 0x10) != 0) {
            *(int*)((char*)param_1 + 0x10) = (int)FUN_00435D90(param_1, (char*)param_1 + 0x10, *(void**)((char*)param_1 + 0x10));
        }
        if (*(int*)((char*)param_1 + 0x30) != 0) {
            *(int*)((char*)param_1 + 0x30) = (int)FUN_00435D90(param_1, (char*)param_1 + 0x30, *(void**)((char*)param_1 + 0x30));
        }
        if (*(int*)((char*)param_1 + 0x98) != 0) {
            int newVal = *(int*)((char*)param_1 + 0x98) + *(int*)((char*)param_1 + 0x8c);
            *(int*)((char*)param_1 + 0x8c) = newVal;
            if (newVal >= 0x10000) {
                *(int*)((char*)param_1 + 0x8c) = newVal - 0x10000;
                *(int*)((char*)param_1 + 0x54) = *(int*)((char*)param_1 + 0x54) + 1;
            }
        }
    }
    if (*(int*)((char*)param_1 + 0x114) == -1) {
        *(int*)((char*)param_1 + 0x110) = 0;
    }
    *(int*)((char*)param_1 + 0x114) = -1;
}
