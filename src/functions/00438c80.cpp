extern "C" int DAT_00455c54_DebugVar;
extern "C" char DAT_0045f088[];
extern "C" char s_event_pCall_0045f12c[];
extern "C" int FUN_00405390(char *format, ...);

extern "C" int __cdecl GEX_Target(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x6c) & 0x20000000) != 0) {
        if (1 < DAT_00455c54_DebugVar) {
            FUN_00405390(DAT_0045f088, *(int *)(param_1 + 8));
            FUN_00405390(s_event_pCall_0045f12c);
        }
        return 1;
    }
    return 0;
}
