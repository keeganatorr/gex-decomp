typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x78 - 0x58];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xac - 0x80];
    int gob_work5;              /* 0xac */
    unsigned char _padb0[0xe0 - 0xb0];
    unsigned int gob_flags2;    /* 0xe0 */
} GXObject;
extern "C" {
extern unsigned int gCollectibles_004a2660[6];
extern LevelEntry DAT_004577B0[];
extern int DAT_004561fc;
extern int DAT_00456200;
extern int DAT_00456204;
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    unsigned char frames[21];
    unsigned int *p;
    int x;
    int y;
    int i;
    unsigned int c;
    gob->gob_flags2 |= 0x1000000;
    x = gob->gob_xpos;
    y = gob->gob_ypos;
    frames[0] = 0;
    frames[1] = 0;
    frames[2] = 0;
    frames[3] = 2;
    frames[4] = 8;
    frames[5] = 14;
    frames[6] = 1;
    frames[7] = 7;
    frames[8] = 13;
    frames[9] = 4;
    frames[10] = 10;
    frames[11] = 16;
    frames[12] = 5;
    frames[13] = 11;
    frames[14] = 17;
    frames[15] = 3;
    frames[16] = 9;
    frames[17] = 15;
    frames[18] = 0;
    frames[19] = 6;
    frames[20] = 12;
    gob->gob_xpos = DAT_004561fc;
    gob->gob_ypos = DAT_00456200;
    i = 0;
    for (p = gCollectibles_004a2660; p < &gCollectibles_004a2660[6]; p++, i++) {
        c = *p;
        if (c != 4 && c != 3) {
            gob->gob_currentFrameIndex = (gob->gob_work5 + i) % 38 + frames[(DAT_004577B0[(int)((c & 0xffff00) >> 8)].info & 0xf) * 3 + ((c & 0xf000000) >> 24)] * 38;
            GOB_DisplayObject_00444590(gob);
            gob->gob_xpos += DAT_00456204;
        }
    }
    gob->gob_currentFrameIndex = -1;
    if (++gob->gob_work5 >= 38)
        gob->gob_work5 = 0;
    gob->gob_xpos = x;
    gob->gob_ypos = y;
}
}
