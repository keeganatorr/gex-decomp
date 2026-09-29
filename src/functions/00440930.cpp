typedef struct StaticTile { int unk[3]; } StaticTile;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;
    BUTTON_RECORD gxir_padJustOnButtons;
    unsigned char _pad1e[2];
    int gxir_dValue;
} GXInputRecord;
extern "C" {
extern StaticTile DAT_0046BCC8;
extern StaticTile DAT_0046BCD4;
extern StaticTile DAT_0046BCE0;
extern StaticTile DAT_0046BCEC;
extern int DAT_00460f48;
extern int DAT_00460f4c;
extern GXInputRecord gInputControllers_004a0280[];
void __cdecl FUN_00402fa0_GetFrameTimingValue(void);
void __cdecl FUN_0043eed0_TvStatic(void);
void __cdecl FUN_0043f080_ResetGraphics_Clean1(int all);
void __cdecl GXINP_ReadPads_0041fc40(void);
void __cdecl FUN_00444800_Tiles(StaticTile *tile, int x, int y, int width, int height, int image, int colour);
void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int flag);
void __cdecl CEL_DrawCels_0043db70(int flag);
void __cdecl FUN_00440930_ContainsInput_POSSMAINGAMELOOP(void)
{
    int height;
    int bottom;
    int lower;
    height = 0x10000;
    do {
        lower = height + 0x10000;
        FUN_00402fa0_GetFrameTimingValue();
        FUN_0043eed0_TvStatic();
        FUN_0043f080_ResetGraphics_Clean1(0);
        GXINP_ReadPads_0041fc40();
        bottom = 0xf00000 - height;
        FUN_00444800_Tiles(&DAT_0046BCC8, 0, 0, 0xa00000, height, DAT_00460f48, 0x1f001f00);
        FUN_00444800_Tiles(&DAT_0046BCD4, 0xa00000, 0, 0xa00000, height, DAT_00460f48, 0x1f001f00);
        FUN_00444800_Tiles(&DAT_0046BCE0, 0, bottom, 0xa00000, lower, DAT_00460f48, 0x1f001f00);
        FUN_00444800_Tiles(&DAT_0046BCEC, 0xa00000, bottom, 0xa00000, lower, DAT_00460f48, 0x1f001f00);
        height += (0x780000 - height) / DAT_00460f4c;
        if (height >= 0x770000)
            break;
        FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(1);
        CEL_DrawCels_0043db70(1);
    } while (!gInputControllers_004a0280[0].gxir_padButtons.buttonA);
}
}
