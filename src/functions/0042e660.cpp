typedef struct GXObject GXObject;
typedef struct AngleBox {
    int unk0[6];
    int left;    /* 0x18 */
    int right;   /* 0x1c */
    int top;     /* 0x20 */
    int bottom;  /* 0x24 */
} AngleBox;
typedef struct AngleBoxPair {
    int unk0;
    int unk4;
    AngleBox first;   /* 0x8 */
    AngleBox second;  /* 0x30 */
} AngleBoxPair;
extern "C" {
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, AngleBox *box);
void __cdecl FUN_0042e5e0(GXObject *gob, int x, int y);
void __cdecl GEX_Target(GXObject *gob, AngleBoxPair *pair)
{
    AngleBox box;
    int x1;
    int y1;
    int x2;
    int y2;
    int swap;
    if (!pair) {
        if (CLD_ComputeAngleEdges_0041cb80(gob, &box))
            FUN_0042e5e0(gob, ((box.right - box.left) >> 1) + box.left, ((box.bottom - box.top) >> 1) + box.top);
    } else {
        x1 = ((pair->first.right - pair->first.left) >> 1) + pair->first.left;
        y1 = ((pair->first.bottom - pair->first.top) >> 1) + pair->first.top;
        x2 = ((pair->second.right - pair->second.left) >> 1) + pair->second.left;
        y2 = ((pair->second.bottom - pair->second.top) >> 1) + pair->second.top;
        if (x2 < x1) {
            swap = x1;
            x1 = x2;
            x2 = swap;
        }
        if (y2 < y1) {
            swap = y1;
            y1 = y2;
            y2 = swap;
        }
        FUN_0042e5e0(gob, ((x2 - x1) >> 1) + x1, ((y2 - y1) >> 1) + y1);
    }
}
}
