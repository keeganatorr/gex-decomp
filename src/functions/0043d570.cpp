// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;    /* 0x78 */
    int gob_ypos;    /* 0x7c */
    unsigned char _pad1[0x28];
    int gob_work4;   /* 0xa8 */
    unsigned char _pad2[0x8];
    int gob_work7;   /* 0xb4 */
} GXObject;
extern "C" {
extern int gIsAddingObjectIntros_004a27d4;
extern int gStartDoorID_00456adc;
extern int gLastStartDoorID_00456aec;
extern int gStartDoorType_00456ae0;
extern int DAT_004a280c_xPos;
extern int DAT_004a2810_yPos;
extern int DAT_004a282c_startxPos;
extern int DAT_004a2830_startypos;
extern void *M1_CurrentLevel_004a2990;
extern int __cdecl GetGlueDist_0040f1d0(void *, GXObject *);
extern void __cdecl GOB_RemoveMapObject_00419840(GXObject *);
extern void __cdecl DefInit_004335f0(GXObject *, int);
int __cdecl abs(int);
void __cdecl ob115Init_0043d570(GXObject *gob)
{
    int dist;
    if (gIsAddingObjectIntros_004a27d4) {
        if (gob->gob_work7 == gStartDoorID_00456adc) {
            DAT_004a280c_xPos = gob->gob_xpos;
            DAT_004a2810_yPos = gob->gob_ypos;
            gob->gob_ypos += 0x200000;
            DAT_004a282c_startxPos = gob->gob_xpos;
            DAT_004a2830_startypos = gob->gob_ypos;
            gStartDoorType_00456ae0 = 0;
            dist = GetGlueDist_0040f1d0(M1_CurrentLevel_004a2990, gob);
            if (abs(dist) < 0x5a0000)
                DAT_004a2830_startypos += dist;
        }
        GOB_RemoveMapObject_00419840(gob);
    } else {
        if (gob->gob_work7 == gLastStartDoorID_00456aec) {
            gLastStartDoorID_00456aec = -2;
            gob->gob_work4 = 1;
        }
        DefInit_004335f0(gob, 0);
    }
}
}
