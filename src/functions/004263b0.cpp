// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x14];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad2[0x4];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    int gob_xVel;               /* 0x80 */
    int gob_maxxVel;            /* 0x84 */
    int gob_xAccl;              /* 0x88 */
    int gob_yVel;               /* 0x8c */
    unsigned char _pad3[0x8];
    int gob_work0;              /* 0x98 */
    unsigned char _pad4[0x28];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern unsigned char gInputControllers_004a0280[];
extern int DAT_004a27f8;
extern void __cdecl GOB_ResetState_00420bc0(GXObject *);
extern void __cdecl GX_ResetRotAndScale_00423c80(GXObject *);
extern void __cdecl FUN_00421560_DrawCharacter(void *, GXObject *);
extern void __cdecl EFECT_AddPuff_0042e480(int, int, unsigned int, int, unsigned int);
extern void __cdecl PlayerRunStopFall_00426330(GXObject *);
void __cdecl InitPlayerRunStopFall_004263b0(GXObject *gob)
{
    GOB_ResetState_00420bc0(gob);
    gob->gob_state = 0x2c;
    gob->gob_currentFrameGroup = 0x28;
    gob->gob_currentFrameIndex = 5;
    gob->gob_maxxVel = 0x90000;
    gob->gob_yVel = 0;
    gob->gob_work0 = 3;
    GX_ResetRotAndScale_00423c80(gob);
    if (!gInputControllers_004a0280[0] && !gInputControllers_004a0280[1]) {
        gob->gob_xVel = 0;
        gob->gob_xAccl = 0;
    }
    DAT_004a27f8 = 1;
    FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, gob);
    EFECT_AddPuff_0042e480(gob->gob_xpos + 0xa0000, gob->gob_ypos, gob->gob_flags & 0x80000000, gob->gob_angle, gob->gob_flags & 0xf);
    EFECT_AddPuff_0042e480(gob->gob_xpos - 0xa0000, gob->gob_ypos, gob->gob_flags & 0x80000000, gob->gob_angle, gob->gob_flags & 0xf);
    PlayerRunStopFall_00426330(gob);
}
}
