extern "C" {
extern int DAT_00455c54_DebugVar;
extern void __cdecl FUN_00405390(const char*, ...);

int __cdecl GEX_Target(void* param_1)
{
    int state = *(unsigned short*)((char*)param_1 + 0xe0);
    if ((state & 0x0800) != 0) {
        if (DAT_00455c54_DebugVar > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f180);
        }
        *(unsigned int*)((char*)param_1 + 0xe0) &= 0xfffff7ff;
        return 1;
    }
    return 0;
}
}