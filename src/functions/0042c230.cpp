typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;

typedef struct GXObject {
    unsigned char pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char pad58[0x78 - 0x58];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned int gob_work1;     /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
    int gob_work7;              /* 0xb4 */
    int gob_work8;              /* 0xb8 */
    int gob_work9;              /* 0xbc */
    unsigned char padc0[0xc8 - 0xc0];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
    unsigned char padd0[0x1f4 - 0xd0];
    int gob_unk1f4;             /* 0x1f4 */
} GXObject;

extern "C" {
extern GXObject GXObject_00463b70;
extern int INT_ARRAY_ARRAY_00463b10[][2];
extern int DAT_00463d74;
extern int DAT_0045ae78;
extern int DAT_0045adf4;
extern int DAT_0045aecc;
extern LevelEntry DAT_004577B0[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern int DAT_0045add0[];
void __cdecl FUN_0042b760(int, int);
void __cdecl FUN_0042bfe0_TV_Level_unk(GXObject *, int);
GXObject * __cdecl GOB_FindWithWork0_0040c110(int type, int work0);
void __cdecl FUN_0042ca40_UnknownSwitchCase(GXObject *);
void __cdecl FUN_0042c860(GXObject *, int, int);
void __cdecl FUN_0042c1a0(GXObject *);
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
void __cdecl VFX_Play_0041fa80(int);
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *);

void __cdecl GEX_Target(GXObject *gob)
{
    struct { int y; int xScale; int yScale; int work9; } saved;
    int restore;
    int step;
    int level;
    int index;
    int i;
    GXObject *other;
    int n;

    switch (INT_ARRAY_ARRAY_00463b10[4][0]) {
    case 0:
        restore = 0;
        if (INT_ARRAY_ARRAY_00463b10[5][0] && gob->gob_work3 == -2) {
            INT_ARRAY_ARRAY_00463b10[5][0] = 0;
            gob->gob_work3 = 0;
            gob->gob_xScale = 0x10000;
            gob->gob_yScale = 0x10000;
        }
        if (gob->gob_work3 <= -2) {
            FUN_0042ca40_UnknownSwitchCase(gob);
            gob->gob_work3++;
            if (INT_ARRAY_ARRAY_00463b10[5][0]) {
                DAT_0045aecc += DAT_0045adf4;
                saved.y = gob->gob_ypos;
                gob->gob_ypos = DAT_0045aecc;
            } else {
                gob->gob_ypos += DAT_0045adf4;
                saved.y = gob->gob_ypos;
            }
            saved.xScale = gob->gob_xScale;
            saved.yScale = gob->gob_yScale;
            saved.work9 = gob->gob_work9;
            restore = 1;
            step = gob->gob_work3 + INT_ARRAY_ARRAY_00463b10[5][1] + 2;
            if (gob->gob_xScale != gob->gob_yScale) {
                if (!gob->gob_xScale)
                    gob->gob_xScale = gob->gob_yScale;
                else if (!gob->gob_yScale)
                    gob->gob_yScale = gob->gob_xScale;
            }
            if (gob->gob_xScale > 0)
                gob->gob_xScale -= step * INT_ARRAY_ARRAY_00463b10[7][1];
            else
                gob->gob_xScale += step * INT_ARRAY_ARRAY_00463b10[7][1];
            if (gob->gob_yScale > 0)
                gob->gob_yScale -= step * INT_ARRAY_ARRAY_00463b10[7][1];
            else
                gob->gob_yScale += step * INT_ARRAY_ARRAY_00463b10[7][1];
            gob->gob_unk1f4 = 0;
        } else if (gob->gob_work3 == 1 && gob->gob_work0 > 5) {
            gob->gob_work5 = gob->gob_work6;
            FUN_0042c860(gob, GXObject_00463b70.gob_xpos - INT_ARRAY_ARRAY_00463b10[3][0], GXObject_00463b70.gob_ypos - INT_ARRAY_ARRAY_00463b10[3][1]);
            FUN_0042c1a0(gob);
            FUN_0042ca40_UnknownSwitchCase(gob);
            gob->gob_xpos = INT_ARRAY_ARRAY_00463b10[3][0];
            gob->gob_ypos = INT_ARRAY_ARRAY_00463b10[3][1];
            INT_ARRAY_ARRAY_00463b10[3][0] = INT_ARRAY_ARRAY_00463b10[2][0];
            INT_ARRAY_ARRAY_00463b10[3][1] = INT_ARRAY_ARRAY_00463b10[2][1];
            INT_ARRAY_ARRAY_00463b10[2][0] = INT_ARRAY_ARRAY_00463b10[1][0];
            INT_ARRAY_ARRAY_00463b10[2][1] = INT_ARRAY_ARRAY_00463b10[1][1];
            INT_ARRAY_ARRAY_00463b10[1][0] = INT_ARRAY_ARRAY_00463b10[0][0];
            INT_ARRAY_ARRAY_00463b10[1][1] = INT_ARRAY_ARRAY_00463b10[0][1];
            INT_ARRAY_ARRAY_00463b10[0][0] = GXObject_00463b70.gob_xpos;
            INT_ARRAY_ARRAY_00463b10[0][1] = GXObject_00463b70.gob_ypos;
        } else if (gob->gob_work3 == -1) {
            n = DAT_00463d74;
            if (n < 4)
                n--;
            else
                n = 4;
            if (n - gob->gob_work0 == -2) {
                other = GOB_FindWithWork0_0040c110(0xdc, gob->gob_work1 & 0xffff);
                level = other->gob_work1;
                if (level < 0)
                    SND_PlaySoundNoPosition_0041a360(0x9d, 0xff);
                else if (BYTE_ARRAY_004a2540[level] & 2)
                    SND_PlaySoundNoPosition_0041a360(0x97, 0xff);
                else if (BYTE_ARRAY_004a2540[level] & 1) {
                    index = DAT_004577B0[level].info & 0xf;
                    SND_PlaySoundNoPosition_0041a360(DAT_0045add0[index], 0xff);
                    if (index == 4)
                        VFX_Play_0041fa80(7);
                } else
                    SND_PlaySoundNoPosition_0041a360(0x9d, 0xff);
                gob->gob_work0 = DAT_00463d74 - 1;
                gob->gob_work5 = gob->gob_work6;
                if (gob->gob_work5 != 4) {
                    gob->gob_currentFrameGroup = 0x19;
                    gob->gob_work2 = 8;
                }
                gob->gob_work6 = 4;
                gob->gob_xScale = GXObject_00463b70.gob_xScale;
                FUN_0042c1a0(gob);
            }
            FUN_0042ca40_UnknownSwitchCase(gob);
            i = gob->gob_work0;
            if (INT_ARRAY_ARRAY_00463b10[i][0]) {
                gob->gob_xpos = INT_ARRAY_ARRAY_00463b10[i][0];
                gob->gob_ypos = INT_ARRAY_ARRAY_00463b10[i][1];
            }
            gob->gob_work0 = --i;
            if (i < 0) {
                other = GOB_FindWithWork0_0040c110(0xdc, gob->gob_work1 & 0xffff);
                level = other->gob_work1;
                if (((unsigned char)DAT_004577B0[level].info & 0xf) == 2 && (BYTE_ARRAY_004a2540[level] & 1))
                    SND_PlaySoundNoPosition_0041a360(0xa0, 0xff);
                gob->gob_work0 = 0;
                gob->gob_work3 = 0;
                gob->gob_currentFrameGroup = 0x19;
                gob->gob_work2 = 8;
                gob->gob_work6 = 4;
                gob->gob_currentFrameIndex %= 8;
            }
        } else if (gob->gob_work0) {
            if (gob->gob_work0 == 1) {
                gob->gob_work5 = gob->gob_work6;
                FUN_0042c860(gob, GXObject_00463b70.gob_xpos - INT_ARRAY_ARRAY_00463b10[8][0], GXObject_00463b70.gob_ypos - INT_ARRAY_ARRAY_00463b10[8][1]);
                FUN_0042c1a0(gob);
            }
            FUN_0042ca40_UnknownSwitchCase(gob);
            if (gob->gob_work0 > 3) {
                INT_ARRAY_ARRAY_00463b10[3][0] = INT_ARRAY_ARRAY_00463b10[2][0];
                INT_ARRAY_ARRAY_00463b10[3][1] = INT_ARRAY_ARRAY_00463b10[2][1];
            }
            if (gob->gob_work0 > 2) {
                INT_ARRAY_ARRAY_00463b10[2][0] = INT_ARRAY_ARRAY_00463b10[1][0];
                INT_ARRAY_ARRAY_00463b10[2][1] = INT_ARRAY_ARRAY_00463b10[1][1];
            }
            if (gob->gob_work0 > 1) {
                INT_ARRAY_ARRAY_00463b10[1][0] = INT_ARRAY_ARRAY_00463b10[0][0];
                INT_ARRAY_ARRAY_00463b10[1][1] = INT_ARRAY_ARRAY_00463b10[0][1];
            }
            INT_ARRAY_ARRAY_00463b10[0][0] = GXObject_00463b70.gob_xpos;
            INT_ARRAY_ARRAY_00463b10[0][1] = GXObject_00463b70.gob_ypos;
            gob->gob_work0++;
            if (DAT_00463d74 < 4)
                DAT_00463d74++;
        }
        GOB_DisplayObjectScaleAndRotate_00441150(gob);
        gob->gob_currentFrameIndex = gob->gob_work4 >> 16;
        gob->gob_work4 += 0x8000;
        if (gob->gob_currentFrameIndex >= gob->gob_work2) {
            gob->gob_work4 = 0;
            gob->gob_currentFrameIndex = 0;
        }
        if (restore) {
            gob->gob_xScale = saved.xScale;
            gob->gob_yScale = saved.yScale;
            gob->gob_work9 = saved.work9;
            gob->gob_ypos = saved.y;
        }
        break;
    case 1:
        if (DAT_0045ae78 < ++INT_ARRAY_ARRAY_00463b10[6][1]) {
            FUN_0042bfe0_TV_Level_unk(gob, INT_ARRAY_ARRAY_00463b10[4][1]);
            gob->gob_work1 = gob->gob_work1 & 0xffff0000 | INT_ARRAY_ARRAY_00463b10[4][1];
            GOB_FindWithWork0_0040c110(0xdc, INT_ARRAY_ARRAY_00463b10[4][1]);
            INT_ARRAY_ARRAY_00463b10[4][0] = 2;
            INT_ARRAY_ARRAY_00463b10[6][1] = 0;
            return;
        }
        FUN_0042b760(gob->gob_xpos, gob->gob_ypos);
        break;
    case 2:
        if (DAT_0045ae78 < ++INT_ARRAY_ARRAY_00463b10[6][1]) {
            INT_ARRAY_ARRAY_00463b10[4][0] = 0;
            return;
        }
        FUN_0042b760(gob->gob_xpos, gob->gob_ypos);
        break;
    }
}
}
