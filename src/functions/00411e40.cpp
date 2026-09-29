// State 66: move Gex around the inside of a ninety-degree corner.
typedef struct CornerOffset { int dx; int dy; } CornerOffset;
typedef struct CornerRow { int ix; int iy; } CornerRow;
typedef struct CLDEdges {
    int points[6];
    int left;
    int right;
    int top;
    int bottom;
} CLDEdges;

extern "C" {
extern int DAT_004583e8[][5];
extern CornerRow DAT_00458488[];
extern int DAT_00458508[];
extern CornerOffset DAT_00458368[];
extern int gPlayerPlatform_004a2864;

void __cdecl FUN_00421cd0_xpos_ypos_related(int *);
int __cdecl FUN_00421f20_pStateUnk_Side(int *);
int __cdecl FUN_0041CB80(int *, CLDEdges *);
void __cdecl FUN_00411160(int *);

void __cdecl PlayerSideInside90Trans_00411e40(int *gex)
{
    FUN_00421cd0_xpos_ypos_related(gex);
    if (!FUN_00421f20_pStateUnk_Side(gex))
        return;

    int phase = gex[0x26] + 0x8000;
    gex[0x26] = phase;
    if (phase <= 0x10000)
        return;
    gex[0x26] = phase - 0x10000;

    int dir = ((unsigned int)(gex[0x1b] & 0x80000000) >> 28) |
              (gex[0x31] >> 21);
    int index = ++gex[0x15];
    gex[0x1e] += DAT_004583e8[DAT_00458488[dir].ix][index];
    gex[0x1f] += DAT_004583e8[DAT_00458488[dir].iy][index];
    if (index <= 3)
        return;

    int exitDir = DAT_00458508[dir];
    gex[0x31] = (exitDir & 7) << 21;
    gex[0x1b] = (gex[0x1b] & 0x7fffffff) |
                ((exitDir & 8) ? 0x80000000 : 0);

    if (gex[0x2a] != 0) {
        if (gex[0x2a] == 2) {
            CLDEdges edges;
            if (gPlayerPlatform_004a2864 != 0 &&
                FUN_0041CB80((int *)gPlayerPlatform_004a2864, &edges))
                gex[0x1e] = exitDir ? edges.left : edges.right;
        } else {
            gex[0x1e] = (gex[0x1e] & 0xffe00000) |
                        DAT_00458368[exitDir].dx;
        }
    }
    if (gex[0x2b] != 0) {
        if (gex[0x2b] == 2) {
            CLDEdges edges;
            if (gPlayerPlatform_004a2864 != 0 &&
                FUN_0041CB80((int *)gPlayerPlatform_004a2864, &edges))
                gex[0x1f] = edges.bottom;
        } else {
            gex[0x1f] = (gex[0x1f] & 0xffe00000) |
                        DAT_00458368[exitDir].dy;
        }
    }
    FUN_00411160(gex);
}
}
