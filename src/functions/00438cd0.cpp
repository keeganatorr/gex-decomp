// Adapted from pc_decomp_backup/src/functions/FUN_00438CD0.cpp
// Historical source SHA256: 4371bfeaf975741f4ab14b8d646b59504474ceae635be757738f41ee4d1069c8
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl event_hitCeiling_00438cd0(void* param_1)
{
    if ((*(int*)((char*)param_1 + 0x6c) & 0x1f000000) == 0x1f000000) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f13c);
        }
        return 1;
    }
    return 0;
}
}
