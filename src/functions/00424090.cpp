// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x18];
    int gob_state;              /* 0x70 */
    unsigned char _pad2[0xc];
    int gob_xVel;               /* 0x80 */
    int gob_maxxVel;            /* 0x84 */
    int gob_xAccl;              /* 0x88 */
    int gob_yVel;               /* 0x8c */
    int gob_maxyVel;            /* 0x90 */
    int gob_yAccl;              /* 0x94 */
    int gob_work0;              /* 0x98 */
    unsigned char _pad3[0xc];
    int gob_work4;              /* 0xa8 */
} GXObject;
extern "C" {
extern int DAT_004a2980;
extern void __cdecl GOB_ResetState_00420bc0(GXObject *);
extern void __cdecl GX_ResetRotAndScale_00423c80(GXObject *);
extern void __cdecl PlayerStand_00423dc0(GXObject *);
void __cdecl GEX_Target(GXObject *gob)
{
    GOB_ResetState_00420bc0(gob);
    if (gob->gob_state == 0xb || DAT_004a2980)
        gob->gob_work4 = 100;
    else
        gob->gob_work4 = 0;
    gob->gob_currentFrameGroup = 0x29;
    gob->gob_state = 0;
    gob->gob_currentFrameIndex = 0;
    gob->gob_xVel = 0;
    gob->gob_yVel = 0;
    gob->gob_xAccl = 0;
    gob->gob_yAccl = 0;
    gob->gob_work0 = 3;
    GX_ResetRotAndScale_00423c80(gob);
    PlayerStand_00423dc0(gob);
}
}
