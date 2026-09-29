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
    unsigned char _pad9c[0xa8 - 0x9c];
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
    unsigned char _padb0[0xc4 - 0xb0];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern CornerOffset DAT_00457F68[];
extern CornerRow DAT_00458488[];
extern int DAT_004583e8[][5];
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
int __cdecl FUN_00421560_DrawCharacter(void *level, GXObject *gex);
void __cdecl PlayerSideInside90Trans_00411e40(GXObject *gex);
void __cdecl FUN_004120c0_SideInside90Trans(GXObject *gex)
{
    int dir;
    unsigned int x;
    GOB_ResetState_00420bc0(gex);
    dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
    gex->gob_work0 = 0;
    gex->gob_state = 0x42;
    gex->gob_currentFrameGroup = 0x51;
    gex->gob_xpos &= 0xffe00000;
    gex->gob_currentFrameIndex = 0;
    gex->gob_xpos |= DAT_00457F68[dir].dx;
    gex->gob_ypos += 0x200000;
    x = gex->gob_xpos;
    gex->gob_xpos += dir != 4 ? 0x10000 : -0x10000;
    FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, gex);
    gex->gob_xpos = x;
    gex->gob_ypos -= 0x180000;
    gex->gob_xpos += DAT_004583e8[DAT_00458488[dir].ix][gex->gob_currentFrameIndex];
    gex->gob_ypos += DAT_004583e8[DAT_00458488[dir].iy][gex->gob_currentFrameIndex];
    gex->gob_work4 = 0;
    gex->gob_work5 = 0;
    PlayerSideInside90Trans_00411e40(gex);
}
}
