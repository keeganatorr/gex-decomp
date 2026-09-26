typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x7c - 0x74];
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl PlayerPlatAirToSideCrawl_00414240(GXObject *gex);
void __cdecl GEX_Target(GXObject *gex)
{
    GOB_ResetState_00420bc0(gex);
    gex->gob_currentFrameIndex = 0;
    gex->gob_work0 = 0;
    gex->gob_state = 0x4e;
    gex->gob_currentFrameGroup = 0x59;
    switch ((gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21) {
    case 0:
    case 0xc:
        gex->gob_ypos -= 0x200000;
        PlayerPlatAirToSideCrawl_00414240(gex);
        return;
    case 4:
    case 8:
        gex->gob_ypos -= 0x200000;
        break;
    }
    PlayerPlatAirToSideCrawl_00414240(gex);
}
}
