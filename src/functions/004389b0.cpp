extern "C" int DAT_00455c54_DebugVar;
extern "C" int FUN_00405390(const char *, ...);
extern "C" char DAT_0045f088[];
extern "C" char s_event_hitright_0045f078[];

extern "C" int GEX_Target(int objectType)
{
    if ((*(unsigned int *)(objectType + 0x6c) & 0x1f000000) == 0x2000000) {
        if (DAT_00455c54_DebugVar > 1) {
            FUN_00405390(DAT_0045f088, *(unsigned int *)(objectType + 0x8));
            FUN_00405390(s_event_hitright_0045f078);
        }
        return 1;
    }
    return 0;
}
