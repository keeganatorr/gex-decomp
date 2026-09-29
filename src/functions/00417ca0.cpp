// Field names from Ghidra's GXObject/GXInputRecord layouts (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0xb8];
    int gob_flashTime;  /* 0xb8 */
} GXObject;
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
extern GXObject *gPlayerObject_004a27fc;
extern int gHitpoints_004a281c;
extern int DAT_004a2878_CollisionType;
extern int DAT_004a2840;
extern int gNoProcess_00455c4c;
extern int DAT_004a2850;
extern int DAT_00455b8c_CamX2;
extern GXInputRecord gInputControllers_004a0280[];
extern int gIsMapLevel_004a2ac0;
extern int DAT_004a0218_pState;
extern int DAT_004594a0_EatenObject_unk;
extern int DAT_004594a4_HealthUnk;
extern int DAT_004594a8_HealthDrawUnk;
extern int DAT_0045a6e0_GexPowerUpHealth;
extern int gCheatPowerupToSpawn_00459498;
extern int DAT_00455c1c_PlanetXLevelSelect;
extern int DAT_00455c24_LivesUnk;
extern int gNumLives_00456b00;
extern int DAT_00462e38;
int __cdecl FUN_004206b0(int situation);
void __cdecl FUN_00422390_Reset_Powerups(GXObject *gex);
void __cdecl CollectibleReset_0041a660(void);
void __cdecl PlayerKill_00417ca0(void)
{
    if (gPlayerObject_004a27fc && gHitpoints_004a281c) {
        DAT_004a2878_CollisionType = 0x14;
        if (!DAT_004a2840) {
            DAT_004a2840++;
            gNoProcess_00455c4c++;
        }
        gPlayerObject_004a27fc->gob_flashTime = 0x5a;
        DAT_004a2850 = 0;
        if (DAT_00455b8c_CamX2) {
            gInputControllers_004a0280[0].gxir_padButtons.buttonRight = 0;
            gInputControllers_004a0280[0].gxir_padButtons.buttonLeft = 0;
        }
        if (!gIsMapLevel_004a2ac0) {
            if (!FUN_004206b0(0x55))
                DAT_004a0218_pState = 0x76;
            gHitpoints_004a281c = 0;
            FUN_00422390_Reset_Powerups(gPlayerObject_004a27fc);
            DAT_004594a0_EatenObject_unk = -1;
            DAT_004594a4_HealthUnk = -1;
            DAT_004594a8_HealthDrawUnk = -1;
            DAT_0045a6e0_GexPowerUpHealth = -1;
            gCheatPowerupToSpawn_00459498 = -1;
            CollectibleReset_0041a660();
            if (!DAT_00455c1c_PlanetXLevelSelect && !DAT_00455c24_LivesUnk)
                gNumLives_00456b00--;
        } else
            DAT_00462e38 = 1;
    }
}
}
