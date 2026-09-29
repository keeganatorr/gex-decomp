// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0xac];
    int gob_work5;   /* 0xac */
    int gob_work6;   /* 0xb0 */
    unsigned char _pad1[0x2c];
    int gob_flags2;  /* 0xe0 */
} GXObject;
extern "C" {
extern int __cdecl rand(void);
void __cdecl ob231Init_00430de0(GXObject *gob)
{
    gob->gob_flags2 |= 0x40;
    gob->gob_work5 = rand() % 10;
    gob->gob_work6 = 3;
}
}
