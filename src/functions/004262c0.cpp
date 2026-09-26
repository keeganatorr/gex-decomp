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
extern int DAT_0045a6d4;
extern void __cdecl GOB_ResetState_00420bc0(GXObject *);
extern void __cdecl GOB_KeepOutOfTiles_00420960(GXObject *);
extern void __cdecl PlayerRunFall_00426180(GXObject *);
void __cdecl GEX_Target(GXObject *gob)
{
    GOB_ResetState_00420bc0(gob);
    gob->gob_state = 0xf;
    gob->gob_currentFrameGroup = 0x28;
    gob->gob_currentFrameIndex = 3;
    gob->gob_maxxVel = DAT_0045a6d4;
    gob->gob_yAccl = 0x14000;
    gob->gob_work0 = 1;
    gob->gob_yAccl = 0x14000;
    gob->gob_maxyVel = 0xe0000;
    GOB_KeepOutOfTiles_00420960(gob);
    PlayerRunFall_00426180(gob);
}
}
