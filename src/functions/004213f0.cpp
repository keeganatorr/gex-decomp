// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x70];
    int gob_state;    /* 0x70 */
    unsigned char _pad1[0x4];
    int gob_xpos;     /* 0x78 */
    unsigned char _pad2[0x4];
    int gob_xVel;     /* 0x80 */
    int gob_maxxVel;  /* 0x84 */
    int gob_xAccl;    /* 0x88 */
} GXObject;
extern "C" {
extern unsigned int DAT_00457210[];
extern void __cdecl FUN_00420FA0(GXObject *);
extern void __cdecl FUN_00421120(GXObject *);
extern int __cdecl FUN_00420CE0(GXObject *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(GXObject *gob)
{
    int divisor;
    gob->gob_xVel += gob->gob_xAccl;
    if (gob->gob_xVel < 0) {
        if (gob->gob_xAccl == 0 && (DAT_00457210[gob->gob_state] & 0x40)) {
            gob->gob_xVel += 0x2000;
            if (gob->gob_xVel > 0)
                gob->gob_xVel = 0;
        }
        if (gob->gob_xVel < -gob->gob_maxxVel)
            gob->gob_xVel = -gob->gob_maxxVel;
    } else if (gob->gob_xVel > 0) {
        if (gob->gob_xAccl == 0 && (DAT_00457210[gob->gob_state] & 0x40)) {
            gob->gob_xVel -= 0x2000;
            if (gob->gob_xVel < 0)
                gob->gob_xVel = 0;
        }
        if (gob->gob_xVel > gob->gob_maxxVel)
            gob->gob_xVel = gob->gob_maxxVel;
    }
    FUN_00420FA0(gob);
    FUN_00421120(gob);
    divisor = FUN_00420CE0(gob);
    if (divisor)
        gob->gob_xpos += gob->gob_xVel / divisor;
    else
        gob->gob_xpos += gob->gob_xVel;
}
}
