// Field names from Ghidra's GXObject/GXInputRecord layouts (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x14];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x28];
    int gob_work0;              /* 0x98 */
} GXObject;
typedef struct GexTileStruct GexTileStruct;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;
    BUTTON_RECORD gxir_padJustOnButtons;
    unsigned char _pad1e[2];
    int gxir_dValue;
} GXInputRecord;
extern "C" {
extern GXInputRecord gInputControllers_004a0280[];
extern GexTileStruct *M1_CurrentLevel_004a2990;
extern int DAT_00463abc_CollideAndStickWithWall;
void __cdecl InitPlayerRun_00424aa0(GXObject *gex);
int __cdecl FUN_00424980_CheckGexInputs(GXObject *gex);
void __cdecl InitPlayerRunSkidding_00426f60(GXObject *gex);
void __cdecl FUN_004213f0_GexMovementLeftandRight(GXObject *gex);
void __cdecl FUN_004213c0(GexTileStruct *level, GXObject *gex);
int __cdecl FUN_00421560_DrawCharacter(GexTileStruct *level, GXObject *gex);
void __cdecl InitPlayerFalling_004252b0(GXObject *gex);
void __cdecl FUN_00421cc0_Set_Stop_to_1(void);
void __cdecl TILES_CheckOneXPoint_0042cec0(GexTileStruct *level, GXObject *gex, void (__cdecl *hit)(void), int offset);
void __cdecl InitPlayerStand_00424090(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    unsigned int facingLeft;
    facingLeft = gex->gob_flags & 0x80000000;
    if ((facingLeft && gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
        || (!facingLeft && gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)) {
        InitPlayerRun_00424aa0(gex);
        return;
    }
    if (FUN_00424980_CheckGexInputs(gex))
        return;
    if (++gex->gob_work0 >= 2) {
        gex->gob_work0 = 0;
        if (++gex->gob_currentFrameIndex == 2) {
            InitPlayerRunSkidding_00426f60(gex);
            return;
        }
    }
    FUN_004213f0_GexMovementLeftandRight(gex);
    FUN_004213c0(M1_CurrentLevel_004a2990, gex);
    if (!FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, gex)) {
        InitPlayerFalling_004252b0(gex);
        return;
    }
    DAT_00463abc_CollideAndStickWithWall = 0;
    TILES_CheckOneXPoint_0042cec0(M1_CurrentLevel_004a2990, gex, FUN_00421cc0_Set_Stop_to_1, -0x180000);
    if (DAT_00463abc_CollideAndStickWithWall)
        InitPlayerStand_00424090(gex);
}
}
