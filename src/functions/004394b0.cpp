// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef int (__cdecl *GobFunc)(struct GXObject *gob);
typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;   /* 0xc */
    unsigned char _pad10[0x40];
    int gob_currentFrameGroup;  /* 0x50 */
    unsigned char _pad54[8];
    GobFunc gob_doitFunc;       /* 0x5c */
    unsigned char _pad60[0x18];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    int gob_xVel;               /* 0x80 */
    unsigned char _pad84[8];
    int gob_yVel;               /* 0x8c */
} GXObject;
extern "C" {
int __cdecl UTL_ReallyRandom_00428c80(int range);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
int __cdecl FUN_00439460_HuntDiveInner(GXObject *gob);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *gob, GXObject *other);
void __cdecl GEX_Target(GXObject *gob)
{
    int dx;
    int dy;
    GXObject *drop;
    if (UTL_ReallyRandom_00428c80(2))
        dy = UTL_ReallyRandom_00428c80(8) << 16;
    else
        dy = -(UTL_ReallyRandom_00428c80(8) << 16);
    if (UTL_ReallyRandom_00428c80(2))
        dx = UTL_ReallyRandom_00428c80(8) << 16;
    else
        dx = -(UTL_ReallyRandom_00428c80(8) << 16);
    drop = GOB_AddObject_004195d0(0x13b, gob->gob_xpos + dx, gob->gob_ypos + dy, gob->gob_objectLoadData);
    if (drop) {
        drop->gob_doitFunc = FUN_00439460_HuntDiveInner;
        if (UTL_ReallyRandom_00428c80(2))
            drop->gob_xVel = UTL_ReallyRandom_00428c80(0x50000);
        else
            drop->gob_xVel = -UTL_ReallyRandom_00428c80(0x50000);
        if (UTL_ReallyRandom_00428c80(2))
            drop->gob_yVel = UTL_ReallyRandom_00428c80(0x50000);
        else
            drop->gob_yVel = -UTL_ReallyRandom_00428c80(0x50000);
        drop->gob_currentFrameGroup = 3;
        GOB_PutObjectInfrontOfObject_00419be0(drop, gob);
    }
}
}
