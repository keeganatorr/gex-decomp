extern "C" int DAT_00455c54_DebugVar;
extern "C" char s_Object_Type___d__0045f088[];
extern "C" char s_event_hitground_0045f0ac[];
extern "C" void TracePrintf_Debug_00405390(char *, ...);

extern "C" int GEX_Target(int param_1) {
    if ((*(unsigned int *)(param_1 + 0x6c) & 0x1f000000) == 0x4000000) {
        if (DAT_00455c54_DebugVar > 1) {
            TracePrintf_Debug_00405390(s_Object_Type___d__0045f088, *(unsigned int *)(param_1 + 8));
            TracePrintf_Debug_00405390(s_event_hitground_0045f0ac);
        }
        return 1;
    }
    return 0;
}
