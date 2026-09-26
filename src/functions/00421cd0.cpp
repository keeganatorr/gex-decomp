// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;   /* 0x78 */
    int gob_ypos;   /* 0x7c */
    unsigned char _pad80[0x54];
    int gob_xold;   /* 0xd4 */
    int gob_yold;   /* 0xd8 */
} GXObject;
extern "C" {
extern GXObject *gPlayerPlatform_004a2864;
extern int DAT_00463ac8;
extern int gTimer_004a2ac8;
extern void *M1_CurrentLevel_004a2990;
void __cdecl TILES_CheckXTileClid_0042d060(void *level, GXObject *gob, int flags);
void __cdecl TILES_CheckYTileClid_0042d2c0(void *level, GXObject *gob, int flags);
void __cdecl GEX_Target(GXObject *gob)
{
    int dy;
    if (gPlayerPlatform_004a2864 && gTimer_004a2ac8 != DAT_00463ac8) {
        DAT_00463ac8 = gTimer_004a2ac8;
        dy = gPlayerPlatform_004a2864->gob_ypos - gPlayerPlatform_004a2864->gob_yold;
        gob->gob_xpos += gPlayerPlatform_004a2864->gob_xpos - gPlayerPlatform_004a2864->gob_xold;
        TILES_CheckXTileClid_0042d060(M1_CurrentLevel_004a2990, gob, 0);
        gob->gob_ypos += dy;
        TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, 0);
    }
}
}
