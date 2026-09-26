typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x78 - 0x74];
    unsigned int gob_xpos;      /* 0x78 */
    int gob_ypos;               /* 0x7c */
    int gob_xVel;               /* 0x80 */
    unsigned char _pad84[0x8c - 0x84];
    int gob_yVel;               /* 0x8c */
    unsigned char _pad90[0x98 - 0x90];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern GXObject *gPlayerPlatform_004a2864;
extern int DAT_004a23c8;
extern int DAT_004a0218_pState;
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl InitPlayerPlatSideCrawl_00411a40(GXObject *gex);
void __cdecl PlayerSideCrawl_00427d30(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    GOB_ResetState_00420bc0(gex);
    if (gPlayerPlatform_004a2864) {
        InitPlayerPlatSideCrawl_00411a40(gex);
        return;
    }
    gex->gob_state = 0x3d;
    gex->gob_currentFrameGroup = 0x49;
    gex->gob_currentFrameIndex = 4;
    gex->gob_yVel = 0;
    gex->gob_xVel = 0;
    gex->gob_work0 = 0;
    DAT_004a23c8 = 0;
    switch ((gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21) {
    case 0:
    case 0xc:
        gex->gob_xpos |= 0x1f0000;
        break;
    case 4:
    case 8:
        gex->gob_xpos &= 0xffe00000;
        break;
    }
    DAT_004a0218_pState = 0x6b;
    PlayerSideCrawl_00427d30(gex);
}
}
