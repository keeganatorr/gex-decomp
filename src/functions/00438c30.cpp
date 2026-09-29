// Adapted from pc_decomp_backup/src/functions/FUN_00438C30.cpp
// Historical source SHA256: 16642f06a3fa75d71002a23e700a45bcd8334e97cab4e6390fea84c3efff385f
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl event_45left_00438c30(void* param_1)
{
    if ((*(int*)((char*)param_1 + 0x6c) & 0x1f000000) == 0x0d000000) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f11c);
        }
        return 1;
    }
    return 0;
}
}
