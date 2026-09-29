typedef struct GXObject {
    unsigned char pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char pad58[0x78 - 0x58];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char pad9c[0xc4 - 0x9c];
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
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern int decl_pad_15;
extern int decl_pad_16;
extern int decl_pad_17;
extern int decl_pad_18;
extern int decl_pad_19;
extern int decl_pad_20;
extern int decl_pad_21;
extern int decl_pad_22;
extern int decl_pad_23;
extern int decl_pad_24;
extern GXInputRecord gInputControllers_004a0280[];
extern int DAT_004a022c;
void __cdecl FUN_00423800_pStateUnk(GXObject *);
int __cdecl FUN_00423a50_AirToFaceCrawl(GXObject *);
void __cdecl InitPlayerFaceCrawlToAir_004144e0(GXObject *);
void __cdecl InitPlayerFaceTongueLash_00413ba0(GXObject *);
void __cdecl InitPlayerFaceSpin_00412af0(GXObject *);
void __cdecl InitPlayerFaceTurn_00426620(GXObject *);
int __cdecl FUN_00423910_pStateUnk(GXObject *);
int __cdecl FUN_00423960_pStateUnk(GXObject *);
int __cdecl FUN_004239b0_pStateUnk(GXObject *);
int __cdecl FUN_00423a00_pStateUnk(GXObject *);

void __cdecl PlayerFaceStick_00426690(GXObject *gob)
{
    int animSpeed;
    int dy;
    int oldy;
    int moved;
    int anim;
    int speed;
    int dir;
    int dx;
    int oldx;

    FUN_00423800_pStateUnk(gob);
    if (!FUN_00423a50_AirToFaceCrawl(gob)) {
        InitPlayerFaceCrawlToAir_004144e0(gob);
        return;
    }
    if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB && !gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
        InitPlayerFaceCrawlToAir_004144e0(gob);
        return;
    }
    if (!gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonA) {
        if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC) {
            InitPlayerFaceSpin_00412af0(gob);
            return;
        }
        moved = 0;
        dx = 0;
        dy = 0;
        dir = 0;
        anim = 0;
        speed = gInputControllers_004a0280[0].gxir_padButtons.buttonL ? 0x70000 : 0x50000;
        animSpeed = gInputControllers_004a0280[0].gxir_padButtons.buttonL ? 0xd000 : 0xb000;
        switch (gob->gob_angle) {
        case 0:
            if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
                moved = 1;
                dir = 1;
                anim = animSpeed;
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                    dx = dy = speed * 2 / -3;
                else if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    dx = speed * 2 / 3;
                    dy = speed * 2 / -3;
                } else
                    dy = -speed;
            } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft || gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                InitPlayerFaceTurn_00426620(gob);
            else {
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown) {
                    moved = 1;
                    anim = animSpeed;
                    dir = -1;
                    if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                        dx = speed * 2 / -3;
                        dy = speed * 2 / 3;
                    } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                        dx = dy = speed * 2 / 3;
                    else
                        dy = speed;
                } else
                    moved = 1;
            }
            break;
        case 0x400000:
            if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                moved = 1;
                dir = 1;
                anim = animSpeed;
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
                    dx = speed * 2 / 3;
                    dy = speed * 2 / -3;
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
                    dx = dy = speed * 2 / 3;
                else
                    dx = speed;
            } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp || gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
                InitPlayerFaceTurn_00426620(gob);
            else {
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    moved = 1;
                    anim = animSpeed;
                    dir = -1;
                    if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp)
                        dx = dy = speed * 2 / -3;
                    else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown) {
                        dx = -speed;
                        dy = speed * 2 / 3;
                    } else
                        dx = -speed;
                } else
                    moved = 1;
            }
            break;
        case 0x800000:
            if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown) {
                moved = 1;
                anim = animSpeed;
                dir = 1;
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    dx = speed * 2 / -3;
                    dy = speed * 2 / 3;
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                    dx = dy = speed * 2 / 3;
                else
                    dy = speed;
            } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft || gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                InitPlayerFaceTurn_00426620(gob);
            else {
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
                    moved = 1;
                    anim = animSpeed;
                    dir = -1;
                    if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                        dx = dy = speed * 2 / -3;
                    else if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                        dx = speed * 2 / 3;
                        dy = speed * 2 / -3;
                    } else
                        dy = -speed;
                } else
                    moved = 1;
            }
            break;
        case 0xc00000:
            if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                moved = 1;
                anim = animSpeed;
                dir = 1;
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp)
                    dx = dy = speed * 2 / -3;
                else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown) {
                    dx = speed * 2 / -3;
                    dy = speed * 2 / 3;
                } else
                    dx = -speed;
            } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp || gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
                InitPlayerFaceTurn_00426620(gob);
            else {
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    moved = 1;
                    anim = animSpeed;
                    dir = -1;
                    if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
                        dx = speed * 2 / 3;
                        dy = speed * 2 / -3;
                    } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
                        dx = dy = speed * 2 / 3;
                    else
                        dx = speed;
                } else
                    moved = 1;
            }
            break;
        default:
            InitPlayerFaceTurn_00426620(gob);
        }
        if (!moved)
            return;
        if (!dx && !dy) {
            if (gob->gob_currentFrameGroup != 0x48) {
                gob->gob_currentFrameGroup = 0x48;
                gob->gob_currentFrameIndex = 0;
                gob->gob_work0 = 0;
            }
            gob->gob_work0 += 0x4000;
            if (gob->gob_work0 > 0x10000) {
                gob->gob_work0 -= 0x10000;
                gob->gob_currentFrameIndex++;
            }
        } else {
            oldx = gob->gob_xpos;
            oldy = gob->gob_ypos;
            if (gob->gob_currentFrameGroup != 0x43) {
                gob->gob_currentFrameGroup = 0x43;
                gob->gob_currentFrameIndex = 0;
                gob->gob_work0 = 0;
            }
            if (dx > 0) {
                gob->gob_xpos += dx;
                if (!FUN_00423960_pStateUnk(gob))
                    gob->gob_xpos = oldx;
            } else if (dx < 0) {
                gob->gob_xpos += dx;
                if (!FUN_00423910_pStateUnk(gob))
                    gob->gob_xpos = oldx;
            }
            if (dy > 0) {
                gob->gob_ypos += dy;
                if (!FUN_00423a00_pStateUnk(gob))
                    gob->gob_ypos = oldy;
            } else if (dy < 0) {
                gob->gob_ypos += dy;
                if (!FUN_004239b0_pStateUnk(gob))
                    gob->gob_ypos = oldy;
            }
            if (gob->gob_xpos != oldx || gob->gob_ypos != oldy) {
                gob->gob_work0 += anim;
                if (gob->gob_work0 > 0x10000) {
                    gob->gob_work0 -= 0x10000;
                    gob->gob_currentFrameIndex += dir;
                    if (gob->gob_currentFrameIndex < 0)
                        gob->gob_currentFrameIndex = 7;
                }
            }
        }
        DAT_004a022c = 1;
    } else
        InitPlayerFaceTongueLash_00413ba0(gob);
}
}
