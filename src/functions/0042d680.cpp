// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;          /* 0x7c */
    unsigned char _pad1[0x6c];
    int gob_topEdge;       /* 0xec */
    int gob_bottomEdge;    /* 0xf0 */
    unsigned char _pad2[0x94];
    int gob_checkYpos;     /* 0x188 */
} GXObject;
extern "C" {
extern void __cdecl FUN_0042cc70_Object_unk(int, GXObject *);
int __cdecl FUN_0042d680_ObjCallUnk(GXObject *gob)
{
    gob->gob_ypos += 0x200000 - (gob->gob_checkYpos & 0x1fffff);
    gob->gob_bottomEdge = (gob->gob_checkYpos & 0xffe00000) + 0x200000;
    if (gob->gob_topEdge)
        FUN_0042cc70_Object_unk(0, gob);
    return 1;
}
}
