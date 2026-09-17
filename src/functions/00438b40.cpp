extern "C" {
extern volatile int DAT_00455c54_DebugVar;
extern void FUN_00405390(const char *, ...);
extern char DAT_0045f088[];
extern char s_event_ledgeright_0045f0e4[];
}

extern "C" int GEX_Target(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x6c) & 0x1f000000) == 0x6000000) {
        if (DAT_00455c54_DebugVar > 1) {
            FUN_00405390(DAT_0045f088, *(int *)(param_1 + 8));
            FUN_00405390(s_event_ledgeright_0045f0e4);
        }
        return 1;
    }
    return 0;
}
