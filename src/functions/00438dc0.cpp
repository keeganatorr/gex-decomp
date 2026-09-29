// Adapted from pc_decomp_backup/src/functions/FUN_00438DC0.cpp
// Historical source SHA256: 4ad4519f33ff868a5b70f2d5339c014c3e46af39d5e232213681e4dc918d5ad5
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl event_endPath_00438dc0(void* param_1)
{
    if ((*(unsigned char*)((char*)param_1 + 0xe0) & 0x20) != 0) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f170);
        }
        *(unsigned int*)((char*)param_1 + 0xe0) &= 0xffffffdf;
        return 1;
    }
    return 0;
}
}
