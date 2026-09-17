extern "C" int FUN_0041FB50(void);
extern "C" int DAT_00455c54_DebugVar;
extern "C" int FUN_00405390(const char *, ...);
extern "C" const char DAT_0045f088[];
extern "C" const char s_event_voicefinished_0045f1d0[];

extern "C" int GEX_Target(int param_1)
{
    if (FUN_0041FB50() != 0) {
        if (1 < DAT_00455c54_DebugVar) {
            FUN_00405390(DAT_0045f088, *(int *)(param_1 + 8));
            FUN_00405390(s_event_voicefinished_0045f1d0);
        }
        return 1;
    }
    return 0;
}
