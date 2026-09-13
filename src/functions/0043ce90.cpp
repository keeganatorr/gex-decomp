// Adapted from pc_decomp_backup/src/functions/FUN_0043CE90.cpp
// Historical source SHA256: 9a071119ef7b685270ca4c699922a06df2cb10a057c9edb57bb10b227e35656a
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void*);
extern "C" void __cdecl FUN_00434260(void*);
extern "C" void* __cdecl FUN_00435D90(void*, void*, void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int v38;
    int iRet;

    *(int*)((char*)param_1 + 0xd4) = *(int*)((char*)param_1 + 0x78);
    *(int*)((char*)param_1 + 0xd8) = *(int*)((char*)param_1 + 0x7c);
    *(int*)((char*)param_1 + 0xfc) = *(int*)((char*)param_1 + 0x6c);
    *(int*)((char*)param_1 + 0xf4) = *(int*)((char*)param_1 + 0x50);
    *(int*)((char*)param_1 + 0xf8) = *(int*)((char*)param_1 + 0x54);
    *(int*)((char*)param_1 + 0xe4) = 0;
    v38 = *(int*)((char*)param_1 + 0xe0);
    *(int*)((char*)param_1 + 0xe8) = 0;
    *(int*)((char*)param_1 + 0xec) = 0;
    *(int*)((char*)param_1 + 0xf0) = 0;
    v38 = (v38 * 2 ^ (unsigned int)v38) & 0x200 ^ (unsigned int)v38;
    *(int*)((char*)param_1 + 0xe0) = v38;
    *(int*)((char*)param_1 + 0xe0) = v38 & 0xfffffeff;

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
            int v23 = *(int*)((char*)param_1 + 0x8c);
            int v26 = *(int*)((char*)param_1 + 0x98) - 1;
            int newVal = v23 + v26 - 0xc;
            *(int*)((char*)param_1 + 0x8c) = newVal;
            if (newVal > 0xffff) {
                *(int*)((char*)param_1 + 0x8c) = newVal - 0x80;
                *(int*)((char*)param_1 + 0x54) = *(int*)((char*)param_1 + 0x54) + 1;
            }
        }
    }
    if (*(int*)((char*)param_1 + 0x114) == -1) {
        *(int*)((char*)param_1 + 0x110) = 0;
    }
    *(int*)((char*)param_1 + 0x114) = -1;
}
}
