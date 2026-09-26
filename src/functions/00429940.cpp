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
void *__cdecl memset(void *dst, int value, unsigned int count);
extern int M1_IsInMap_004a2a7c;
extern int gGameState_00455c3c;
extern unsigned char gRemotesGained_004a2420[0x90];
extern unsigned char BYTE_ARRAY_004a25d0[0x90];
extern unsigned char BYTE_ARRAY_004a2540[0x90];
extern char gPasswordEnter_004a0200[];
extern int gShowMapTutorials_004a0210;
extern int level_004a2964;
extern int LEVELID_004a2a74;
extern int DAT_00458c8c;
extern GXInputRecord gInputControllers_004a0280[];
int __cdecl VFX_Play_0041fa80(int voice);
void __cdecl FUN_0040b9f0_Unk(void);
void __cdecl CollectibleReset_0041a660(void);
int __cdecl FUN_00429390_EnterPasswordSelectLevel(char *password);
void __cdecl GEX_Target(void)
{
    VFX_Play_0041fa80(1);
    M1_IsInMap_004a2a7c = 1;
    FUN_0040b9f0_Unk();
    gGameState_00455c3c = 2;
    memset(gRemotesGained_004a2420, 0, sizeof(gRemotesGained_004a2420));
    memset(BYTE_ARRAY_004a25d0, 0, sizeof(BYTE_ARRAY_004a25d0));
    memset(BYTE_ARRAY_004a2540, 0, sizeof(BYTE_ARRAY_004a2540));
    CollectibleReset_0041a660();
    if (!FUN_00429390_EnterPasswordSelectLevel(gPasswordEnter_004a0200)) {
        BYTE_ARRAY_004a2540[49] = 1;
        BYTE_ARRAY_004a2540[3] = 1;
        BYTE_ARRAY_004a2540[62] = 1;
        gShowMapTutorials_004a0210 = 1;
        level_004a2964 = 0x37;
        LEVELID_004a2a74 = 0x31;
        DAT_00458c8c = 0;
    } else {
        gShowMapTutorials_004a0210 = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonRight = 0;
    }
    BYTE_ARRAY_004a2540[55] = 1;
}
}
