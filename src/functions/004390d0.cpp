// Field names from Ghidra's GXObject layout (evidence, not proof). Only the
// members this function touches are declared; the rest is padding.
typedef struct GXObject {
    unsigned char _pad0[0x8c];
    int gob_yVel;     /* 0x8c */
    int gob_maxyVel;  /* 0x90 */
    int gob_yAccl;    /* 0x94 */
} GXObject;
extern "C" {
extern void __cdecl FUN_00438470_MoveGuillotine(GXObject *, int);
void __cdecl GOB_ProcessYPositionChange_004390d0(GXObject *gob)
{
    gob->gob_yVel += gob->gob_yAccl;
    if (gob->gob_yVel > gob->gob_maxyVel)
        gob->gob_yVel = gob->gob_maxyVel;
    else if (gob->gob_yVel < -gob->gob_maxyVel)
        gob->gob_yVel = -gob->gob_maxyVel;
    FUN_00438470_MoveGuillotine(gob, gob->gob_yVel);
}
}
