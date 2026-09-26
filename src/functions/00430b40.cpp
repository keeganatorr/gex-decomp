// Field names from Ghidra's GXObject/GXHitArea layouts (evidence, not proof).
typedef struct GXHitArea { int gxha_left; int gxha_top; int gxha_right; int gxha_bottom; } GXHitArea;
typedef struct GXObFrame { int left; int top; int right; int bottom; GXHitArea *areas; } GXObFrame;
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;  /* 0x6c */
} GXObject;
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
extern int DAT_00463f00;
extern int DAT_00463f04;
extern int DAT_00463f08;
extern int DAT_00463f0c;
GXObFrame *__cdecl GOB_GetCurrentFrameWithDefault_0041a380(GXObject *gob);
int __cdecl FUN_00430990(GXObject *gob, int top, int bottom, int left, int right, int a, int b, int c, int d);
int __cdecl GEX_Target(void)
{
    GXObFrame *frame;
    GXHitArea *area;
    int left;
    int right;
    int top;
    int bottom;
    unsigned int flip;
    frame = GOB_GetCurrentFrameWithDefault_0041a380(gPlayerObject_004a27fc);
    top = frame->top;
    bottom = frame->bottom;
    flip = gPlayerObject_004a27fc->gob_flags & 0x80000000;
    if (flip)
        right = -frame->left;
    else
        right = frame->right;
    if (flip)
        left = -frame->right;
    else
        left = frame->left;
    if (FUN_00430990(gPlayerObject_004a27fc, top, bottom, left, right, DAT_00463f04, DAT_00463f0c, DAT_00463f00, DAT_00463f08)) {
        for (area = frame->areas; area->gxha_left != (int)0x80000000; area++) {
            if (gPlayerObject_004a27fc->gob_flags & 0x80000000) {
                left = -area->gxha_right;
                right = -area->gxha_left;
            } else {
                left = area->gxha_left;
                right = area->gxha_right;
            }
            if (gPlayerObject_004a27fc->gob_flags & 0x40000000) {
                top = -area->gxha_bottom;
                bottom = -area->gxha_top;
            } else {
                top = area->gxha_top;
                bottom = area->gxha_bottom;
            }
            if (FUN_00430990(gPlayerObject_004a27fc, top, bottom, left, right, DAT_00463f04, DAT_00463f0c, DAT_00463f00, DAT_00463f08))
                return 1;
        }
    }
    return 0;
}
}
