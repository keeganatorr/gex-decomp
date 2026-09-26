typedef struct CornerOffset { int dx; int dy; } CornerOffset;
typedef struct CornerRow { int ix; int iy; } CornerRow;
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x78 - 0x74];
    unsigned int gob_xpos;      /* 0x78 */
    unsigned int gob_ypos;      /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern GXObject *gPlayerPlatform_004a2864;
extern unsigned int DAT_00457EE8[];
extern CornerOffset DAT_00457F68[];
extern CornerRow DAT_004585E8[];
extern int DAT_00458548[][5];
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl FUN_004112e0_PlatCorner(GXObject *gex, unsigned int corner);
void __cdecl PlayerSideOutside90Trans_00412290(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    int dir;
    GOB_ResetState_00420bc0(gex);
    dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
    gex->gob_state = 0x44;
    gex->gob_work0 = 0;
    gex->gob_currentFrameGroup = 0x52;
    gex->gob_currentFrameIndex = 0;
    if (gPlayerPlatform_004a2864)
        FUN_004112e0_PlatCorner(gex, DAT_00457EE8[dir]);
    else {
        gex->gob_xpos &= 0xffe00000;
        gex->gob_ypos &= 0xffe00000;
    }
    gex->gob_xpos += DAT_00457F68[dir].dx;
    gex->gob_ypos += DAT_00457F68[dir].dy;
    gex->gob_xpos += DAT_00458548[DAT_004585E8[dir].ix][gex->gob_currentFrameIndex];
    gex->gob_ypos += DAT_00458548[DAT_004585E8[dir].iy][gex->gob_currentFrameIndex];
    PlayerSideOutside90Trans_00412290(gex);
}
}
