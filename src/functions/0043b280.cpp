// Adapted from pc_decomp_backup/src/functions/FUN_0043B280.cpp
// Historical source SHA256: 2f26f23e8c611b684f3197eec14b6f693ef4c324413ca736331f6eb57e4e02f0
extern "C" {
extern "C" void __cdecl FUN_0041F8C0(int);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    unsigned int uVar1;
    
    uVar1 = *(unsigned int*)((char*)param_1 + 0x9c) & 1;
    *(unsigned int*)((char*)param_1 + 0x50) = (unsigned int)(uVar1 == 0);
    *(int*)((char*)param_1 + 0xc4) =
        *(int*)(&((int*)0x0045ffe8)[((uVar1 == 0) - 1) & 4 | *(unsigned int*)((char*)param_1 + 0xa0)]);
    FUN_0041F8C0(0x49);
}
}
