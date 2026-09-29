typedef struct WallProbe { int dx; int dy; } WallProbe;
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xc4 - 0x80];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern WallProbe DAT_0045A710[];
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(void *level, int x, int y);
int __cdecl FUN_004218a0_CheckWallCollision(GXObject *gex)
{
    int dir;
    dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
    return M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, DAT_0045A710[dir].dx + gex->gob_xpos, DAT_0045A710[dir].dy + gex->gob_ypos) == 0x57;
}
}
