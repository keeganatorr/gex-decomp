// Field names from Ghidra's GXObject/GXInputRecord layouts (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x28];
    int gob_xVel;               /* 0x80 */
    unsigned char _pad84[0x14];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
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
extern int DAT_004a021c;
extern int DAT_00456018_gex_Init_unk;
extern GXInputRecord gInputControllers_004a0280[];
void __cdecl InitPlayerRunJumpStart_00425ef0(GXObject *gex);
void __cdecl InitPlayerTongueLash_00427b80(GXObject *gex);
void __cdecl InitPlayerTailSlash_00427760(GXObject *gex);
void __cdecl FUN_004245b0_Walk_Apply_Speed(GXObject *gex, int speed);
void __cdecl GEX_Target(GXObject *gex)
{
    if (!DAT_004a021c && !DAT_00456018_gex_Init_unk) {
        if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB) {
            InitPlayerRunJumpStart_00425ef0(gex);
            return;
        }
        if (!gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonA) {
            if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC) {
                InitPlayerTailSlash_00427760(gex);
                return;
            }
        } else {
            InitPlayerTongueLash_00427b80(gex);
            return;
        }
    }
    gex->gob_work1 -= gex->gob_xVel < 0 ? -gex->gob_xVel : gex->gob_xVel;
    if (gex->gob_work1 < 0) {
        gex->gob_currentFrameIndex++;
        gex->gob_work1 += 0xb0000;
        if (gex->gob_work1 < 0)
            gex->gob_work1 = 0;
    }
    gex->gob_work0 = 0;
    FUN_004245b0_Walk_Apply_Speed(gex, 0x8000);
}
}
