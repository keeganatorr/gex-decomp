// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x18];
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x24];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    unsigned char _padA0[8];
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
} GXObject;
extern "C" {
extern int gStartDoorType_00456ae0;
extern int DAT_004a0260;
extern int DAT_00455bfc;
extern int DAT_00455c00;
extern int DAT_00455be4;
extern int DAT_00455BF4;
extern int DAT_00455BF8;
extern int DAT_00455BF0;
extern int DAT_004a2948;
extern int DAT_004a280c_xPos;
extern int DAT_004a2810_yPos;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern char s_Bad_Start_Door_Type_ld_00458c04[];
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl SND_PlayObSound_0041a250(GXObject *gob, int id, int volume, int pan);
void __cdecl FUN_004153e0_Falling_unk(GXObject *gex);
void __cdecl GFX_Fade_0043f490(int steps, int r0, int r1, int g0, int g1, int b0, int b1);
void __cdecl InitPlayerStartFromCamera_004155c0(GXObject *gex);
void __cdecl FUN_00415480_First_pState(GXObject *gex)
{
    GOB_ResetState_00420bc0(gex);
    switch (gStartDoorType_00456ae0) {
    case 0:
        DAT_004a0260 = 0;
        gex->gob_state = 1;
        gex->gob_currentFrameIndex = 0;
        gex->gob_work1 = 0;
        gex->gob_currentFrameGroup = 0x30;
        gex->gob_work0 = 0xd;
        DAT_00455bfc = 0;
        DAT_00455c00 = 0;
        gex->gob_work4 = 0;
        gex->gob_work5 = DAT_00455c00 / -13;
        DAT_00455be4 = 1;
        DAT_00455BF4 = DAT_004a280c_xPos - CAMERA_XPos_004a2a38;
        DAT_00455BF8 = DAT_004a2810_yPos - CAMERA_YPos_004a2a1c;
        DAT_00455BF0 = 0;
        DAT_004a2948 = 1;
        SND_PlayObSound_0041a250(gex, 0x89, 0x80, 0x60);
        FUN_004153e0_Falling_unk(gex);
        GFX_Fade_0043f490(7, 0, 0xff, 0, 0xff, 0, 0xff);
        break;
    case 1:
        DAT_004a0260 = 0;
        InitPlayerStartFromCamera_004155c0(gex);
        break;
    default:
        TracePrintf_Debug_00405390(s_Bad_Start_Door_Type_ld_00458c04, gStartDoorType_00456ae0);
        break;
    }
    gStartDoorType_00456ae0 = -1;
}
}
