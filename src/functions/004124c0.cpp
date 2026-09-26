// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;      /* 0x54 */
    unsigned char _pad58[0x14];
    unsigned int gob_flags;         /* 0x6c */
    unsigned char _pad70[8];
    int gob_xpos;                   /* 0x78 */
    int gob_ypos;                   /* 0x7c */
    unsigned char _pad80[0x18];
    int gob_work0;                  /* 0x98 */
    unsigned char _pad9c[0x50];
    int gob_topEdge;                /* 0xec */
    unsigned char _padF0[0x20];
    struct GXObject *gob_platform;  /* 0x110 */
    int gob_platHitType;            /* 0x114 */
} GXObject;
typedef struct AngleEdge { int unk[10]; } AngleEdge;
typedef struct GexTileStruct GexTileStruct;
extern "C" {
extern int DAT_004586a8[];
extern int DAT_004586c0[];
extern GXObject *gPlayerPlatform_004a2864;
extern GexTileStruct *M1_CurrentLevel_004a2990;
int __cdecl FUN_00421f20_pStateUnk_Side(GXObject *gex);
int __cdecl FUN_00411230(GXObject *platform, AngleEdge *edge, int *left, int *right);
int __cdecl FUN_00421560_DrawCharacter(GexTileStruct *level, GXObject *gex);
void __cdecl InitPlayerStand_00424090(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    int left;
    int right;
    AngleEdge edge;
    int frame;
    GXObject *platform;
    if (FUN_00421f20_pStateUnk_Side(gex) && ++gex->gob_work0 >= 2) {
        frame = ++gex->gob_currentFrameIndex;
        gex->gob_work0 = 0;
        if (gex->gob_flags & 0x80000000)
            gex->gob_xpos += DAT_004586a8[frame];
        else
            gex->gob_xpos -= DAT_004586a8[frame];
        gex->gob_ypos += DAT_004586c0[frame];
        if (frame > 3) {
            if (gPlayerPlatform_004a2864) {
                FUN_00411230(gPlayerPlatform_004a2864, &edge, &left, &right);
                platform = gPlayerPlatform_004a2864;
                gex->gob_platHitType = 0;
                gex->gob_topEdge = 1;
                gex->gob_platform = platform;
                gPlayerPlatform_004a2864 = 0;
            }
            FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, gex);
            InitPlayerStand_00424090(gex);
        }
    }
}
}
