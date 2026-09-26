// Field names from Ghidra's GXObject/GXHitArea layouts (evidence, not proof).
typedef struct GXHitArea { int gxha_left; int gxha_top; int gxha_right; int gxha_bottom; } GXHitArea;
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;         /* 0x54 */
    unsigned char _pad58[0x14];
    unsigned int gob_flags;            /* 0x6c */
    unsigned char _pad70[0x2c];
    int gob_work1;                     /* 0x9c */
    unsigned char _padA0[0x18];
    int gob_flashTime;                 /* 0xb8 */
    unsigned char _padBC[0xb4];
    GXHitArea *gob_phaClid;            /* 0x170 */
    GXHitArea *gob_phaClidWith;        /* 0x174 */
    struct GXObject *gob_pgobClidWith; /* 0x178 */
} GXObject;
extern "C" {
extern int DAT_004a023c_PowerUp_Invincibility;
extern void *PTR_00464e14;
void __cdecl PlayerDamage_00417b70(GXObject *gob);
void __cdecl SND_PlaySound_0041a340(void *sound, int id);
void __cdecl GEX_Target(GXObject *gob, int *event)
{
    unsigned int mine;
    unsigned int theirs;
    unsigned int kind;
    if (!*event)
        return;
    if (gob->gob_flashTime > 0)
        return;
    if (gob->gob_work1 <= 0x10 || gob->gob_work1 >= 0x70)
        return;
    mine = gob->gob_phaClid->gxha_left & 0xffff;
    theirs = gob->gob_phaClidWith->gxha_left & 0xffff;
    kind = (gob->gob_pgobClidWith->gob_flags & 0xf00) >> 8;
    if (kind == 2 && !DAT_004a023c_PowerUp_Invincibility && (theirs == mine || mine == 1)) {
        PlayerDamage_00417b70(gob);
        return;
    }
    if ((DAT_004a023c_PowerUp_Invincibility && kind == 2) || mine == 2 || theirs == 1) {
        if (theirs != 3) {
            SND_PlaySound_0041a340(PTR_00464e14, 0x115);
            gob->gob_currentFrameIndex = 0;
        }
    }
}
}
