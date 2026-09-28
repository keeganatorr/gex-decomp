extern "C" {
extern int M1_004a2a80;
extern void *M1_CurrentLevel_004a2990;
extern int gNoVFX_004a2958;
extern int gStartDoorID_00456adc;
extern int DAT_00455C40;
extern int level_004a2964;
extern int DAT_004A2A0C;
extern int M1_IsInMap_004a2a7c;
extern int DAT_00455c1c_PlanetXLevelSelect;
extern int gGameState_00455c3c;
extern int LEVELID_004a2a98;
extern int gIsMapLevel_004a2ac0;
extern char M1_IsLevelDone_004a2a8c;
extern int LEVELID_004a2944;
extern int DAT_004a2a18_doorID_unk;
extern int DAT_004a2aa0;
typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
extern LevelEntry DAT_004577B0[];
extern int FUN_004A28A0[];
extern char s_Exit_Level_00455e50[];
extern char s_Max_Cels_00455e38[];
extern int DAT_00455c5c_Cells;
extern int DAT_00455c58_Cells;
extern int DAT_004626FC;
extern void **DAT_004A2A78;
extern int LEVELID_004a2a74;
int __cdecl FUN_0041fa10_ProcessVoiceLoadingCompletion_Clean1(void);
int __cdecl VFX_VoiceFinished_0041fb50(void);
void __cdecl VFX_Reset_0041f840(void);
void __cdecl VSIT_UnforceVoiceSituation_0041fbc0(void);
int __cdecl IDL_Resolve_0041fd00(void);
void __cdecl IDL_Free_0041fd70(void);
void __cdecl FUN_0040f780_Input(int);
void __cdecl FUN_0040b9f0_Unk(void);
void __cdecl TracePrintf_Debug_00405390(char *, ...);
void __cdecl GOB_FreeAllObjects_00419aa0(void);
void __cdecl FreeMemory_00409740(void *);
void __cdecl FUN_004099b0_CloseMusic(int);
void __cdecl FUN_00440850_GameOver(void);
void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
void __cdecl PAL_WaitForFade_0043f580(void);
void __cdecl FUN_0043f080_ResetGraphics_Clean1(unsigned int);

void __cdecl GEX_Target(void *map)
{
    int i;
    M1_CurrentLevel_004a2990 = map;
    if (M1_004a2a80)
        return;
    if (!gNoVFX_004a2958) {
        if (gStartDoorID_00456adc <= 0 || level_004a2964 != DAT_00455C40) {
            while (!FUN_0041fa10_ProcessVoiceLoadingCompletion_Clean1())
                ;
            while (!VFX_VoiceFinished_0041fb50())
                ;
            VFX_Reset_0041f840();
            VSIT_UnforceVoiceSituation_0041fbc0();
            while (!IDL_Resolve_0041fd00())
                ;
            IDL_Free_0041fd70();
        }
        if (DAT_004A2A0C) {
            DAT_004A2A0C = 0;
            M1_IsInMap_004a2a7c = 1;
            FUN_0040f780_Input(0);
            FUN_0040b9f0_Unk();
            level_004a2964 = 0x3f;
            M1_IsInMap_004a2a7c = 1;
        }
        if ((gStartDoorID_00456adc <= 0 || level_004a2964 != DAT_00455C40) && DAT_00455c1c_PlanetXLevelSelect) {
            gGameState_00455c3c = 0;
            M1_IsInMap_004a2a7c = 1;
            DAT_00455C40 = 1000;
            level_004a2964 = LEVELID_004a2a98;
        }
        if (gIsMapLevel_004a2ac0) {
            if (!M1_IsLevelDone_004a2a8c) {
                level_004a2964 = LEVELID_004a2944;
                gStartDoorID_00456adc = DAT_004a2a18_doorID_unk;
            }
            gIsMapLevel_004a2ac0 = 0;
        } else if (DAT_004577B0[level_004a2964].info & 0x80) {
            gIsMapLevel_004a2ac0 = 1;
            LEVELID_004a2944 = LEVELID_004a2a98;
            DAT_004a2a18_doorID_unk = DAT_004a2aa0;
            FUN_004A28A0[level_004a2964 + 8] = 1;
        }
    }
    TracePrintf_Debug_00405390(s_Exit_Level_00455e50);
    TracePrintf_Debug_00405390(s_Max_Cels_00455e38, DAT_00455c58_Cells, DAT_00455c5c_Cells);
    GOB_FreeAllObjects_00419aa0();
    if (DAT_004626FC) {
        for (i = DAT_004626FC - 1; i >= 0; i--)
            FreeMemory_00409740(DAT_004A2A78[i]);
        FreeMemory_00409740(DAT_004A2A78);
    }
    if ((!gNoVFX_004a2958 && gStartDoorID_00456adc <= 0) || level_004a2964 != DAT_00455C40)
        FUN_004099b0_CloseMusic(0);
    switch (M1_IsInMap_004a2a7c) {
    default:
        FUN_00440850_GameOver();
        break;
    case 1:
        GFX_Fade_0043f490(10, 0, 0, 0, 0, 0, 0);
        PAL_WaitForFade_0043f580();
        break;
    case 3:
        break;
    }
    FUN_0043f080_ResetGraphics_Clean1(1);
    if (!gNoVFX_004a2958 && !(DAT_004577B0[LEVELID_004a2a98].info & 0x20))
        LEVELID_004a2a74 = LEVELID_004a2a98;
    if (M1_IsLevelDone_004a2a8c)
        M1_IsLevelDone_004a2a8c = 0;
}
}
