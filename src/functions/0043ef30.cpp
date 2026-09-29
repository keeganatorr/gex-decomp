typedef struct GfxBuffer { int unk[5]; } GfxBuffer;              /* 0x14 bytes */
typedef struct GfxSurface {
    unsigned char unk0[0x16];
    unsigned char flag16;   /* 0x16 */
    unsigned char flag17;   /* 0x17 */
    unsigned char flag18;   /* 0x18 */
    unsigned char unk19[0x43];
} GfxSurface;                                                      /* 0x5c bytes */
extern "C" {
extern char s_GFX_Init_00460dc0[];
extern GfxBuffer DAT_0046A560[2];
extern GfxSurface DAT_0046A588[2];
extern int DAT_004a2b08_GFXInit9;
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl FUN_00444c90_InitTiles_TrueMaybe(int flag);
void __cdecl FUN_00445380_GFXInit1(int flag);
void __cdecl FUN_00445280_GFXInit2(GfxBuffer *buffer, int x, int y, int width, int height);
void __cdecl FUN_004452d0_GFXInit3(GfxSurface *surface, int x, int y, int width, int height);
void __cdecl GFX_Init_0043ef30(void)
{
    TracePrintf_Debug_00405390(s_GFX_Init_00460dc0);
    FUN_00444c90_InitTiles_TrueMaybe(0);
    FUN_00445380_GFXInit1(0);
    FUN_00445280_GFXInit2(&DAT_0046A560[0], 0, 0, 320, 240);
    FUN_00445280_GFXInit2(&DAT_0046A560[1], 0, 240, 320, 240);
    FUN_004452d0_GFXInit3(&DAT_0046A588[0], 0, 240, 320, 240);
    FUN_004452d0_GFXInit3(&DAT_0046A588[1], 0, 0, 320, 240);
    DAT_0046A588[1].flag17 = 1;
    DAT_0046A588[0].flag17 = 1;
    DAT_0046A588[1].flag18 = 1;
    DAT_0046A588[0].flag18 = 1;
    DAT_0046A588[1].flag16 = 0;
    DAT_0046A588[0].flag16 = 0;
    DAT_004a2b08_GFXInit9 = 0;
}
}
