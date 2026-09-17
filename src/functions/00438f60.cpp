extern "C" {
    extern int DAT_004A2964;
    extern char DAT_004A0280;
    extern char DAT_004A0281;
    extern char DAT_004A0282;
    extern char DAT_004A0283;
    extern char DAT_004A0284;
    extern char DAT_004A0285;
    extern char DAT_004A0286;
    extern int DAT_00455c54_DebugVar;
    extern const char DAT_0045f088[];
    extern const char s_event_buttonpressed_0045f1b8[];
    void FUN_00405390(const char *format, ...);
}

extern "C" int GEX_Target(char *opjectType)
{
    if (DAT_004A2964 != 0x44 &&
        (DAT_004A0282 != '\0' ||
         DAT_004A0283 != '\0' ||
         DAT_004A0280 != '\0' ||
         DAT_004A0281 != '\0' ||
         DAT_004A0286 != '\0' ||
         DAT_004A0285 != '\0' ||
         DAT_004A0284 != '\0')) {
        if (1 < DAT_00455c54_DebugVar) {
            FUN_00405390(DAT_0045f088, *(int *)(opjectType + 8));
            FUN_00405390(s_event_buttonpressed_0045f1b8);
        }
        return 1;
    }
    return 0;
}
