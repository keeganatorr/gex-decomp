typedef struct GXObject GXObject;
typedef struct Contour {
    int unk0;
    int baseY;                 /* 0x4 */
    int count;                 /* 0x8 */
    unsigned char heights[4];  /* 0xc */
} Contour;
typedef struct Tile {
    unsigned int flags;        /* 0x0: 2 = has contour */
    int unk4[7];
    Contour *contour;          /* 0x20 */
} Tile;
typedef struct AngleEdge {
    Tile *tile;                /* 0x0 */
    int unk4;
    int unk8;
    int y;                     /* 0xc */
    int flipped;               /* 0x10 */
    int unk14[3];
    int edge;                  /* 0x20 */
} AngleEdge;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern GXObject *gPlayerPlatform_004a2864;
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *platform, AngleEdge *edge);
int __cdecl GEX_Target(int unused, AngleEdge *edge, int *left, int *right)
{
    Contour *contour;
    int index;
    int height;
    if (gPlayerPlatform_004a2864) {
        if (CLD_ComputeAngleEdges_0041cb80(gPlayerPlatform_004a2864, edge)) {
            *left = edge->edge;
            *right = edge->edge;
            if (edge->tile->flags & 2) {
                contour = edge->tile->contour;
                index = 0;
                if (edge->flipped)
                    index = contour->count - 1;
                height = contour->heights[index];
                if (height)
                    *left = (contour->baseY + (height - 1) * 0x10000) + edge->y;
                index = !edge->flipped ? contour->count - 1 : 0;
                height = contour->heights[index];
                if (height)
                    *right = (contour->baseY + (height - 1) * 0x10000) + edge->y;
            }
            return 1;
        }
    }
    return 0;
}
}
