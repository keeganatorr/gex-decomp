typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x78 - 0x58];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x15c - 0x80];
    GXObject *gob_parent;       /* 0x15c */
};
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
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
unsigned int __cdecl SCRIPT_GetUInt_00417f00(unsigned char **script);
int __cdecl GOB_GetHotSpot_00419c00(GXObject *gob, int index, int flag, int *x, int *y);
void __cdecl GOB_DisplayCelToQuad_00443ae0(GXObject *gob, int cel, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
unsigned char *__cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    int hx;
    int hy;
    int minX;
    int minY;
    int maxX;
    int maxY;
    int group;
    int frame;
    int savedGroup;
    int savedFrame;
    int ys[4];
    int xs[4];
    int hot[4];
    int i;
    savedGroup = gob->gob_currentFrameGroup;
    savedFrame = gob->gob_currentFrameIndex;
    group = *script++;
    frame = *script++;
    minX = SCRIPT_GetUInt_00417f00(&script);
    minY = SCRIPT_GetUInt_00417f00(&script);
    maxX = SCRIPT_GetUInt_00417f00(&script);
    maxY = SCRIPT_GetUInt_00417f00(&script);
    hot[0] = *script++;
    hot[1] = *script++;
    hot[2] = *script++;
    hot[3] = *script++;
    script++;
    for (i = 0; i < 4; i++) {
        if (GOB_GetHotSpot_00419c00(gob, hot[i], 0, &hx, &hy)) {
            if (gob->gob_parent) {
                xs[i] = gob->gob_parent->gob_xpos + hx;
                ys[i] = gob->gob_parent->gob_ypos + hy;
            } else {
                xs[i] = gob->gob_xpos + hx;
                ys[i] = gob->gob_ypos + hy;
            }
            if (xs[i] < minX)
                xs[i] = minX;
            if (xs[i] > maxX)
                xs[i] = maxX;
            if (ys[i] < minY)
                ys[i] = minY;
            if (ys[i] > maxY)
                ys[i] = maxY;
            xs[i] -= CAMERA_XPos_004a2a38;
            ys[i] -= CAMERA_YPos_004a2a1c;
        }
    }
    gob->gob_currentFrameGroup = group;
    gob->gob_currentFrameIndex = frame;
    GOB_DisplayCelToQuad_00443ae0(gob, 0, xs[0], ys[0], xs[1], ys[1], xs[2], ys[2], xs[3], ys[3]);
    gob->gob_currentFrameGroup = savedGroup;
    gob->gob_currentFrameIndex = savedFrame;
    return script;
}
}
