// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x14];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad2[0x24];
    int gob_work0;              /* 0x98 */
    unsigned char _pad3[0x28];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern int DAT_004a0218_pState;
extern void __cdecl GOB_ResetState_00420bc0(GXObject *);
extern void __cdecl PlayerDuckSpinAround_00414ce0(GXObject *);
void __cdecl InitPlayerDuckSpinAround_00414e20(GXObject *gob)
{
    GOB_ResetState_00420bc0(gob);
    gob->gob_state = 0x22;
    gob->gob_work0 = 0;
    gob->gob_currentFrameGroup = 0x55;
    gob->gob_currentFrameIndex = 3;
    gob->gob_angle = (gob->gob_flags & 0x80000000) ? 0x400000 : 0xc00000;
    DAT_004a0218_pState = 0x67;
    PlayerDuckSpinAround_00414ce0(gob);
}
}
