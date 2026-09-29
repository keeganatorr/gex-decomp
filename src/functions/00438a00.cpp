extern "C" {
    extern int _DAT_00455c54_DebugVar;
    extern const char _DAT_0045f088[];
    extern const char s_event_hitleft_0045f09c[];
    extern void _FUN_00405390(const char*, ...);
    int event_hitleft_00438a00(int param_1);
}

int event_hitleft_00438a00(int param_1) {
    if ((*(unsigned int*)(param_1 + 0x6c) & 0x1f000000) == 0x1000000) {
        if (_DAT_00455c54_DebugVar > 1) {
            _FUN_00405390(_DAT_0045f088, *(unsigned int*)(param_1 + 8));
            _FUN_00405390(s_event_hitleft_0045f09c);
        }
        return 1;
    }
    return 0;
}
