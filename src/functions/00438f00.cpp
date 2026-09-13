// Adapted from pc_decomp_backup/src/functions/FUN_00438F00.cpp
// Historical source SHA256: 987640780eb322fd2e4d7811349d34a95c13e91bacd869a75337ee85b5752364
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl GEX_Target(void* param_1)
{
    if ((*(unsigned char*)((char*)param_1 + 0xe1) & 0x80) != 0) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f1a8);
        }
        *(unsigned int*)((char*)param_1 + 0xe0) &= 0xffff7fff;
        return 1;
    }
    return 0;
}
}
