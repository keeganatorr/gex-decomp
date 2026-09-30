typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xPos;               /* 0x78 */
    int gob_yPos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    char *gob_name;             /* 0x9c */
    int gob_up;                 /* 0xa0 */
    int gob_down;               /* 0xa4 */
    unsigned char _pada8[0xb0 - 0xa8];
    int gob_workB0;             /* 0xb0 */
    int gob_workB4;             /* 0xb4 */
} GXObject;
extern "C" {
extern int M1_IsInMap_004a2a7c;
extern int DAT_00462c84;
extern int DAT_00455c34_LEV_Variable;
extern int DAT_0045acc4_ProcessedTitleScreenCheat;
extern char DAT_00456334;
extern char DAT_0045633c;
extern char gPasswordEnter_004a0200[];
extern int gTimer_004a2ac8;
extern int DAT_00462c78;
extern char *STRING_START_00487fe0;
extern char *STRING_PASSWORD_00487fd0;
extern char *STRING_EXIT_00487fec;
void *__cdecl memset(void *, int, unsigned int);
void __cdecl InitPlayer_00417ee0(void);
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int situation);
void __cdecl FUN_0040b950_VoiceInner(void);
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, int work0);
void __cdecl MainMenuControllerInit_0040dda0(GXObject *gex)
{
    GXObject *start;
    GXObject *password;
    GXObject *exit;
    M1_IsInMap_004a2a7c = 1;
    if (DAT_00455c34_LEV_Variable >= 4 &&
        DAT_00455c34_LEV_Variable <= 6) {
        // The next title update increments both fields before selecting a
        // recording. Values 4..6 carry the CLI choice through startup; turn
        // them back into the ordinary cursor before the recording is loaded.
        DAT_00455c34_LEV_Variable =
            (DAT_00455c34_LEV_Variable - 4 + 2) % 3;
        DAT_00462c84 = 0x384;
    } else {
        DAT_00462c84 = 0;
    }
    DAT_0045acc4_ProcessedTitleScreenCheat = 0;
    DAT_00456334 = 0;
    DAT_0045633c = 0;
    memset(gPasswordEnter_004a0200, 'A', 8);
    gPasswordEnter_004a0200[8] = 0;
    InitPlayer_00417ee0();
    gex->gob_xPos = 0xfff60000;
    gex->gob_yPos = 0x1e00000;
    gex->gob_workB4 = gTimer_004a2ac8;
    DAT_00462c78 = 0xa0000;
    gex->gob_workB0 = 0;
    VSIT_PlayVoiceSituation_0041f8c0(1);
    FUN_0040b950_VoiceInner();
    start = GOB_FindWithWork0_0040c110(0x7b, 1);
    start->gob_workB4 |= 1;
    start->gob_name = STRING_START_00487fe0;
    password = GOB_FindWithWork0_0040c110(0x7b, 2);
    password->gob_workB4 |= 1;
    password->gob_name = STRING_PASSWORD_00487fd0;
    exit = GOB_FindWithWork0_0040c110(0x7b, 3);
    exit->gob_workB4 |= 1;
    exit->gob_name = STRING_EXIT_00487fec;
    password->gob_work0 = 3;
    exit->gob_work0 = 2;
    start->gob_up = 2;
    start->gob_down = 3;
    password->gob_up = 1;
    password->gob_down = 2;
    exit->gob_up = 3;
    exit->gob_down = 1;
}
}
