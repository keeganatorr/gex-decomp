// Field names from Ghidra's GXObject/GXHitArea layouts (evidence, not proof).
typedef struct GXHitArea { int gxha_left; int gxha_top; int gxha_right; int gxha_bottom; } GXHitArea;
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;           /* 0x6c */
    unsigned char _pad70[0x100];
    GXHitArea *gob_phaClid;           /* 0x170 */
    GXHitArea *gob_phaClidWith;       /* 0x174 */
    struct GXObject *gob_pgobClidWith; /* 0x178 */
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int DAT_004a023c_PowerUp_Invincibility;
extern int DAT_00455c54_DebugVar;
extern int DAT_00464700;
extern char s_Damage_To_GEX_0045b140[];
int __cdecl _printf(const char *format, ...);
void __cdecl PlayerDamage_00417b70(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob, int *event)
{
    int mine;
    int theirs;
    if (*event) {
        mine = gob->gob_phaClid->gxha_left & 0xffff;
        theirs = gob->gob_phaClidWith->gxha_left & 0xffff;
        if ((gob->gob_pgobClidWith->gob_flags & 0xf00) == 0x200 && !DAT_004a023c_PowerUp_Invincibility
            && (mine == theirs || mine == 1)) {
            if (DAT_00455c54_DebugVar > 1)
                _printf(s_Damage_To_GEX_0045b140);
            PlayerDamage_00417b70(gob);
            return;
        }
        if (theirs == 1)
            DAT_00464700 = 1;
    }
}
}
