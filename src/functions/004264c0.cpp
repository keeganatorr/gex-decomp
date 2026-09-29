typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;        /* 0x0 */
    BUTTON_RECORD gxir_padJustOnButtons;  /* 0xf */
    unsigned char _pad1e[2];
    int gxir_dValue;                      /* 0x20 */
} GXInputRecord;
extern "C" {
extern GXInputRecord gInputControllers_004a0280[];
extern int DAT_00463aa8;
extern int DAT_004a022c;
int __cdecl abs(int);
void __cdecl FUN_00423800_pStateUnk(GXObject *gex);
int __cdecl FUN_00423910_pStateUnk(GXObject *gex);
int __cdecl FUN_00423960_pStateUnk(GXObject *gex);
int __cdecl FUN_004239b0_pStateUnk(GXObject *gex);
int __cdecl FUN_00423a00_pStateUnk(GXObject *gex);
int __cdecl FUN_00423a50_AirToFaceCrawl(GXObject *gex);
void __cdecl InitPlayerFaceCrawlToAir_004144e0(GXObject *gex);
void __cdecl InitPlayerFaceStick_00426ca0(GXObject *gex);
void __cdecl PlayerFaceTurn_004264c0(GXObject *gex)
{
    int diff;
    int step;
    FUN_00423800_pStateUnk(gex);
    if (!gex->gob_work0) {
        if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
            DAT_00463aa8 = 0x400000;
        else if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
            DAT_00463aa8 = 0xc00000;
        else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
            DAT_00463aa8 = 0x800000;
        else if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp)
            DAT_00463aa8 = 0;
    }
    diff = DAT_00463aa8 - gex->gob_angle;
    step = abs(diff);
    if (step > 0x800000)
        diff = -diff;
    step = step < 0x100000 ? step : 0x100000;
    if (diff > 0)
        gex->gob_angle += step;
    else
        gex->gob_angle -= step;
    gex->gob_angle &= 0xff0000;
    if (!FUN_00423910_pStateUnk(gex))
        gex->gob_xpos += 0x40000;
    if (!FUN_00423960_pStateUnk(gex))
        gex->gob_xpos -= 0x40000;
    if (!FUN_004239b0_pStateUnk(gex))
        gex->gob_ypos += 0x40000;
    if (!FUN_00423a00_pStateUnk(gex))
        gex->gob_ypos -= 0x40000;
    if (!(gex->gob_angle & 0x3f0000) && !FUN_00423a50_AirToFaceCrawl(gex))
        InitPlayerFaceCrawlToAir_004144e0(gex);
    if (gex->gob_angle == DAT_00463aa8)
        InitPlayerFaceStick_00426ca0(gex);
    DAT_004a022c = 1;
}
}
