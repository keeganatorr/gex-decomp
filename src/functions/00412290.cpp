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
extern GXObject *gPlayerPlatform_004a2864;
extern unsigned int FUN_00458668[];
extern unsigned int FUN_00457F28[];
extern CornerOffset DAT_00457FE8[];
extern CornerRow DAT_004585E8[];
extern int DAT_00458548[][5];
int __cdecl FUN_00421f20_pStateUnk_Side(GXObject *gex);
void __cdecl FUN_00421cd0_xpos_ypos_related(GXObject *gex);
void __cdecl FUN_004112e0_PlatCorner(GXObject *gex, unsigned int corner);
void __cdecl InitPlayerSideCrawl_00411160(GXObject *gex);
void __cdecl PlayerSideOutside90Trans_00412290(GXObject *gex)
{
    int dir;
    unsigned int next;
    if (FUN_00421f20_pStateUnk_Side(gex)) {
        FUN_00421cd0_xpos_ypos_related(gex);
        if ((gex->gob_work0 += 0x8000) > 0x10000) {
            dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
            gex->gob_work0 -= 0x10000;
            gex->gob_currentFrameIndex++;
            gex->gob_xpos += DAT_00458548[DAT_004585E8[dir].ix][gex->gob_currentFrameIndex];
            gex->gob_ypos += DAT_00458548[DAT_004585E8[dir].iy][gex->gob_currentFrameIndex];
            if (gex->gob_currentFrameIndex > 3) {
                next = FUN_00458668[dir];
                gex->gob_flags &= 0x7fffffff;
                gex->gob_angle = (next & 7) << 21;
                if (next & 8)
                    gex->gob_flags |= 0x80000000;
                if (gPlayerPlatform_004a2864)
                    FUN_004112e0_PlatCorner(gex, FUN_00457F28[next]);
                else {
                    gex->gob_xpos &= 0xffe00000;
                    gex->gob_ypos &= 0xffe00000;
                }
                gex->gob_xpos += DAT_00457FE8[next].dx;
                gex->gob_ypos += DAT_00457FE8[next].dy;
                InitPlayerSideCrawl_00411160(gex);
            }
        }
    }
}
}
