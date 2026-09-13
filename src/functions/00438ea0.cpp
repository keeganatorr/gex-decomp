// Adapted from pc_decomp_backup/src/functions/FUN_00438EA0.cpp
// Historical source SHA256: 8c1767692984e9fe24aafbf27111855082a1fa3b3be9c12d786781ea306a7117
extern "C" {
extern "C" { extern int DAT_00455c54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl GEX_Target(void* param_1)
{
    if ((*(unsigned char*)((char*)param_1 + 0xe1) & 0x10) != 0) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f194);
        }
        *(unsigned int*)((char*)param_1 + 0xe0) &= 0xffffefff;
        return 1;
    }
    return 0;
}
}
