extern "C" int DAT_00455c54_DebugVar;
extern "C" int TracePrintf_Debug_00405390(char *fmt, ...);
extern "C" char s_Object_Type___d__0045f088[];
extern "C" char s_event_gotSpit_0045f160[];

extern "C" int event_gotSpit_00438d70(int param_1)
{
    unsigned char *base = (unsigned char *)param_1;
    if ((base[0xe0] & 8) != 0) {
        if (1 < DAT_00455c54_DebugVar) {
            TracePrintf_Debug_00405390(s_Object_Type___d__0045f088, *(int *)(base + 8));
            TracePrintf_Debug_00405390(s_event_gotSpit_0045f160);
        }
        return 1;
    }
    return 0;
}
