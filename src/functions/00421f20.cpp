typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xc4 - 0x80];
    int gob_angle;              /* 0xc4 */
    unsigned char _padc8[0xe4 - 0xc8];
    int gob_leftEdge;           /* 0xe4 */
    int gob_rightEdge;          /* 0xe8 */
    int gob_topEdge;            /* 0xec */
    int gob_bottomEdge;         /* 0xf0 */
} GXObject;
extern "C" {
extern unsigned int DAT_0045a790[];
int __cdecl FUN_00421f20_pStateUnk_Side(GXObject *gex)
{
    unsigned int sides;
    sides = DAT_0045a790[(gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21];
    if (sides & 0x1000)
        gex->gob_leftEdge = gex->gob_xpos;
    if (sides & 0x100)
        gex->gob_rightEdge = gex->gob_xpos;
    if (sides & 0x10)
        gex->gob_topEdge = gex->gob_ypos;
    if (sides & 1)
        gex->gob_bottomEdge = gex->gob_ypos;
    return 1;
}
}
