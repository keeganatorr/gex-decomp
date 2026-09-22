extern "C" {
    extern int DAT_00456B00;
    extern int DAT_004A2964;
    extern int DAT_004A2990;
    int FUN_0040AA60(void);
    void FUN_0040a990_LoadLevel_Clean1(void);
    int FUN_0041ECD0(int);
    void FUN_00402fa0_GetFrameTimingValue(void);
    void FUN_0043eed0_TvStatic(void);
    void FUN_0043f080_ResetGraphics_Clean1(int);
    void FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);
    void FUN_0043db70(int);
    void FUN_00440930_ContainsInput_POSSMAINGAMELOOP(void);
    void FUN_00440a30_ContainsInput_CallsInputFunction_MAINGAMELOOP(void);
    void FUN_0043f490(int, int, int, int, int, int, int);
    void FUN_0043f580(void);

    void GEX_Target(void) {
        if (DAT_00456B00 == 0) {
            DAT_004A2964 = 0x42;
            FUN_0040AA60();
            FUN_0040a990_LoadLevel_Clean1();
            if (FUN_0041ECD0(DAT_004A2990) == 0) {
                do {
                    FUN_00402fa0_GetFrameTimingValue();
                    FUN_0043eed0_TvStatic();
                    FUN_0043f080_ResetGraphics_Clean1(0);
                    FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(1);
                    FUN_0043db70(1);
                } while (FUN_0041ECD0(DAT_004A2990) == 0);
            }
        } else {
            FUN_0040AA60();
            FUN_0040a990_LoadLevel_Clean1();
            FUN_0041ECD0(DAT_004A2990);
            FUN_00440930_ContainsInput_POSSMAINGAMELOOP();
            FUN_0041ECD0(DAT_004A2990);
            FUN_00440a30_ContainsInput_CallsInputFunction_MAINGAMELOOP();
            FUN_0041ECD0(DAT_004A2990);
            FUN_0043f490(6, 0, 0, 0, 0, 0, 0);
            FUN_0043f580();
            FUN_0043f080_ResetGraphics_Clean1(1);
        }
    }
}
