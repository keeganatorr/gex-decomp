typedef struct DiveTrail { int x0, y0, x1, y1; } DiveTrail;
typedef struct DiveDelay { int d0, d1, d2, d3; } DiveDelay;
typedef struct DiveAngles { int a0, a1, a2; } DiveAngles;
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x9c - 0x80];
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned char _pada4[0xd4 - 0xa4];
    int gob_oldX;               /* 0xd4 */
    int gob_oldY;               /* 0xd8 */
} GXObject;
extern "C" {
extern GXObject *PTR_ARRAY_00464610[];
extern DiveAngles UINT_ARRAY_ARRAY_004645b0[];
extern DiveTrail PTR_00464518[];
extern DiveDelay DAT_00464660[];
extern int DAT_004646f0;
extern int DAT_004646f8;
unsigned int __cdecl FUN_004391d0_HuntDiveInner(int a, int b, int c);
void __cdecl GEX_Target(GXObject *gob)
{
    int i;
    GXObject *seg;
    int depth;
    i = gob->gob_work1;
    seg = PTR_ARRAY_00464610[i];
    UINT_ARRAY_ARRAY_004645b0[i].a2 = UINT_ARRAY_ARRAY_004645b0[i].a1;
    UINT_ARRAY_ARRAY_004645b0[i].a1 = UINT_ARRAY_ARRAY_004645b0[i].a0;
    UINT_ARRAY_ARRAY_004645b0[i].a0 = seg->gob_work2;
    PTR_00464518[i + 1].x1 = PTR_00464518[i + 1].x0;
    PTR_00464518[i + 1].y1 = PTR_00464518[i + 1].y0;
    PTR_00464518[i + 1].x0 = gob->gob_oldX;
    PTR_00464518[i + 1].y0 = gob->gob_oldY;
    gob->gob_oldX = gob->gob_xpos;
    gob->gob_oldY = gob->gob_ypos;
    DAT_00464660[i].d3 = DAT_00464660[i].d2;
    DAT_00464660[i].d2 = DAT_00464660[i].d1;
    DAT_00464660[i].d1 = DAT_00464660[i].d0;
    if (i > 0)
        DAT_00464660[i].d0 = DAT_00464660[i - 1].d3;
    else if (DAT_004646f0 != 5)
        DAT_00464660[i].d0 = (FUN_004391d0_HuntDiveInner(0, PTR_00464518[0].y1, DAT_004646f8) & 0xffffff00) * 0x60;
    else {
        depth = DAT_004646f8;
        if (depth > 0x600000)
            depth = 0x600000;
        DAT_00464660[i].d0 = depth;
    }
    if (i > 0 && DAT_004646f0 != 5) {
        PTR_ARRAY_00464610[i]->gob_xpos = PTR_00464518[i].x1;
        PTR_ARRAY_00464610[i]->gob_ypos = PTR_00464518[i].y1;
        gob->gob_work2 = UINT_ARRAY_ARRAY_004645b0[i - 1].a2;
    } else if (i > 0 && DAT_004646f0 == 5) {
        PTR_ARRAY_00464610[i]->gob_xpos = PTR_00464518[i].x0;
        PTR_ARRAY_00464610[i]->gob_ypos = PTR_00464518[i].y0;
        gob->gob_work2 = UINT_ARRAY_ARRAY_004645b0[i - 1].a2;
    }
}
}
