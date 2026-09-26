// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    unsigned char _pad54[0x18];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0xc];
    int gob_xVel;               /* 0x80 */
    int gob_maxxVel;            /* 0x84 */
    int gob_xAccl;              /* 0x88 */
    int gob_yVel;               /* 0x8c */
    int gob_maxyVel;            /* 0x90 */
    int gob_yAccl;              /* 0x94 */
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0x28];
    int gob_angle;              /* 0xc4 */
    unsigned char _padC8[0x18];
    unsigned int gob_flags2;    /* 0xe0 */
} GXObject;
extern "C" {
extern void *GEX_pGlob_004a2ad4;
extern GXObject *gPlayerObject_004a27fc;
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *gob, unsigned int priority);
void __cdecl GEX_Target(int x, int y, unsigned int flags, int angle, unsigned int priority)
{
    GXObject *puff;
    puff = GOB_AddObject_004195d0(0x5c, x, y, GEX_pGlob_004a2ad4);
    if (puff) {
        puff->gob_flags |= flags | 0xc000;
        puff->gob_maxxVel = 0x7fff0000;
        puff->gob_xVel = (flags & 0x80000000) ? -0x10000 : 0x10000;
        puff->gob_xAccl = 0;
        puff->gob_maxyVel = 0x7fff0000;
        puff->gob_yVel = -0x8000;
        puff->gob_yAccl = 0;
        puff->gob_angle = angle;
        puff->gob_currentFrameGroup = 0x18;
        puff->gob_work0 = 3;
        puff->gob_state = 0x30;
        GOB_SetObjectDisplayPriority_00419b80(puff, priority);
        if (gPlayerObject_004a27fc->gob_flags2 & 0x40)
            puff->gob_flags2 |= 0x40;
    }
}
}
