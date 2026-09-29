typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x78 - 0x58];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x8c - 0x80];
    int gob_yVel;               /* 0x8c */
    unsigned char _pad90[0xa0 - 0x90];
    int gob_work2;              /* 0xa0 */
    unsigned char _pada4[0xa8 - 0xa4];
    int gob_work4;              /* 0xa8 */
    unsigned char _padac[0x1f8 - 0xac];
    int gob_last_x;             /* 0x1f8 */
    int gob_last_y;             /* 0x1fc */
} GXObject;
extern "C" {
extern int DAT_00462c78;
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    int x;
    int y;
    int frame;
    int lastX;
    int lastY;

    x = gob->gob_xpos;
    y = gob->gob_ypos;
    lastX = gob->gob_last_x;
    lastY = gob->gob_last_y;
    frame = gob->gob_currentFrameIndex;
    gob->gob_last_x = gob->gob_work4 + gob->gob_yVel * 2;
    gob->gob_xpos = gob->gob_work4 + gob->gob_yVel;
    gob->gob_last_y = gob->gob_ypos = gob->gob_work2;
    gob->gob_currentFrameIndex = 3;
    GOB_DisplayObject_00444590(gob);
    if (gob->gob_yVel <= 0) {
        if (DAT_00462c78) {
            if (DAT_00462c78 <= 0x20000) {
                gob->gob_last_x = gob->gob_xpos = gob->gob_work4 - 0xc0000;
                gob->gob_last_y = gob->gob_ypos = gob->gob_work2 - 0x940000;
                gob->gob_currentFrameIndex = 6;
                GOB_DisplayObject_00444590(gob);
            }
            DAT_00462c78 -= 0x8000;
        }
    } else {
        gob->gob_yVel >>= 2;
        gob->gob_xpos = x;
        gob->gob_ypos = y;
        gob->gob_last_x = lastX;
        gob->gob_last_y = lastY;
        gob->gob_currentFrameIndex = frame;
    }
}
}
