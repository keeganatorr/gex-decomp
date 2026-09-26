// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;       /* 0x7c */
    int gob_xVel;       /* 0x80 */
    unsigned char _pad84[0x8];
    int gob_yVel;       /* 0x8c */
    unsigned char _pad90[0x14];
    int gob_work3;      /* 0xa4 */
    unsigned char _padA8[0xdc];
    int gob_checkXpos;  /* 0x184 */
} GXObject;
typedef struct JumpStep { int xVel; int yVel; int velocity; } JumpStep;
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
extern GXObject *DAT_004a23d0;
extern int DAT_004a23c8;
extern int DAT_004a2890_velocity_unk;
extern JumpStep DAT_0045b038[];
void __cdecl FUN_0041b700_ObjCallUnkInner(GXObject *gob);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, int flags);
int __cdecl FUN_0042d7c0_ObjCallUnk(GXObject *gob, int arg);
int __cdecl GEX_Target(GXObject *gob, int arg)
{
    GXObject *spawned;
    if (gPlayerObject_004a27fc == gob) {
        if (DAT_004a23d0)
            FUN_0041b700_ObjCallUnkInner(DAT_004a23d0);
        spawned = GOB_AddObject_004195d0(0x11c, gob->gob_checkXpos, gob->gob_ypos, 0);
        if (spawned) {
            DAT_004a23d0 = spawned;
            spawned->gob_work3 = 0;
        }
        FUN_0042d7c0_ObjCallUnk(gob, arg);
        gob->gob_xVel = DAT_0045b038[DAT_004a23c8].xVel;
        gob->gob_yVel = DAT_0045b038[DAT_004a23c8].yVel;
        DAT_004a2890_velocity_unk = DAT_0045b038[DAT_004a23c8++].velocity;
        if (DAT_004a23c8 == 4)
            DAT_004a23c8--;
        return 0;
    }
    return FUN_0042d7c0_ObjCallUnk(gob, arg);
}
}
