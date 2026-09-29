// Field names from Ghidra's GXObject/GXInputRecord layouts (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;      /* 0x50 */
    int gob_currentFrameIndex;      /* 0x54 */
    unsigned char _pad58[0x18];
    int gob_state;                  /* 0x70 */
    unsigned char _pad74[4];
    int gob_xpos;                   /* 0x78 */
    int gob_ypos;                   /* 0x7c */
    int gob_xVel;                   /* 0x80 */
    int gob_maxxVel;                /* 0x84 */
    int gob_xAccl;                  /* 0x88 */
    int gob_yVel;                   /* 0x8c */
    int gob_maxyVel;                /* 0x90 */
    int gob_yAccl;                  /* 0x94 */
    int gob_work0;                  /* 0x98 */
    int gob_work1;                  /* 0x9c */
    int gob_work2;                  /* 0xa0 */
    int gob_work3;                  /* 0xa4 */
    unsigned char _padA8[0x2c];
    int gob_xold;                   /* 0xd4 */
    unsigned char _padD8[0x38];
    struct GXObject *gob_platform;  /* 0x110 */
} GXObject;
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
extern int INT_0045a6d0;
extern int DAT_004a0214_HighJump;
extern GXInputRecord gInputControllers_004a0280[];
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl FUN_00424d80_StandJump(GXObject *gex)
{
    GXObject *platform;
    int highJump;
    int jumpSpeed;
    GOB_ResetState_00420bc0(gex);
    gex->gob_state = 0xc;
    gex->gob_currentFrameGroup = 0x27;
    gex->gob_currentFrameIndex = 2;
    gex->gob_maxxVel = INT_0045a6d0;
    gex->gob_work0 = DAT_004a0214_HighJump ? 8 : 5;
    highJump = DAT_004a0214_HighJump;
    jumpSpeed = highJump ? -0xe0000 : -0xc3333;
    gex->gob_work2 = 0;
    gex->gob_yAccl = 0x14000;
    gex->gob_work3 = 2;
    gex->gob_maxyVel = 0xe0000;
    gex->gob_yVel = jumpSpeed;
    platform = gex->gob_platform;
    if (platform) {
        gex->gob_xVel += platform->gob_xpos - platform->gob_xold;
        gex->gob_platform = 0;
    }
    gex->gob_work1 = jumpSpeed;
    gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB = 0;
}
}
