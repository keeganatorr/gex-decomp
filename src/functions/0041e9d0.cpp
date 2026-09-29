typedef struct Contour {
    int x;
    int y;
    int width;
    unsigned char heights[1];
} Contour;
typedef struct CFrame {
    unsigned int flags;
    unsigned char _pad4[0x20 - 4];
    Contour *contour;           /* 0x20 */
} CFrame;
typedef struct CLDEdges {
    CFrame *frame;
    int unk4;
    int x;
    int y;
    int flip;
    int unk14;
    int left;
    int right;
    int top;
    int bottom;
} CLDEdges;
typedef struct HitRecord {
    int unk0;
    int type;
    CLDEdges a;
    CLDEdges b;
} HitRecord;
typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x178 - 0x70];
    GXObject *gob_hitObject;    /* 0x178 */
};

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
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, CLDEdges *edges);
int __cdecl CLD_CheckAboveContour_0041e9d0(GXObject *gob, HitRecord *hit)
{
    CLDEdges b;
    CLDEdges a;
    GXObject *other;
    int r;
    int h;
    int l;
    int limit;
    int bl;
    int br;
    int i4;
    int li;
    Contour *contour;
    int i3;
    int start;
    int end;
    int ri;
    other = gob->gob_hitObject;
    if (hit->type == 1) {
        CLD_ComputeAngleEdges_0041cb80(gob, &a);
        CLD_ComputeAngleEdges_0041cb80(other, &b);
    } else {
        a = hit->a;
        b = hit->b;
    }
    if (b.frame->flags & 2) {
        contour = b.frame->contour;
        if (gob->gob_flags & 0x80000000) {
            l = a.right;
            r = a.left;
        } else {
            l = a.left;
            r = a.right;
        }
        if (b.flip) {
            bl = b.right;
            br = b.left;
            start = b.x - (contour->width << 16) - contour->x;
            end = b.x - contour->x;
            i3 = contour->width;
            i4 = 0;
            li = l - end >> 16;
            ri = r - end >> 16;
        } else {
            bl = b.left;
            br = b.right;
            start = b.x + contour->x;
            end = (contour->width << 16) + contour->x + b.x;
            i4 = contour->width;
            li = l - start >> 16;
            i3 = 0;
            ri = r - start >> 16;
        }
        limit = a.bottom - contour->y - b.y;
        if (start < l && end > l) {
            h = contour->heights[li] << 16;
            if (h > limit)
                return 1;
        }
        if (start < r && end > r && contour->heights[ri] << 16 > limit)
            return 1;
        if (bl <= l && start > l || bl <= r && start > r) {
            if (contour->heights[i3] << 16 > limit)
                return 1;
        } else if (end <= l && br > l || end <= l && br > l) {
            if (contour->heights[i4] << 16 > limit)
                return 1;
        }
    }
    return 0;
}
