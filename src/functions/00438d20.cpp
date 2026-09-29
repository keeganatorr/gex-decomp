// Adapted from pc_decomp_backup/src/functions/FUN_00438D20.cpp
// Historical source SHA256: b2e58415b9de3ca5540dc6038e7d92ebbb17283f76f6f8a05d953d270de60f45
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl event_topWall_00438d20(void* param_1)
{
    if ((*(int*)((char*)param_1 + 0x6c) & 0x1f000000) == 0x03000000) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f150);
        }
        return 1;
    }
    return 0;
}
}
