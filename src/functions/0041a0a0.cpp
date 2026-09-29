// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;                   /* 0x7c */
    unsigned char _pad80[0x5c];
    int gob_oldContourDist;         /* 0xdc */
    unsigned char _padE0[0x30];
    struct GXObject *gob_platform;  /* 0x110 */
    int gob_platHitType;            /* 0x114 */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern int DAT_00455c54_DebugVar;
extern GXObject *gPlayerObject_004a27fc;
extern int DAT_00458edc;
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern char s_landeddist_ld_old_ld_00458f48[];
int __cdecl GetGlueDist_0040f1d0(void *level, GXObject *gob);
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
int __cdecl GOB_LandedOnContours_0041a0a0(GXObject *gob, int offset)
{
    int dist;
    gob->gob_ypos += offset;
    dist = GetGlueDist_0040f1d0(M1_CurrentLevel_004a2990, gob);
    gob->gob_ypos -= offset;
    if (DAT_00455c54_DebugVar > 2 && gPlayerObject_004a27fc == gob)
        TracePrintf_Debug_00405390(s_landeddist_ld_old_ld_00458f48, dist >> 16, gob->gob_oldContourDist >> 16);
    if (dist <= 0x18000 && dist >= DAT_00458edc
        && (gob->gob_oldContourDist >= -0x20000 || gob->gob_oldContourDist < -0x7e000000)) {
        gob->gob_oldContourDist = 0;
        gob->gob_ypos += dist;
        return 1;
    }
    gob->gob_oldContourDist = dist;
    if (gob->gob_platform && !gob->gob_platHitType)
        return 1;
    return 0;
}
}
