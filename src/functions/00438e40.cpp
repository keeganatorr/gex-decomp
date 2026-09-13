// Adapted from pc_decomp_backup/src/functions/FUN_00438E40.cpp
// Historical source SHA256: bdf8ada82a16c859c96483ecd92e04c6468be95607d9a702c87d3e73e7634bcb
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl GEX_Target(void* param_1)
{
    if ((*(unsigned char*)((char*)param_1 + 0xe1) & 8) != 0) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f180);
        }
        *(unsigned int*)((char*)param_1 + 0xe0) &= 0xfffff7ff;
        return 1;
    }
    return 0;
}
}
