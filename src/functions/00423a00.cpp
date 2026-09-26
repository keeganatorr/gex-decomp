// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0xc4];
    int gob_angle;  /* 0xc4 */
} GXObject;
extern "C" {
extern unsigned char DAT_004a2820[];
extern void __cdecl FUN_00423780_pStateUnk(GXObject *);
int __cdecl GEX_Target(GXObject *gob)
{
    int count, i;
    FUN_00423780_pStateUnk(gob);
    count = ((gob->gob_angle + 0x200000) & 0x400000) ? 4 : 3;
    for (i = 0; i < count; i++)
        if (!DAT_004a2820[i])
            return 0;
    return 1;
}
}
