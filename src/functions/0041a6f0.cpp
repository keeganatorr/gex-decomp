// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x20];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x18];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned char _padA4[0x10];
    int gob_work7;              /* 0xb4: door id */
} GXObject;
typedef struct GexTileStruct GexTileStruct;
extern "C" {
extern int gIsAddingObjectIntros_004a27d4;
extern int gStartDoorID_00456adc;
extern int DAT_0046359c;
extern int DAT_004a280c_xPos;
extern int DAT_004a2810_yPos;
extern int DAT_004a282c_startxPos;
extern int DAT_004a2830_startypos;
extern int gStartDoorType_00456ae0;
extern GexTileStruct *M1_CurrentLevel_004a2990;
extern int LEVELID_004a2a98;
extern unsigned char gStartDoorIDs_004a2710[];
extern int DAT_004a2a40_LoadObjects;
int __cdecl GetGlueDist_0040f1d0(GexTileStruct *level, GXObject *gob);
void __cdecl GOB_RemoveMapObject_00419840(GXObject *gob);
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int situation);
void __cdecl GEX_Target(GXObject *gob)
{
    int dist;
    if (gIsAddingObjectIntros_004a27d4) {
        DAT_0046359c = 0;
        if (gob->gob_work7 == gStartDoorID_00456adc) {
            DAT_004a280c_xPos = gob->gob_xpos;
            DAT_004a2810_yPos = gob->gob_ypos;
            gob->gob_ypos += 0x200000;
            DAT_004a282c_startxPos = gob->gob_xpos;
            DAT_004a2830_startypos = gob->gob_ypos;
            gStartDoorType_00456ae0 = 1;
            dist = GetGlueDist_0040f1d0(M1_CurrentLevel_004a2990, gob);
            if ((dist < 0 ? -dist : dist) < 0x5a0000)
                DAT_004a2830_startypos += dist;
        }
        GOB_RemoveMapObject_00419840(gob);
    } else if (gStartDoorIDs_004a2710[LEVELID_004a2a98] == gob->gob_work7) {
        if (DAT_004a282c_startxPos >= 0 && gStartDoorType_00456ae0 == 1 && DAT_004a2a40_LoadObjects) {
            gob->gob_work1 = 0;
            gob->gob_work2 = 0;
            gob->gob_currentFrameIndex = 0;
            gob->gob_currentFrameGroup = 0;
            gob->gob_work0 = 1;
        } else {
            gob->gob_work0 = 3;
            gob->gob_currentFrameIndex = 0;
            gob->gob_currentFrameGroup = 2;
        }
    } else
        VSIT_PlayVoiceSituation_0041f8c0(0x4a);
}
}
