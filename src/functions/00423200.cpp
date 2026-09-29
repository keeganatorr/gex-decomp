typedef struct CLDEdges {
    int points[6];
    int left;
    int right;
    int top;
    int bottom;
} CLDEdges;
typedef struct GXObject {
    unsigned char _pad0[0x70];
    int gob_size;               /* 0x70 */
    unsigned char _pad74[0x78 - 0x74];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xc4 - 0x80];
    int gob_angle;              /* 0xc4 */
} GXObject;
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
extern int INT_ARRAY_00456f40[];
extern char DAT_004a286c[];
extern char DAT_004a2820[];
extern char DAT_004a2848[];
extern char DAT_004a2868[];
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, CLDEdges *edges);
void __cdecl FUN_00423200_pStateUnk(GXObject *gob, GXObject *other)
{
    CLDEdges edges;
    int x0;
    int x1;
    int y0;
    int y1;
    int x;
    int i;
    int j;
    if (CLD_ComputeAngleEdges_0041cb80(other, &edges)) {
        if ((gob->gob_angle + 0x200000) & 0x400000) {
            x0 = gob->gob_xpos - 0x180000;
            x1 = gob->gob_xpos + 0x180000;
            y0 = gob->gob_ypos - 0x100000;
            y1 = gob->gob_ypos + 0x100000;
        } else {
            x0 = gob->gob_xpos - 0x100000;
            x1 = gob->gob_xpos + 0x100000;
            y0 = gob->gob_ypos - 0x180000;
            y1 = gob->gob_ypos + 0x180000;
        }
        y0 = INT_ARRAY_00456f40[gob->gob_size] + y0 - 0x200000;
        y1 = INT_ARRAY_00456f40[gob->gob_size] + y1 - 0x200000;
        i = 0;
        x = x0;
        while (1) {
            if (x >= edges.left && x <= edges.right) {
                if (y0 >= edges.top && y0 <= edges.bottom)
                    DAT_004a286c[i] = 1;
                if (y1 >= edges.top && y1 <= edges.bottom)
                    DAT_004a2820[i] = 1;
            }
            if (x == x1)
                break;
            i++;
            x += 0x100000;
            if (x > x1)
                x = x1;
        }
        j = 0;
        while (1) {
            if (y0 >= edges.top && y0 <= edges.bottom) {
                if (x0 >= edges.left && x0 <= edges.right)
                    DAT_004a2848[j] = 1;
                if (x1 >= edges.left && x1 <= edges.right)
                    DAT_004a2868[j] = 1;
            }
            if (y0 == y1)
                break;
            j++;
            y0 += 0x100000;
            if (y0 > y1)
                y0 = y1;
        }
    }
}
}
