typedef struct HitBox {
    int left;
    int top;
    int right;
    int bottom;
} HitBox;
typedef struct CFrame {
    unsigned int flags;
    unsigned char _pad4[0x10 - 4];
    HitBox *boxes;              /* 0x10 */
} CFrame;
typedef struct CLDEdges {
    CFrame *frame;
    int unk4;
    int x;
    int y;
    int flipX;
    int flipY;
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
typedef struct HitMessage {
    int unk0;
    int type;
} HitMessage;
typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x64];
    void (__cdecl *gob_hitCallback)(GXObject *, void *);    /* 0x64 */
    unsigned char _pad68[0xc4 - 0x68];
    int gob_angle;              /* 0xc4 */
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
    unsigned char _padd0[0x170 - 0xd0];
    HitBox *gob_hitBox;         /* 0x170 */
    HitBox *gob_hitOtherBox;    /* 0x174 */
    GXObject *gob_hitObject;    /* 0x178 */
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
extern int DAT_00463734;
extern int DAT_0046368c;
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, CLDEdges *edges);
int __cdecl CLD_CheckCollisionAngle_0041dd50(GXObject *gob, GXObject *other);
int __cdecl CLD_CheckCollisionFunkyAngle_0041d310(GXObject *gob, GXObject *other);

int __cdecl GEX_Target(GXObject *gob, GXObject *other)
{
    HitRecord self;
    HitBox *ha;
    HitBox *hb;
    int al;
    int ar;
    int at;
    int ab;
    int bl;
    int br;
    int bt;
    int bb;

    if ((gob->gob_angle & 0x3f0000) || (other->gob_angle & 0x3f0000) || gob->gob_xScale != 0x10000
        || gob->gob_yScale != 0x10000 || other->gob_xScale != 0x10000 || other->gob_yScale != 0x10000)
        return CLD_CheckCollisionFunkyAngle_0041d310(gob, other);
    if (((gob->gob_angle + 0x200000) & 0xc00000) || ((other->gob_angle + 0x200000) & 0xc00000))
        return CLD_CheckCollisionAngle_0041dd50(gob, other);
    DAT_00463734++;
    if (!CLD_ComputeAngleEdges_0041cb80(gob, &self.a))
        return 0;
    if (!CLD_ComputeAngleEdges_0041cb80(other, &self.b))
        return 0;
    if (self.a.right < self.b.left || self.a.bottom < self.b.top || self.a.left > self.b.right || self.a.top > self.b.bottom)
        return 0;
    DAT_0046368c++;
    ha = self.a.frame->boxes;
    if (ha) {
        hb = self.b.frame->boxes;
        if (hb) {
            while (ha->left != (int)0x80000000) {
                hb = self.b.frame->boxes;
                if (self.a.flipX) {
                    al = -ha->right;
                    ar = -ha->left;
                } else {
                    al = ha->left;
                    ar = ha->right;
                }
                if (self.a.flipY) {
                    at = -ha->bottom;
                    ab = -ha->top;
                } else {
                    at = ha->top;
                    ab = ha->bottom;
                }
                for (; hb->left != (int)0x80000000; hb++) {
                    if (self.b.flipX) {
                        bl = -hb->right;
                        br = -hb->left;
                    } else {
                        bl = hb->left;
                        br = hb->right;
                    }
                    if (self.b.flipY) {
                        bt = -hb->bottom;
                        bb = -hb->top;
                    } else {
                        bt = hb->top;
                        bb = hb->bottom;
                    }
                    if (self.b.x + bl <= self.a.x + ar && self.a.y + ab >= self.b.y + bt && self.a.x + al <= self.b.x + br && self.a.y + at <= self.b.y + bb) {
                        gob->gob_hitObject = other;
                        gob->gob_hitBox = ha;
                        gob->gob_hitOtherBox = hb;
                        other->gob_hitObject = gob;
                        other->gob_hitBox = hb;
                        other->gob_hitOtherBox = ha;
                        if (gob->gob_hitCallback) {
                            self.unk0 = 1;
                            self.type = 0;
                            gob->gob_hitCallback(gob, &self);
                        }
                        if (other->gob_hitCallback) {
                            HitRecord hit;
                            hit.unk0 = 1;
                            hit.a = self.b;
                            hit.b = self.a;
                            hit.type = 0;
                            other->gob_hitCallback(other, &hit);
                        }
                        return 1;
                    }
                }
                ha++;
            }
        }
    }
    gob->gob_hitObject = other;
    gob->gob_hitBox = 0;
    gob->gob_hitOtherBox = 0;
    other->gob_hitObject = gob;
    other->gob_hitBox = 0;
    other->gob_hitOtherBox = 0;
    if (gob->gob_hitCallback) {
        self.unk0 = 0;
        self.type = 0;
        gob->gob_hitCallback(gob, &self);
    }
    if (other->gob_hitCallback) {
        HitRecord hit;
        hit.a = self.b;
        hit.b = self.a;
        hit.unk0 = 0;
        hit.type = 0;
        other->gob_hitCallback(other, &hit);
    }
    return 1;
}
}
