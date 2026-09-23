extern "C" {
extern int DAT_00455c54;
extern void __cdecl FUN_00405390(const char*, ...);

int __cdecl GEX_Target(int param_1)
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