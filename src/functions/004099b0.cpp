typedef struct LevelEntry {
    unsigned short info;
    unsigned char pad2[2];
    unsigned char music;
    unsigned char rest[3];
} LevelEntry;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int DAT_004a2a08_LoadLevelMusic4;
extern int level_004a2964;
extern int DAT_004a2a00;
extern LevelEntry DAT_004577B0[];
extern void __cdecl MUS_Stop_00402f70(int, int);
void __cdecl GEX_Target(int force)
{
    int music;
    if (DAT_004a2a08_LoadLevelMusic4) {
        music = DAT_004577B0[level_004a2964].music;
        if (force || music != DAT_004a2a08_LoadLevelMusic4 || !(DAT_004577B0[level_004a2964].info & 0x100)) {
            MUS_Stop_00402f70(0, DAT_004a2a00);
            DAT_004a2a08_LoadLevelMusic4 = 0;
        }
    }
}
}
