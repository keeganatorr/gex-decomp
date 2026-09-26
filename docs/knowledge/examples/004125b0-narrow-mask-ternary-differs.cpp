typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x78 - 0x74];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern int DAT_004586a8;
extern int DAT_004586c0;
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl PlayerSideGetup_004124c0(GXObject *gob);
void __cdecl GEX_Target(GXObject *gex)
{
    GOB_ResetState_00420bc0(gex);
    gex->gob_currentFrameIndex = 0;
    gex->gob_work0 = 0;
    gex->gob_state = 0x46;
    gex->gob_currentFrameGroup = 0x4d;
    if (((gex->gob_flags & 0x80000000) >> 28 | gex->gob_angle >> 21) == 8)
        gex->gob_flags |= 0x80000000;
    if (gex->gob_flags & 0x80000000)
        gex->gob_xpos += DAT_004586a8;
    else
        gex->gob_xpos -= DAT_004586a8;
    gex->gob_ypos += DAT_004586c0;
    PlayerSideGetup_004124c0(gex);
}
}
