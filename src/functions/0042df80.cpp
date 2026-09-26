// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;       /* 0x78 */
    unsigned char _pad7c[0x10];
    int gob_yVel;       /* 0x8c */
    unsigned char _pad90[0x14];
    int gob_work3;      /* 0xa4 */
    unsigned char _padA8[0xe0];
    int gob_checkYpos;  /* 0x188 */
} GXObject;
typedef struct BounceStep { int yVel; int velocity; int unk8; } BounceStep;
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
extern GXObject *DAT_004a23dc;
extern int DAT_004a23c8;
extern int DAT_004a2890_velocity_unk;
extern BounceStep DAT_0045b00c[];
void __cdecl FUN_0041b700_ObjCallUnkInner(GXObject *gob);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, int flags);
int __cdecl FUN_0042dab0_gOb_GexFuncUnk(GXObject *gob, int arg);
int __cdecl GEX_Target(GXObject *gob, int arg)
{
    GXObject *spawned;
    if (gPlayerObject_004a27fc == gob) {
        if (DAT_004a23dc)
            FUN_0041b700_ObjCallUnkInner(DAT_004a23dc);
        spawned = GOB_AddObject_004195d0(0x11c, gob->gob_xpos, gob->gob_checkYpos, 0);
        if (spawned) {
            DAT_004a23dc = spawned;
            spawned->gob_work3 = 3;
        }
        FUN_0042dab0_gOb_GexFuncUnk(gob, arg);
        gob->gob_yVel = -DAT_0045b00c[DAT_004a23c8].yVel;
        DAT_004a2890_velocity_unk = DAT_0045b00c[DAT_004a23c8++].velocity;
        if (DAT_004a23c8 == 4)
            DAT_004a23c8--;
        return 0;
    }
    return FUN_0042dab0_gOb_GexFuncUnk(gob, arg);
}
}
