typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;

typedef struct GXObject {
    unsigned char pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char pad58[0x98 - 0x58];
    int gob_work0;              /* 0x98 */
    unsigned int gob_work1;     /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned int gob_work3;     /* 0xa4 */
    unsigned int gob_work4;     /* 0xa8 */
    unsigned int gob_work5;     /* 0xac */
    unsigned int gob_work6;     /* 0xb0 */
    int gob_work7;              /* 0xb4 */
} GXObject;

extern "C" {
extern LevelEntry DAT_004577B0[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern int DAT_0045acd0_animationFrame[];
extern int DAT_0045ad00[];
extern int DAT_0045acf0;
extern int DAT_0045ad20;
extern int DAT_0045acf4;
extern int DAT_0045ad24;
extern unsigned int DAT_0045acf8;
extern int DAT_0045ad28;
GXObject * __cdecl GOB_FindWithWork0_0040c110(int type, int work0);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
void __cdecl RezInObject_004372f0(GXObject *);

void __cdecl ob270DoIt_0042ad40(GXObject *gob)
{
    GXObject *other;
    int level;
    int index;
    int *frame;
    int anim;
    unsigned int state;

    if (gob->gob_work5 & 0x20) {
        other = GOB_FindWithWork0_0040c110(0xdc, gob->gob_work1 & 0xffff);
        level = other->gob_work1;
        index = DAT_004577B0[level].info & 0xf;
        if ((other->gob_work3 & 0x200) && (other->gob_work3 & 0x400) && (BYTE_ARRAY_004a2540[level] & 3) != 3) {
            state = gob->gob_work5 & ~0xff | 0x11;
            frame = &gob->gob_currentFrameIndex;
            *frame = -1;
            gob->gob_work5 = state;
            if (other->gob_work3 & 0x40000000)
                gob->gob_work5 = state | 0x40;
        } else if (BYTE_ARRAY_004a2540[level] & 2) {
            state = gob->gob_work5 & ~0xff | 5;
            frame = &gob->gob_currentFrameIndex;
            gob->gob_work5 = state;
            if (other->gob_work3 & 0x40000000) {
                *frame = -1;
                gob->gob_work5 = state | 0x40;
            } else {
                *frame = DAT_0045acf0;
                gob->gob_work2 = (DAT_0045ad20 + *frame - 1) << 16 | *frame & 0xffff;
                gob->gob_work4 = gob->gob_work4 & ~0xffff | 0x4000;
            }
        } else if (BYTE_ARRAY_004a2540[level] & 1) {
            state = gob->gob_work5 & ~0xff | 3;
            frame = &gob->gob_currentFrameIndex;
            gob->gob_work5 = state;
            if (other->gob_work3 & 0x40000000) {
                *frame = -1;
                gob->gob_work5 = state | 0x40;
            } else {
                anim = DAT_0045acd0_animationFrame[index];
                *frame = anim;
                gob->gob_work2 = (DAT_0045ad00[index] + anim - 1) << 16 | anim & 0xffff;
                gob->gob_work4 = gob->gob_work4 & ~0xffff | 0x4000;
                *frame = anim + other->gob_work0 % DAT_0045ad00[index];
                gob->gob_work7 = (UTL_ReallyRandom32_00428c60() & 0x5f) << 16;
            }
            gob->gob_work6 &= 0xffff;
        } else {
            state = gob->gob_work5 & ~0xff | 1;
            frame = &gob->gob_currentFrameIndex;
            gob->gob_work5 = state;
            if (other->gob_work3 & 0x40000000) {
                *frame = -1;
                gob->gob_work5 = state | 0x40;
            } else {
                *frame = DAT_0045acd0_animationFrame[0];
                gob->gob_work2 = (DAT_0045ad00[0] + *frame - 1) << 16 | *frame & 0xffff;
                gob->gob_work4 = gob->gob_work4 & ~0xffff | 0x4000;
                gob->gob_work7 = (UTL_ReallyRandom32_00428c60() & 0x5f) << 16;
            }
        }
        gob->gob_work1 = gob->gob_work1 & 0xffff | level << 16;
        gob->gob_work6 = gob->gob_work6 & 0xffff0000 | index & 0xf;
        gob->gob_work3 = *frame << 16;
        return;
    }
    if ((gob->gob_work5 & 0xf) == 1 && (BYTE_ARRAY_004a2540[gob->gob_work1 >> 16] & 1)) {
        if (gob->gob_work5 & 0x40) {
            gob->gob_currentFrameIndex = -1;
            gob->gob_work5 = gob->gob_work5 & ~0xff | 3;
        } else {
            SND_PlaySoundNoPosition_0041a360(0x9b, 0xff);
            gob->gob_currentFrameIndex = DAT_0045acf4;
            if (gob->gob_work5 & 0x10)
                RezInObject_004372f0(gob);
            gob->gob_work5 = gob->gob_work5 & ~0xff | 2;
            anim = gob->gob_currentFrameIndex;
            gob->gob_work2 = (DAT_0045ad24 + anim - 1) << 16 | anim & 0xffff;
            gob->gob_work4 = gob->gob_work4 & ~0xffff | 0x8000;
            gob->gob_work3 = anim << 16;
        }
        gob->gob_work6 &= 0xffff;
        return;
    }
    if ((gob->gob_work5 & 0xf) == 3 && (BYTE_ARRAY_004a2540[gob->gob_work1 >> 16] & 2)) {
        if (gob->gob_work5 & 0x40) {
            gob->gob_work5 = gob->gob_work5 & ~0xff | 3;
            gob->gob_currentFrameIndex = -1;
            return;
        }
        SND_PlaySoundNoPosition_0041a360(0x97, 0xff);
        gob->gob_work5 = gob->gob_work5 & ~0xff | 4;
        anim = DAT_0045acf8;
        gob->gob_currentFrameIndex = anim;
        gob->gob_work2 = (DAT_0045ad28 + anim - 1) << 16 | anim & 0xffff;
        gob->gob_work4 = gob->gob_work4 & ~0xffff | 0x4000;
        gob->gob_work3 = anim << 16;
        gob->gob_work7 = 0;
    }
}
}
