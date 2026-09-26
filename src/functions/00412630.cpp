typedef struct TurnStep { int dx; int dy; } TurnStep;
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned int gob_work1;     /* 0x9c */
    unsigned char _pada0[0xc4 - 0xa0];
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
extern int DAT_00458c78_ButtonUnk10;
extern TurnStep DAT_004586d8[];
extern unsigned int DAT_00458068[];
int __cdecl FUN_00421f20_pStateUnk_Side(GXObject *gex);
void __cdecl FUN_00421cd0_xpos_ypos_related(GXObject *gex);
void __cdecl InitPlayerSideCrawl_00411160(GXObject *gex);
void __cdecl InitPlayerSideJump_004138b0(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    unsigned int flags;
    unsigned int dir;
    int step;
    TurnStep *entry;
    if (!DAT_00458c78_ButtonUnk10 && !gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB) {
        if (FUN_00421f20_pStateUnk_Side(gex)) {
            FUN_00421cd0_xpos_ypos_related(gex);
            if ((gex->gob_work0 += 0x10000) > 0x10000) {
                gex->gob_work0 -= 0x10000;
                gex->gob_currentFrameIndex++;
                if (gex->gob_work1 & 0x10) {
                    step = (gex->gob_work1 & 0xf) << 3;
                    gex->gob_xpos += -(*(int *)((char *)DAT_004586d8 + step) * 5 << 16);
                    gex->gob_ypos += -(*(int *)((char *)DAT_004586d8 + step + 4) * 5 << 16);
                }
                if (gex->gob_currentFrameIndex > 3) {
                    flags = gex->gob_flags;
                    dir = DAT_00458068[(flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21];
                    gex->gob_angle = (dir & 7) << 21;
                    flags &= 0x7fffffff;
                    gex->gob_flags = flags;
                    if (dir & 8) {
                        flags |= 0x80000000;
                        gex->gob_flags = flags;
                    }
                    InitPlayerSideCrawl_00411160(gex);
                }
            }
        }
    } else
        InitPlayerSideJump_004138b0(gex);
}
}
