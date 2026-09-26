// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXAniScript { unsigned char *as_script; int as_data[7]; } GXAniScript;
typedef int (__cdecl *GobFunc)(struct GXObject *gob);
typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;   /* 0xc */
    GXAniScript gob_scripts[2]; /* 0x10 */
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    GobFunc gob_initFunc;       /* 0x58 */
    GobFunc gob_doitFunc;       /* 0x5c */
    unsigned char _pad60[0x18];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x28];
    int gob_work4;              /* 0xa8 */
    unsigned char _padAC[0x24];
    int gob_removeDist;         /* 0xd0 */
} GXObject;
extern "C" {
extern GXAniScript DAT_0049fee0;
extern GXAniScript DAT_0049ff00;
extern GXAniScript DAT_0049ff20;
int __cdecl GOB_GetHotSpot_00419c00(GXObject *gob, int group, int index, int *x, int *y);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
int __cdecl DefDoIt_004339c0(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    int x;
    int y;
    GXObject *spawned;
    GXAniScript *script;
    if (GOB_GetHotSpot_00419c00(gob, 0, 0, &x, &y)) {
        x += gob->gob_xpos;
        y += gob->gob_ypos;
        spawned = GOB_AddObject_004195d0(0xe5, x, y, gob->gob_objectLoadData);
        if (spawned) {
            spawned->gob_currentFrameGroup = 0x11;
            spawned->gob_currentFrameIndex = 0;
            spawned->gob_doitFunc = DefDoIt_004339c0;
            if (gob->gob_work4 == 1)
                spawned->gob_scripts[0] = DAT_0049fee0;
            else if (gob->gob_work4 == 2)
                spawned->gob_scripts[0] = DAT_0049ff00;
            else
                spawned->gob_scripts[0] = DAT_0049ff20;
            spawned->gob_removeDist = 0x30000000;
        }
    }
}
}
