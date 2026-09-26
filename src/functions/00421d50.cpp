typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x78 - 0x74];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xc4 - 0x80];
    int gob_angle;              /* 0xc4 */
} GXObject;
typedef struct HitBox {
    unsigned char _pad0[0x20];
    int left;                   /* 0x20 */
    int right;                  /* 0x24 */
    int top;                    /* 0x28 */
    int bottom;                 /* 0x2c */
} HitBox;
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
extern GXObject *gPlayerObject_004a27fc;
extern GXObject *gPlayerPlatform_004a2864;
extern unsigned int DAT_00457210[];
extern int DAT_00458c78_ButtonUnk10;
void __cdecl FUN_00421cd0_xpos_ypos_related(GXObject *gex);
void __cdecl InitPlayerPlatAirToSideCrawl_00414290(GXObject *gex);
void __cdecl GEX_Target(GXObject *platform, HitBox *box, int side)
{
    int right;
    int over;
    int under;
    int x;
    if (!(DAT_00457210[gPlayerObject_004a27fc->gob_state] & 2) || DAT_00458c78_ButtonUnk10)
        return;
    switch (platform->gob_state) {
    case 0x3d:
        return;
    case 0x44:
    case 0x45:
        return;
    case 0x50:
    case 0x51:
    case 0x52:
        return;
    }
    if (side == 2) {
        if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp)
            return;
        gPlayerPlatform_004a2864 = platform;
        FUN_00421cd0_xpos_ypos_related(gPlayerObject_004a27fc);
        gPlayerObject_004a27fc->gob_angle = gPlayerObject_004a27fc->gob_flags & 0x80000000 ? 0xc00000 : 0x400000;
        gPlayerObject_004a27fc->gob_ypos = box->bottom;
        x = gPlayerObject_004a27fc->gob_xpos;
        over = box->left - x + 0x180000;
        under = x - box->right + 0x180000;
        if (over > 0 && under > 0)
            ;
        else if (over > 0)
            gPlayerObject_004a27fc->gob_xpos = over + x + 0x10000;
        else if (under > 0)
            gPlayerObject_004a27fc->gob_xpos = x - under - 0x10000;
        InitPlayerPlatAirToSideCrawl_00414290(gPlayerObject_004a27fc);
    } else {
        right = side == 1;
        if (right && gInputControllers_004a0280[0].gxir_padButtons.buttonRight || !right && gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
            gPlayerPlatform_004a2864 = platform;
            FUN_00421cd0_xpos_ypos_related(gPlayerObject_004a27fc);
            if (right) {
                gPlayerObject_004a27fc->gob_flags |= 0x80000000;
                gPlayerObject_004a27fc->gob_xpos = box->left;
            } else {
                gPlayerObject_004a27fc->gob_flags &= 0x7fffffff;
                gPlayerObject_004a27fc->gob_xpos = box->right;
            }
            InitPlayerPlatAirToSideCrawl_00414290(gPlayerObject_004a27fc);
        }
    }
}
}
