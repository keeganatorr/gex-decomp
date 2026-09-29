// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0xa8];
    int gob_work4;  /* 0xa8 */
    unsigned char _pad1[0x4];
    int gob_work6;  /* 0xb0 */
} GXObject;
typedef struct Slot { int a, b, c, d; } Slot;
extern "C" {
extern Slot DAT_00456168[];
void __cdecl FUN_0040cca0(GXObject *gob)
{
    int old = gob->gob_work6;
    if (gob->gob_work4 == 0x10)
        gob->gob_work6 = 1;
    else if (gob->gob_work4 == 0xe)
        gob->gob_work6 = 2;
    else if (gob->gob_work4 == 0xc)
        gob->gob_work6 = 3;
    else if (gob->gob_work4 == 0x70)
        gob->gob_work6 = 4;
    else {
        gob->gob_work6 = 5;
        if (gob->gob_work4 != 0x12)
            gob->gob_work6 = 0;
    }
    if (old != gob->gob_work6)
        DAT_00456168[gob->gob_work6].a = 0;
}
}
