typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    unsigned char _padac[0xc8 - 0xac];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
} GXObject;
extern "C" {
extern int gMainState_004a2970;
extern int gGameState_00455c3c;
void __cdecl GOB_DisplayObjectAtPos_0041a030(GXObject *gob, int group, int frame, int x, int y);
void __cdecl FUN_0040b9f0_Unk(void);
void __cdecl ob109Draw_0040bab0(GXObject *gob)
{
    int frame;
    frame = gob->gob_work0 == 3 ? gob->gob_work3 >> 16 : 0;
    GOB_DisplayObjectAtPos_0041a030(gob, 0, frame, gob->gob_xpos, gob->gob_ypos);
    if (gob->gob_work1 != 0x140) {
        gob->gob_work1 += 4;
        if (gob->gob_work1 > 0x140)
            gob->gob_work1 = 0x140;
        gob->gob_xScale = 0x1400000 / gob->gob_work1 & ~0x3f;
    }
    if (gob->gob_work2 != 0x140) {
        gob->gob_work2 += 4;
        if (gob->gob_work2 > 0x140)
            gob->gob_work2 = 0x140;
        gob->gob_yScale = 0x1400000 / gob->gob_work2 & ~0x3f;
    }
    if (gob->gob_work0 == 3) {
        if (gob->gob_work4 == 1) {
            if ((gob->gob_work3 & ~0xffff) < 0x10000)
                gob->gob_work3 += 0x2000;
            else {
                gMainState_004a2970 = 2;
                gGameState_00455c3c = -1;
                FUN_0040b9f0_Unk();
            }
        }
        if (gob->gob_work0 == 3 && gob->gob_work1 == 0x140 && gob->gob_work2 == 0x140 && gob->gob_work4 == 0 && ((gob->gob_work3 += 0x2000) & ~0xffff) == 0x40000) {
            gob->gob_work3 = 0;
            gob->gob_work4 = 1;
        }
    }
}
}
