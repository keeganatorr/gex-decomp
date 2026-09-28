typedef struct ObState {
    unsigned int state : 8;
    unsigned int prev : 4;
    unsigned int rest : 20;
} ObState;

typedef struct GXObject {
    unsigned char pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char pad58[0x98 - 0x58];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    ObState gob_work5;          /* 0xac */
    int gob_work6;              /* 0xb0 */
    int gob_work7;              /* 0xb4 */
    int gob_work8;              /* 0xb8 */
    int gob_work9;              /* 0xbc */
} GXObject;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int DAT_0045acf4;
extern int DAT_0045acc8[];
extern int DAT_0045add0[];
extern int DAT_0045acd0_animationFrame[];
extern int DAT_0045ad00[];
extern int DAT_0045acf0;
extern int DAT_0045ad20;
extern int DAT_0045ad30[];
extern int DAT_0045ad58[];
extern int DAT_0045ad80[];
extern int DAT_0045ada8[];
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
void __cdecl GOB_DisplayObject_00444590(GXObject *);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
GXObject * __cdecl GOB_FindFirstWithType_00429c60(int);

void __cdecl GEX_Target(GXObject *gob)
{
    int saved;
    int frame;
    int i;

    if (((unsigned char)gob->gob_work5.state & 0xf) == 2 && !(gob->gob_work3 & 0xffff)
        && !((gob->gob_currentFrameIndex - DAT_0045acf4) & 7))
        SND_PlaySoundNoPosition_0041a360(0x98, 0xff);
    GOB_DisplayObject_00444590(gob);
    if ((gob->gob_work5.state & 0xf) == 3 || (gob->gob_work5.state & 0xf) == 6 && gob->gob_work5.prev == 3) {
        saved = gob->gob_work9;
        frame = gob->gob_currentFrameIndex;
        gob->gob_work9 = DAT_0045acc8[gob->gob_work6 >> 24];
        if (gob->gob_work0 == 1)
            gob->gob_currentFrameIndex = 0xa5;
        else
            gob->gob_currentFrameIndex = 0x97;
        GOB_DisplayObject_00444590(gob);
        gob->gob_currentFrameIndex = frame;
        gob->gob_work9 = saved;
        gob->gob_work6 += 0x1000000;
        if (gob->gob_work6 >> 24 >= 2)
            gob->gob_work6 &= 0xffff;
    }
    if (gob->gob_work4 & 0xffff) {
        gob->gob_work3 += gob->gob_work4 & 0xffff;
        if ((int)(gob->gob_work2 & 0xffff0000) < (int)(gob->gob_work3 & 0xffff0000)) {
            if ((gob->gob_work5.state & 0xf) == 2) {
                SND_PlaySoundNoPosition_0041a360(DAT_0045add0[(gob->gob_work6 & 0xf)], 0xff);
                gob->gob_work5.state = 3;
                gob->gob_work3 = DAT_0045acd0_animationFrame[(gob->gob_work6 & 0xf)];
                gob->gob_work2 = (DAT_0045ad00[(gob->gob_work6 & 0xf)] + gob->gob_work3 - 1) << 16 | gob->gob_work3 & 0xffff;
                gob->gob_work3 <<= 16;
                gob->gob_work7 = (UTL_ReallyRandom32_00428c60() & 0x5f) << 16;
            } else if ((gob->gob_work5.state & 0xf) == 4) {
                gob->gob_work5.state = 5;
                gob->gob_work3 = DAT_0045acf0;
                gob->gob_work2 = (DAT_0045ad20 + gob->gob_work3 - 1) << 16 | gob->gob_work3 & 0xffff;
                gob->gob_work3 <<= 16;
            } else if ((gob->gob_work5.state & 0xf) == 6) {
                if (gob->gob_work5.prev == 3) {
                    gob->gob_work5.state = 3;
                        gob->gob_work2 = (DAT_0045ad00[(gob->gob_work6 & 0xf)] + DAT_0045acd0_animationFrame[(gob->gob_work6 & 0xf)] - 1) << 16 | DAT_0045acd0_animationFrame[(gob->gob_work6 & 0xf)] & 0xffff;
                } else {
                    gob->gob_work5.state = 1;
                        gob->gob_work2 = (DAT_0045ad00[0] + DAT_0045acd0_animationFrame[0] - 1) << 16 | DAT_0045acd0_animationFrame[0] & 0xffff;
                }
                gob->gob_work3 = gob->gob_work7;
                gob->gob_work7 = (UTL_ReallyRandom32_00428c60() & 0x5f) << 16;
            } else
                gob->gob_work3 = gob->gob_work2 << 16;
        }
        i = gob->gob_work5.state & 0xf;
        if (i == 3) {
            gob->gob_work7 -= gob->gob_work4 & 0xffff;
            if (gob->gob_work7 < (gob->gob_work4 & 0xffff)) {
                if (i == 3) {
                    if (!((GOB_FindFirstWithType_00429c60(0xdf)->gob_work1 ^ gob->gob_work1) & 0xffff))
                        SND_PlaySoundNoPosition_0041a360(0x9c, 0xff);
                    i = (gob->gob_work6 & 0xf);
                } else
                    i = 0;
                gob->gob_work7 = gob->gob_work3;
                gob->gob_work5.prev = gob->gob_work5.state;
                gob->gob_work5.state = 6;
                if (gob->gob_work0 == 1) {
                    gob->gob_work3 = DAT_0045ad30[i];
                    gob->gob_work2 = (DAT_0045ad80[i] + gob->gob_work3 - 1) << 16 | gob->gob_work3 & 0xffff;
                } else {
                    gob->gob_work3 = DAT_0045ad58[i];
                    gob->gob_work2 = (DAT_0045ada8[i] + gob->gob_work3 - 1) << 16 | gob->gob_work3 & 0xffff;
                }
                gob->gob_work3 <<= 16;
            }
        }
        gob->gob_currentFrameIndex = gob->gob_work3 >> 16;
    }
}
}
