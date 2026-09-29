// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x14];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad2[0x14];
    int gob_xAccl;              /* 0x88 */
    unsigned char _pad3[0xc];
    int gob_work0;              /* 0x98 */
} GXObject;
extern "C" {
extern void __cdecl GOB_ResetState_00420bc0(GXObject *);
extern void __cdecl PlayerRunTurn_004271f0(GXObject *);
void __cdecl InitPlayerRunTurn_00427340(GXObject *gob)
{
    GOB_ResetState_00420bc0(gob);
    gob->gob_currentFrameIndex = 0;
    gob->gob_work0 = 0;
    gob->gob_state = 7;
    gob->gob_currentFrameGroup = 0x3e;
    gob->gob_xAccl = (gob->gob_flags & 0x80000000) ? -0x28000 : 0x28000;
    PlayerRunTurn_004271f0(gob);
}
}
