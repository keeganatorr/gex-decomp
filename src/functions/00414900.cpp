typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x98 - 0x58];
    int gob_work0;              /* 0x98 */
} GXObject;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;        /* 0x0 */
    BUTTON_RECORD gxir_padJustOnButtons;  /* 0xf */
    unsigned char _pad1e[2];
    int gxir_dValue;                      /* 0x20 */
} GXInputRecord;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern GXObject *gEatingObject_004a2888;
extern GXInputRecord gInputControllers_004a0280[];
int __cdecl FUN_00421820_pStateUnk_Duck(GXObject *gex);
int __cdecl FUN_00421560_DrawCharacter(void *level, GXObject *gex);
void __cdecl FUN_00423120_Lash_unk(GXObject *gex);
void __cdecl InitPlayerDuckSwallow_00414b60(GXObject *gex);
void __cdecl InitPlayerFall_004250b0(GXObject *gex);
void __cdecl InitPlayerStandJumpStart_00424b80(GXObject *gex);
void __cdecl InitPlayerDuckSpin_00414c90(GXObject *gex);
void __cdecl InitPlayerDuck_00427850(GXObject *gex);
void __cdecl FUN_00422790_pStateUnk_Lash(GXObject *gex);
void __cdecl FUN_004213f0_GexMovementLeftandRight(GXObject *gex);
void __cdecl FUN_004213c0(void *level, GXObject *gex);
void __cdecl FUN_00423130_pStateUnk_Eating(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    int ducked;
    ducked = FUN_00421820_pStateUnk_Duck(gex);
    if (!FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, gex)) {
        FUN_00423120_Lash_unk(gex);
        if (gEatingObject_004a2888)
            InitPlayerDuckSwallow_00414b60(gex);
        else
            InitPlayerFall_004250b0(gex);
        return;
    }
    if ((!ducked && gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB || gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC) && !gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonA) {
        FUN_00423120_Lash_unk(gex);
        if (gEatingObject_004a2888)
            InitPlayerDuckSwallow_00414b60(gex);
        else if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB)
            InitPlayerStandJumpStart_00424b80(gex);
        else
            InitPlayerDuckSpin_00414c90(gex);
        return;
    }
    if (++gex->gob_work0 >= 1) {
        gex->gob_work0 = 0;
        if (++gex->gob_currentFrameIndex > 7) {
            FUN_00423120_Lash_unk(gex);
            if (gEatingObject_004a2888)
                InitPlayerDuckSwallow_00414b60(gex);
            else
                InitPlayerDuck_00427850(gex);
            return;
        }
        FUN_00422790_pStateUnk_Lash(gex);
    }
    FUN_004213f0_GexMovementLeftandRight(gex);
    FUN_004213c0(M1_CurrentLevel_004a2990, gex);
    FUN_00423130_pStateUnk_Eating(gex);
}
}
