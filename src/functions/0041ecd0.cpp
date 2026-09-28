typedef struct LevelEntry {
    unsigned short info;
    unsigned char f2;
    unsigned char f3;
    unsigned char music;
    unsigned char next;
    unsigned char speech;
    unsigned char idle;
} LevelEntry;
typedef struct LevelRequest {
    int file;
    int blocks;
    int base;
} LevelRequest;
extern "C" {
extern int M1_StreamingState_00463844;
extern int M1_DidLastLoadSucceed_00463840;
extern int *DAT_004638a8_LevelData;
extern int *DAT_004638ac_levelPointer;
extern char *DAT_004a02d8;
extern char DAT_00459824[];
extern char s_Loading_SFX_Samples_00459844[];
extern char s_waiting_for_sound_to_load_00459828[];
extern char s_waiting_for_tiles_to_load_00459808[];
extern char s_waiting_for_preloaded_to_load_004597e8[];
extern char s_waiting_for_level_to_load_004597cc[];
extern char s_waiting_for_music_to_load_004597b0[];
extern char String_Waiting_For_Speech_To_Load[];
extern char String_Waiting_For_GX_To_Load[];
extern char String_Waiting_For_GX_Idle_To_Load[];
extern char String_Finished_Loading[];
extern int M1_StreamedLevel_004638a4;
extern int gSFXEnabled_00455c08;
extern int gVFXEnabled_00455c0c;
extern int gMUSEnabled_00455c10;
extern int DAT_004a291c_LoadLevelUnk1;
extern int DAT_004a2918_LevelObjectsListEnd;
extern int DAT_004a2920_LoadLevelUnk5;
extern int M1_IsLoadingMapLevel_004a296c;
extern int DAT_004a2a08_LoadLevelMusic4;
extern int LEVELID_004a2a74;
extern LevelEntry DAT_004577B0[];
extern int DAT_00459670[];
extern int DAT_00459648[];
extern int M1_MusicTrack_004a2a14;
extern int M1_NextMusicTrack_004a2a88;
extern int gDemoQueued_004a2ac4;
extern int gDemoShowing_004a2a0c;
extern int M1_PlaybackRecordingInfo_004a2968;
extern void *PTR_DAT_00459640_OpenFile;
extern int DAT_00455c34_LEV_Variable;
extern char *PTR_gIDLDirectory_00455998;
extern char *DAT_00459698[];
extern int DAT_004596a8[];
extern int DAT_004596b8[];
extern int DAT_004a02dc_Lev_Loading_Unk;
extern int DAT_004a02e0_SpeechRelated;
extern int DAT_004596e0[];
extern int DAT_004596f0[];
extern int DAT_004a2980;
int __cdecl UTL_ReallyRandom_00428c80(int range);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
void __cdecl TracePrintf_Debug_00405390(char *fmt, ...);
int __cdecl M1_OpenLevelFile_0041ec70(int file, int part, int **data, int **pointer);
void __cdecl SND_LoadSounds_00401df0(int data, int pointer);
void __cdecl RM_LoadTextures_004405b0(int data, int pointer);
void __cdecl GOB_LoadTextures_00440e70(int data, int pointer);
void __cdecl BLOC_LoadBlocks_0040b8c0(int file, int part, int *base, int *blocks);
void __cdecl MUS_QueuePlay_00402e70(int track);
int __cdecl FUN_00402eb0_Return1(void);
void __cdecl ASYNC_LoadFileToMem_00437e90(char *dir, char *name, void *file, int buffer, int size);
void __cdecl VSIT_ForceVoiceSituation_0041fb80(int situation);
void __cdecl VFX_Update_0041faf0(void);
int __cdecl ASYNC_DoneLoading_00437f10(void *file);
int __cdecl VSIT_ForcedVoiceSituationReady_0041fba0(void);
void __cdecl LoadGex_00409880(void);
int __cdecl GX_Resolve_004098d0(void);
void __cdecl IDL_SetIdle_0041fdb0(int idle);
int __cdecl IDL_Resolve_0041fd00(void);

int __cdecl GEX_Target(LevelRequest *request)
{
    int result;
    int data;
    int pointer;
    int track;
    int ready;

    result = 0;
    UTL_ReallyRandom_00428c80(2);
    UTL_ReallyRandom32_00428c60();
    switch (M1_StreamingState_00463844) {
    case 0:
        TracePrintf_Debug_00405390(s_Loading_SFX_Samples_00459844);
        M1_DidLastLoadSucceed_00463840 = M1_OpenLevelFile_0041ec70(request->file, 1, &DAT_004638a8_LevelData, &DAT_004638ac_levelPointer);
        M1_StreamingState_00463844++;
        break;
    case 1:
        DAT_004a02d8 = s_waiting_for_sound_to_load_00459828;
        TracePrintf_Debug_00405390(DAT_00459824, s_waiting_for_sound_to_load_00459828);
        if (M1_DidLastLoadSucceed_00463840) {
            if (!DAT_004638ac_levelPointer)
                break;
            M1_DidLastLoadSucceed_00463840 = 0;
            data = *DAT_004638a8_LevelData;
            pointer = *DAT_004638ac_levelPointer;
            M1_DidLastLoadSucceed_00463840 = M1_OpenLevelFile_0041ec70(request->file, 2, &DAT_004638a8_LevelData, &DAT_004638ac_levelPointer);
            SND_LoadSounds_00401df0(data, pointer);
            M1_StreamingState_00463844++;
            break;
        }
        M1_DidLastLoadSucceed_00463840 = M1_OpenLevelFile_0041ec70(request->file, 2, &DAT_004638a8_LevelData, &DAT_004638ac_levelPointer);
        M1_StreamingState_00463844++;
        break;
    case 2:
        DAT_004a02d8 = s_waiting_for_tiles_to_load_00459808;
        TracePrintf_Debug_00405390(DAT_00459824, s_waiting_for_tiles_to_load_00459808);
        if (M1_DidLastLoadSucceed_00463840) {
            if (!DAT_004638ac_levelPointer)
                break;
            M1_DidLastLoadSucceed_00463840 = 0;
            data = *DAT_004638a8_LevelData;
            pointer = *DAT_004638ac_levelPointer;
            M1_DidLastLoadSucceed_00463840 = M1_OpenLevelFile_0041ec70(request->file, 3, &DAT_004638a8_LevelData, &DAT_004638ac_levelPointer);
            RM_LoadTextures_004405b0(data, pointer);
            M1_StreamingState_00463844++;
            break;
        }
        M1_DidLastLoadSucceed_00463840 = M1_OpenLevelFile_0041ec70(request->file, 3, &DAT_004638a8_LevelData, &DAT_004638ac_levelPointer);
        M1_StreamingState_00463844++;
        break;
    case 3:
        DAT_004a02d8 = s_waiting_for_preloaded_to_load_004597e8;
        if (M1_DidLastLoadSucceed_00463840) {
            if (!DAT_004638ac_levelPointer)
                break;
            M1_DidLastLoadSucceed_00463840 = 0;
            data = *DAT_004638a8_LevelData;
            pointer = *DAT_004638ac_levelPointer;
            GOB_LoadTextures_00440e70(data, pointer);
            BLOC_LoadBlocks_0040b8c0(request->file, 4, &request->base, &request->blocks);
            M1_StreamingState_00463844++;
            break;
        }
        BLOC_LoadBlocks_0040b8c0(request->file, 4, &request->base, &request->blocks);
        M1_StreamingState_00463844++;
        break;
    case 4:
        DAT_004a02d8 = s_waiting_for_level_to_load_004597cc;
        if (!request->blocks)
            break;
        if (M1_StreamedLevel_004638a4 == 0x3f) {
            DAT_004a291c_LoadLevelUnk1 = gSFXEnabled_00455c08;
            gSFXEnabled_00455c08 = 1;
            DAT_004a2918_LevelObjectsListEnd = gVFXEnabled_00455c0c;
            gVFXEnabled_00455c0c = 1;
            DAT_004a2920_LoadLevelUnk5 = gMUSEnabled_00455c10;
            gMUSEnabled_00455c10 = 1;
        }
        if (!M1_IsLoadingMapLevel_004a296c && !DAT_004a2a08_LoadLevelMusic4) {
            switch (M1_StreamedLevel_004638a4) {
            case 0x42:
                track = DAT_00459670[DAT_004577B0[LEVELID_004a2a74].info & 0xf];
                break;
            case 0x44:
                track = DAT_00459648[DAT_004577B0[LEVELID_004a2a74].info & 0xf];
                break;
            default:
                track = DAT_004577B0[M1_StreamedLevel_004638a4].music;
                break;
            }
            if (track) {
                M1_MusicTrack_004a2a14 = track;
                MUS_QueuePlay_00402e70(track);
                M1_NextMusicTrack_004a2a88 = DAT_004577B0[M1_StreamedLevel_004638a4].next;
            }
        }
        M1_StreamingState_00463844++;
        break;
    case 5:
        DAT_004a02d8 = s_waiting_for_music_to_load_004597b0;
        if (M1_MusicTrack_004a2a14 && !FUN_00402eb0_Return1())
            break;
        if (!M1_IsLoadingMapLevel_004a296c) {
            if (gDemoQueued_004a2ac4) {
                ASYNC_LoadFileToMem_00437e90(PTR_gIDLDirectory_00455998, DAT_00459698[DAT_00455c34_LEV_Variable], PTR_DAT_00459640_OpenFile, M1_PlaybackRecordingInfo_004a2968, 0x3800);
                gDemoQueued_004a2ac4 = 0;
                gDemoShowing_004a2a0c = 1;
            } else {
                if (M1_StreamedLevel_004638a4 == 0x44) {
                    if (DAT_004577B0[M1_StreamedLevel_004638a4].info & 0x200) {
                        DAT_004a02dc_Lev_Loading_Unk = UTL_ReallyRandom_00428c80(3);
                        DAT_004a02e0_SpeechRelated = DAT_004596a8[DAT_004a02dc_Lev_Loading_Unk];
                    } else
                        DAT_004a02e0_SpeechRelated = DAT_004596b8[DAT_004577B0[LEVELID_004a2a74].info & 0xf];
                } else
                    DAT_004a02e0_SpeechRelated = DAT_004577B0[M1_StreamedLevel_004638a4].speech;
                if (DAT_004a02e0_SpeechRelated) {
                    VSIT_ForceVoiceSituation_0041fb80(DAT_004a02e0_SpeechRelated);
                    VFX_Update_0041faf0();
                }
            }
        }
        M1_StreamingState_00463844++;
        break;
    case 6:
        DAT_004a02d8 = String_Waiting_For_Speech_To_Load;
        if (gDemoShowing_004a2a0c)
            ready = ASYNC_DoneLoading_00437f10(PTR_DAT_00459640_OpenFile);
        else if (DAT_004a02e0_SpeechRelated) {
            VFX_Update_0041faf0();
            ready = VSIT_ForcedVoiceSituationReady_0041fba0();
        } else
            ready = 1;
        if (!ready)
            break;
        DAT_004a02e0_SpeechRelated = 0;
        if (DAT_004577B0[M1_StreamedLevel_004638a4].info & 0x10)
            LoadGex_00409880();
        M1_StreamingState_00463844++;
        break;
    case 7:
        DAT_004a02d8 = String_Waiting_For_GX_To_Load;
        if (!GX_Resolve_004098d0())
            break;
        if (!M1_IsLoadingMapLevel_004a296c) {
            if (M1_StreamedLevel_004638a4 == 0x44) {
                if (DAT_004577B0[M1_StreamedLevel_004638a4].info & 0x200)
                    track = DAT_004596e0[DAT_004a02dc_Lev_Loading_Unk];
                else
                    track = DAT_004596f0[DAT_004577B0[LEVELID_004a2a74].info & 0xf];
            } else
                track = DAT_004577B0[M1_StreamedLevel_004638a4].idle;
            if (DAT_004a2980 || track)
                IDL_SetIdle_0041fdb0(DAT_004a2980 ? DAT_004a2980 : track);
        }
        M1_StreamingState_00463844++;
        break;
    case 8:
        DAT_004a02d8 = String_Waiting_For_GX_Idle_To_Load;
        TracePrintf_Debug_00405390(DAT_00459824, String_Waiting_For_GX_Idle_To_Load);
        if (!IDL_Resolve_0041fd00())
            break;
        M1_StreamingState_00463844++;
        break;
    case 9:
        DAT_004a02d8 = String_Finished_Loading;
        TracePrintf_Debug_00405390(DAT_00459824, String_Finished_Loading);
        result = 1;
        DAT_004577B0[0x44].info &= ~0x200;
        break;
    }
    return result;
}
}
