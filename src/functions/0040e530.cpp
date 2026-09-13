// Adapted from pc_decomp_backup/src/functions/FUN_0040E530.cpp
// Historical source SHA256: 8e765beeaf18c4bcf513f0d8445413ebd020e311d836cc16e5d79f3f7676ce33
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1)
{
    *(unsigned int*)((char*)param_1 + 0x98) = 1;
    *(unsigned int*)((char*)param_1 + 0x9c) = 0;
    *(unsigned int*)((char*)param_1 + 0xe0) |= 0x1000000;
}
}
