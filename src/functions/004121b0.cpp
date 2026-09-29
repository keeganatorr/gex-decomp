typedef struct CLDEdges {
    int points[6];
    int left;
    int right;
    int top;
    int bottom;
} CLDEdges;
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
extern GXObject *gPlayerPlatform_004a2864;
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, CLDEdges *edges);
void __cdecl FUN_00411ff0_SideInside90Trans(GXObject *gex, int x, int y);
void __cdecl FUN_004121b0_SideInside90Trans_Outer(GXObject *gex, int x, int y)
{
    CLDEdges edges;
    int dir;
    GOB_ResetState_00420bc0(gex);
    if (gPlayerPlatform_004a2864 && CLD_ComputeAngleEdges_0041cb80(gPlayerPlatform_004a2864, &edges)) {
        dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
        if (x) {
            if (dir != 0xe)
                gex->gob_xpos = edges.left - 0x180000;
            else
                gex->gob_xpos = edges.right + 0x180000;
        }
        if (y)
            gex->gob_ypos = edges.bottom + 0x180000;
        FUN_00411ff0_SideInside90Trans(gex, x ? 2 : 0, y ? 2 : 0);
    }
}
}
