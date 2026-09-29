// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0xb0];
    int gob_work6;   /* 0xb0 */
} GXObject;
typedef struct Slot { int a, b, c, d; } Slot;
extern "C" {
extern unsigned char DAT_00462c70;
extern int M1_004a2994;
extern int M1_IsInMap_004a2a7c;
extern Slot DAT_00456168[6];
extern int DAT_004a2920_LoadLevelUnk5;
extern int DAT_00456020_MusicOnUnk;
extern int DAT_0045601c_LevelMusicUnk;
extern int DAT_00462c68;
void __cdecl ob212Init_0040c4d0(GXObject *gob)
{
    Slot *slot;
    DAT_00462c70 = 0;
    M1_004a2994 = 0;
    M1_IsInMap_004a2a7c = 1;
    gob->gob_work6 = 0;
    for (slot = DAT_00456168; slot < &DAT_00456168[6]; slot++)
        slot->a = 0;
    if (DAT_004a2920_LoadLevelUnk5)
        gob->gob_work6 = 1;
    else
        gob->gob_work6 = 0;
    DAT_00456020_MusicOnUnk = 1;
    DAT_0045601c_LevelMusicUnk = 0;
    DAT_00462c68 = 0;
}
}

