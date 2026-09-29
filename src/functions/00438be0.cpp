extern "C" int DAT_00455c54_DebugVar;
extern "C" char DAT_0045f088[];
extern "C" char s_event_45right_0045f10c[];
extern "C" int FUN_00405390(char *fmt, ...);

extern "C" int event_45right_00438be0(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x6c) & 0x1f000000) == 0x0e000000) {
        if (1 < DAT_00455c54_DebugVar) {
            FUN_00405390(DAT_0045f088, *(unsigned int *)(param_1 + 8));
            FUN_00405390(s_event_45right_0045f10c);
        }
        return 1;
    }
    return 0;
}
