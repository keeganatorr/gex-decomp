// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;              /* 0x6c */
    unsigned char _pad1[0x28];
    int gob_work0;                       /* 0x98 */
    unsigned char _pad2[0x4];
    int gob_work2;                       /* 0xa0 */
    unsigned char _pad3[0xd0];
    unsigned int *gob_phaClidWith;       /* 0x174 */
    struct GXObject *gob_pgobClidWith;   /* 0x178 */
} GXObject;
extern "C" {
extern int DAT_0045b130;
extern void __cdecl FUN_0042f5f0(GXObject *, int);
extern void __cdecl RezOutObject_00437310(GXObject *);
void __cdecl ob234Clid_00431640(GXObject *gob, int *hit)
{
    int i;
    unsigned int kind, collision;
    if (*hit && gob->gob_work0 == 0x80) {
        kind = *gob->gob_phaClidWith & 0xffff;
        collision = (gob->gob_pgobClidWith->gob_flags >> 8) & 0xf;
        if (collision == 2 && kind == 1 && gob->gob_work0 == 0x80 && gob->gob_work2 < 0) {
        DAT_0045b130 = 1;
        i = 20;
        do {
            FUN_0042f5f0(gob, 0);
        } while (--i);
        RezOutObject_00437310(gob);
        gob->gob_work2 = 20;
        }
    }
}
}
