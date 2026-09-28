typedef struct GXObject {
    unsigned char _pad0[0x6c];
    int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x8];
    int gob_xpos;      /* 0x78 */
    int gob_ypos;      /* 0x7c */
    unsigned char _pad80[0x44];
    int gob_angle;     /* 0xc4 */
} GXObject;
typedef struct ContourData {
    int unk0;
    int base;
    int last;
    unsigned char heights[1];
} ContourData;
typedef struct Contour {
    unsigned int flags;
    int unk4[7];
    ContourData *data;
} Contour;
typedef struct AngleBox {
    Contour *contour;
    int unk4[3];
    int flip;    /* 0x10 */
    int unk14;
    int left;    /* 0x18 */
    int right;   /* 0x1c */
    int top;     /* 0x20 */
    int bottom;  /* 0x24 */
} AngleBox;
typedef struct AngleProbe {
    int dx;
    int dy;
    int attr;
} AngleProbe;
typedef struct GexTileStruct GexTileStruct;
extern "C" {
extern GXObject *gPlayerPlatform_004a2864;
extern GexTileStruct *M1_CurrentLevel_004a2990;
extern AngleProbe DAT_0045a7d0[];
void __cdecl FUN_00421cd0_xpos_ypos_related(GXObject *gob);
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, AngleBox *box);
int __cdecl FUN_00420c40_CheckWallCollision(GexTileStruct *level, int x, int y);
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(GexTileStruct *level, int x, int y);
void __cdecl TILES_CheckXTileClid_0042d060(GexTileStruct *level, GXObject *gob, void *callback);
void __cdecl TILES_CheckYTileClid_0042d2c0(GexTileStruct *level, GXObject *gob, void *callback);
void __cdecl FUN_004211d0(GXObject *gob);
void __cdecl FUN_00421120(GXObject *gob);

int __cdecl GEX_Target(GXObject *gob)
{
    AngleBox box;
    unsigned int index;
    int wall;
    int flags;
    ContourData *data;
    int low;
    int high;
    int swap;

    flags = gob->gob_flags;
    if (gPlayerPlatform_004a2864) {
        index = (flags & 0x80000000 ? 8 : 0) | gob->gob_angle >> 21;
        FUN_00421cd0_xpos_ypos_related(gob);
        if (CLD_ComputeAngleEdges_0041cb80(gPlayerPlatform_004a2864, &box)) {
            low = 0;
            high = 0;
            if (box.contour->flags & 2) {
                data = box.contour->data;
                low = (data->heights[0] - 1 << 16) + data->base;
                high = (data->heights[data->last] - 1 << 16) + data->base;
                if (box.flip) {
                    swap = low;
                    low = high;
                    high = swap;
                }
            }
            switch (index) {
            case 0:
            case 12:
                if (box.top + high <= gob->gob_ypos - 0x180000 && gob->gob_ypos + 0x180000 <= box.bottom
                    && gob->gob_xpos - 0x10000 <= box.right && box.right <= gob->gob_xpos + 0x10000)
                    return 1;
                break;
            case 2:
            case 14:
                if (box.left <= gob->gob_xpos - 0x180000 && gob->gob_xpos + 0x180000 <= box.right
                    && gob->gob_ypos - 0x10000 <= box.bottom && box.bottom <= gob->gob_ypos + 0x10000)
                    return 1;
                break;
            case 4:
            case 8:
                if (box.top + low <= gob->gob_ypos - 0x180000 && gob->gob_ypos + 0x180000 <= box.bottom
                    && gob->gob_xpos - 0x10000 <= box.left && box.left <= gob->gob_xpos + 0x10000)
                    return 1;
                break;
            }
        }
        return 0;
    }
    index = (flags & 0x80000000 ? 8 : 0) | gob->gob_angle >> 21;
    wall = FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos);
    if (wall != DAT_0045a7d0[index].attr)
        return 0;
    wall = FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, gob->gob_xpos + DAT_0045a7d0[index].dx, gob->gob_ypos + DAT_0045a7d0[index].dy);
    if (wall != DAT_0045a7d0[index].attr)
        return 0;
    wall = FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, gob->gob_xpos - DAT_0045a7d0[index].dx, gob->gob_ypos - DAT_0045a7d0[index].dy);
    if (wall != DAT_0045a7d0[index].attr)
        return 0;
    switch (M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos)) {
    case 0x2d:
        gob->gob_xpos -= 0x30000;
        TILES_CheckXTileClid_0042d060(M1_CurrentLevel_004a2990, gob, 0);
        break;
    case 0x2e:
        gob->gob_xpos += 0x30000;
        TILES_CheckXTileClid_0042d060(M1_CurrentLevel_004a2990, gob, 0);
        break;
    case 0x4e:
        gob->gob_ypos -= 0x30000;
        TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, 0);
        break;
    case 0x4f:
        gob->gob_ypos += 0x30000;
        TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, 0);
        break;
    }
    switch (index) {
    case 0:
    case 4:
    case 8:
    case 12:
        FUN_004211d0(gob);
        TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, 0);
        break;
    case 2:
    case 14:
        FUN_00421120(gob);
        TILES_CheckXTileClid_0042d060(M1_CurrentLevel_004a2990, gob, 0);
        break;
    }
    return 1;
}
}
