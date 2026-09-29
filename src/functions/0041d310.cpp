// Reconstructed from the pinned function and a read-only Ghidra decompilation.
// A rotated collision test uses coordinates relative to each object's parent
// chain, then compares the current frame and its optional hit areas.
typedef struct GXObject GXObject;
typedef void (__cdecl *HitCallback)(GXObject *, int *);
struct GXObject {
    unsigned char pad0[0x64];
    HitCallback hitCallback;      // 0x64
    unsigned char pad68[0x78 - 0x68];
    int x;                        // 0x78
    int y;                        // 0x7c
    unsigned char pad80[0xc4 - 0x80];
    int angle;                    // 0xc4
};

extern "C" {
extern int gTrigTable_0045a5c8[];
extern int DAT_0046368C;
extern int DAT_00463738;
int __cdecl CLD_ComputeAnglePointsWithFrame_0041d0e0(void *, int, int, int, int *);
void __cdecl CLD_ComputeAnglePointsWithHitArea_0041d010(void *, int *, int, int, int, int *);
int __cdecl CLD_CheckRotatedRects_0041d250(int, int);
}

static int field(GXObject *object, int offset) {
    return *(int *)((unsigned char *)object + offset);
}

static void setField(GXObject *object, int offset, int value) {
    *(int *)((unsigned char *)object + offset) = value;
}

static int sine256(unsigned int angle) {
    unsigned int phase = angle & 255;
    if (phase <= 64) return gTrigTable_0045a5c8[phase];
    if (phase <= 128) return gTrigTable_0045a5c8[128 - phase];
    if (phase <= 192) return -gTrigTable_0045a5c8[phase - 128];
    return -gTrigTable_0045a5c8[256 - phase];
}

static void worldPosition(GXObject *object, int *x, int *y) {
    GXObject *parent = (GXObject *)field(object, 0x15c);
    *x = field(object, 0x78);
    *y = field(object, 0x7c);
    while (parent) {
        *x += field(parent, 0x78);
        *y += field(parent, 0x7c);
        parent = (GXObject *)field(parent, 0x15c);
    }
}

static void setHit(GXObject *a, GXObject *b, int *boxA, int *boxB) {
    setField(a, 0x178, (int)b);
    setField(a, 0x170, (int)boxA);
    setField(a, 0x174, (int)boxB);
    setField(b, 0x178, (int)a);
    setField(b, 0x170, (int)boxB);
    setField(b, 0x174, (int)boxA);
}

static void sendHits(GXObject *a, GXObject *b, int contact) {
    int event[22] = {0};
    event[0] = contact;
    event[1] = 1;
    if (a->hitCallback)
        a->hitCallback(a, event);
    if (b->hitCallback)
        b->hitCallback(b, event);
}

extern "C" int __cdecl CLD_CheckCollisionFunkyAngle_0041d310(GXObject *a, GXObject *b)
{
    int ax, ay, bx, by;
    int dx, dy, angleA, angleB, angleDifference;
    int cosine, sine, localAx, localAy, localBx, localBy;
    int pointsA[17], pointsB[17];
    int *boxesA, *boxesB;

    ++DAT_00463738;
    worldPosition(a, &ax, &ay);
    worldPosition(b, &bx, &by);
    dx = (ax - bx) >> 8;
    dy = (ay - by) >> 8;
    angleA = field(a, 0xc4);
    angleB = field(b, 0xc4);
    sine = sine256((unsigned int)(-angleB) >> 16);
    cosine = sine256(((unsigned int)(-angleB) >> 16) + 64);
    // The pinned routine uses quarter-turn table values after an 8-bit shift.
    localAx = bx + (cosine >> 8) * dx - (sine >> 8) * dy;
    localAy = by + (sine >> 8) * dx + (cosine >> 8) * dy;
    sine = sine256((unsigned int)(-angleA) >> 16);
    cosine = sine256(((unsigned int)(-angleA) >> 16) + 64);
    localBx = ax + (sine >> 8) * dy - (cosine >> 8) * dx;
    localBy = ay - (cosine >> 8) * dy - (sine >> 8) * dx;
    angleDifference = (angleA - angleB) & 0xff0000;

    if (!CLD_ComputeAnglePointsWithFrame_0041d0e0(a, localAx, localAy, angleDifference, pointsA))
        return 0;
    if (!CLD_ComputeAnglePointsWithFrame_0041d0e0(b, localBx, localBy, (-angleDifference) & 0xff0000, pointsB))
        return 0;
    if (!CLD_CheckRotatedRects_0041d250((int)pointsA, (int)pointsB))
        return 0;
    ++DAT_0046368C;

    boxesA = *(int **)((unsigned char *)pointsA[0] + 0x10);
    boxesB = *(int **)((unsigned char *)pointsB[0] + 0x10);
    if (boxesA && boxesB) {
        int *areaA;
        int *areaB;
        for (areaA = boxesA; areaA[0] != (int)0x80000000; areaA += 4) {
            CLD_ComputeAnglePointsWithHitArea_0041d010(a, areaA, localAx, localAy,
                                                         angleDifference, pointsA);
            for (areaB = boxesB; areaB[0] != (int)0x80000000; areaB += 4) {
                CLD_ComputeAnglePointsWithHitArea_0041d010(b, areaB, localBx, localBy,
                                                             (-angleDifference) & 0xff0000, pointsB);
                if (CLD_CheckRotatedRects_0041d250((int)pointsA, (int)pointsB)) {
                    setHit(a, b, areaA, areaB);
                    sendHits(a, b, 1);
                    return 1;
                }
            }
        }
    }
    setHit(a, b, 0, 0);
    sendHits(a, b, 0);
    return 1;
}
