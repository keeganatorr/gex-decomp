// Adapted from pc_decomp_backup/src/functions/FUN_0043A780.cpp
// Historical source SHA256: 44cadac567b075e7640356382d9af190d605af3596cf976c420dfc0da8cf31ad
extern "C" {
extern "C" void __cdecl FUN_00441150(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int val = *(int*)((char*)param_1 + 0x9c);
    if (val == 1 || val == 3 || val == 4 || val == 5 || val == 6) {
        *(int*)((char*)param_1 + 0xc4) = 0;
    }
    FUN_00441150(param_1);
}
}
