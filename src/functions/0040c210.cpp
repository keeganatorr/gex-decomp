// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x40];
    int gob_work0;              /* 0x98 */
    unsigned char _pad2[0x10];
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
} GXObject;
extern "C" {
extern int M1_IsInMap_004a2a7c;
extern int M1_004a2994;
extern int DAT_004a291c_LoadLevelUnk1;
extern int DAT_004a2920_LoadLevelUnk5;
extern int DAT_004a2918_LevelObjectsListEnd;
extern int level_004a2964;
extern void __cdecl FUN_0040c2c0_GameFunkUnk(GXObject *);
void __cdecl MainMenuButtonInit_0040c210(GXObject *gob)
{
    M1_IsInMap_004a2a7c = 1;
    M1_004a2994 = 0;
    switch (gob->gob_work5) {
    case 1:
        if (gob->gob_work0 == 2) {
            if (DAT_004a291c_LoadLevelUnk1)
                gob->gob_work6 = 1;
            else
                gob->gob_work6 = 0;
        } else if (gob->gob_work0 == 4) {
            if (DAT_004a2920_LoadLevelUnk5)
                gob->gob_work6 = 1;
            else
                gob->gob_work6 = 0;
        } else if (gob->gob_work0 == 6) {
            if (DAT_004a2918_LevelObjectsListEnd)
                gob->gob_work6 = 1;
            else
                gob->gob_work6 = 0;
        } else
            gob->gob_work6 = 1;
        break;
    case 2:
        gob->gob_work6 = 0;
        break;
    default:
        gob->gob_work6 = 0;
    }
    if (level_004a2964 == 0x41 && (gob->gob_work0 == 2 || gob->gob_work0 == 1))
        gob->gob_currentFrameIndex = 0;
    else
        gob->gob_currentFrameIndex = -1;
    if (gob->gob_work5 == 3)
        FUN_0040c2c0_GameFunkUnk(gob);
}
}
