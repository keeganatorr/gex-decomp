typedef struct GXFrame {
    int left;
    int top;
    int right;
    int bottom;
} GXFrame;
typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xc8 - 0x80];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
    unsigned char _padd0[0x15c - 0xd0];
    GXObject *gob_parent;       /* 0x15c */
};
typedef struct CLDPoints {
    GXFrame *frame;
    int x0, y0;
    int x1, y1;
    int x2, y2;
    int x3, y3;
} CLDPoints;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
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
extern int decl_pad_25;
extern int decl_pad_26;
extern int decl_pad_27;
extern int decl_pad_28;
extern int decl_pad_29;
extern int decl_pad_30;
extern int decl_pad_31;
extern int decl_pad_32;
extern int decl_pad_33;
extern int decl_pad_34;
extern int decl_pad_35;
extern int decl_pad_36;
extern int decl_pad_37;
extern int decl_pad_38;
extern int decl_pad_39;
extern int decl_pad_40;
extern int decl_pad_41;
extern int decl_pad_42;
extern int decl_pad_43;
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
GXFrame *__cdecl GOB_GetCurrentFrameWithDefault_0041a380(GXObject *gob);
void __cdecl CLD_ApplyAngleToPoints_0041cc70(CLDPoints *points, int x, int y, int a, int b, unsigned int c, int xScale, int yScale);
int __cdecl CLD_ComputeAnglePointsWithFrame_0041d0e0(GXObject *gob, int a, int b, unsigned int c, CLDPoints *points)
{
    GXObject *parent;
    int originalX;
    int originalY;
    int x;
    GXFrame *frame;
    int y;
    parent = gob->gob_parent;
    if (gob->gob_currentFrameGroup >= 0 && gob->gob_currentFrameIndex >= 0) {
        frame = GOB_GetCurrentFrameWithDefault_0041a380(gob);
        if (frame && frame->left <= frame->right) {
            points->frame = frame;
            if (gob->gob_flags & 0x80000000) {
                points->x0 = -frame->right;
                points->x1 = -frame->left;
                points->x2 = -frame->left;
                points->x3 = -frame->right;
            } else {
                points->x0 = frame->left;
                points->x1 = frame->right;
                points->x2 = frame->right;
                points->x3 = frame->left;
            }
            if (gob->gob_flags & 0x40000000) {
                points->y0 = -frame->bottom;
                points->y1 = -frame->bottom;
                points->y2 = -frame->top;
                points->y3 = -frame->top;
            } else {
                points->y0 = frame->top;
                points->y1 = frame->top;
                points->y2 = frame->bottom;
                points->y3 = frame->bottom;
            }
            if (parent) {
                int dx;
                int dy;
                originalX = gob->gob_xpos;
                originalY = gob->gob_ypos;
                dx = 0;
                dy = 0;
                while (parent->gob_parent) {
                    dx += parent->gob_xpos;
                    dy += parent->gob_ypos;
                    parent = parent->gob_parent;
                }
                x = parent->gob_xpos + dx + originalX;
                y = originalY + (parent->gob_ypos + dy);
            } else {
                x = gob->gob_xpos;
                y = gob->gob_ypos;
            }
            CLD_ApplyAngleToPoints_0041cc70(points, x, y, a, b, c, gob->gob_xScale, gob->gob_yScale);
            return 1;
        }
        return 0;
    }
    return 0;
}
}
