// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x98];
    int gob_work0;   /* 0x98 */
    unsigned char _pad1[0x8];
    int gob_work3;   /* 0xa4 */
} GXObject;
extern "C" {
int __cdecl FUN_0042a630_Gex_Frames(GXObject *gob)
{
    if (gob->gob_work3 > gob->gob_work0) {
        gob->gob_work0 += 0x40000;
        if (gob->gob_work3 <= gob->gob_work0) {
            gob->gob_work0 = gob->gob_work3;
            return 1;
        }
    } else if (gob->gob_work3 < gob->gob_work0) {
        gob->gob_work0 -= 0x40000;
        if (gob->gob_work3 >= gob->gob_work0) {
            gob->gob_work0 = gob->gob_work3;
            return 1;
        }
    } else
        return 1;
    return 0;
}
}
