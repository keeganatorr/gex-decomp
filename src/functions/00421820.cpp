// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;  /* 0x78 */
    int gob_ypos;  /* 0x7c */
} GXObject;
extern "C" {
// CLD_ComputeAngleEdges fills a 40-byte record; this caller reads words 6 and 7.
extern int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *, int *);
extern unsigned int __cdecl GetTileFlagsAtPosition_00420c10(int, int);
int __cdecl GEX_Target(GXObject *gob)
{
    int edges[10];
    int y;
    if (CLD_ComputeAngleEdges_0041cb80(gob, edges)) {
        y = gob->gob_ypos - 0x300000;
        if (!(GetTileFlagsAtPosition_00420c10(edges[6] + 0x100000, y) & 0x80000000) &&
            !(GetTileFlagsAtPosition_00420c10(edges[7] - 0x100000, y) & 0x80000000) &&
            !(GetTileFlagsAtPosition_00420c10(gob->gob_xpos, y) & 0x80000000))
            return 0;
    }
    return 1;
}
}
