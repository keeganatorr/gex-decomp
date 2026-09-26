typedef struct CornerOffset { int dx; int dy; } CornerOffset;
typedef struct CornerRow { int ix; int iy; } CornerRow;
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    unsigned int gob_xpos;      /* 0x78 */
    unsigned int gob_ypos;      /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern unsigned int DAT_00458328[];
extern CornerOffset DAT_00457FE8[];
extern CornerRow DAT_004582a8[];
extern int DAT_00458208[][5];
int __cdecl FUN_00421f20_pStateUnk_Side(GXObject *gex);
void __cdecl InitPlayerSideCrawl_00411160(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    unsigned int dir;
    if (FUN_00421f20_pStateUnk_Side(gex)) {
        if ((gex->gob_work0 += 0x8000) > 0x10000) {
            dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
            gex->gob_work0 -= 0x10000;
            gex->gob_currentFrameIndex++;
            gex->gob_xpos += DAT_00458208[DAT_004582a8[dir].ix][gex->gob_currentFrameIndex];
            gex->gob_ypos += DAT_00458208[DAT_004582a8[dir].iy][gex->gob_currentFrameIndex];
            if (gex->gob_currentFrameIndex > 3) {
                dir = DAT_00458328[dir];
                gex->gob_flags &= 0x7fffffff;
                gex->gob_angle = (dir & 7) << 21;
                if (dir & 8)
                    gex->gob_flags |= 0x80000000;
                gex->gob_xpos &= 0xffe00000;
                gex->gob_xpos |= DAT_00457FE8[dir].dx;
                gex->gob_ypos &= 0xffe00000;
                gex->gob_ypos |= DAT_00457FE8[dir].dy;
                InitPlayerSideCrawl_00411160(gex);
            }
        }
    }
}
}
