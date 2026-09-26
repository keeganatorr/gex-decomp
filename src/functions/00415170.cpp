typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x98 - 0x58];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
    unsigned char _padb0[0xc8 - 0xb0];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
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
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern int decl_pad_15;
extern int decl_pad_16;
extern int decl_pad_17;
extern int decl_pad_18;
extern int DAT_00458898[];
extern unsigned char DAT_004588d0[];
extern LevelEntry DAT_004577B0[];
extern unsigned int gCollectibles_004a2660[6];
extern unsigned char gRemotesGained_004a2420[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern int DAT_00456ae8;
extern int LEVELID_00456ad8;
extern int level_004a2964;
extern int gGameState_00455c3c;
extern int M1_IsInMap_004a2a7c;
extern int DAT_00455be8;
extern int DAT_00455bec;
extern int DAT_00455bfc;
extern int DAT_00455c00;
void __cdecl GEX_Target(GXObject *gob)
{
    unsigned int *p;
    int kind;
    int image;
    gob->gob_work2 += 0x5556;
    if (gob->gob_work2 >= 0x10000) {
        gob->gob_work2 -= 0x10000;
        gob->gob_currentFrameIndex++;
    }
    image = DAT_00458898[gob->gob_work0];
    if (!image) {
        if (DAT_00456ae8 == 4) {
            gGameState_00455c3c = 5;
            for (p = gCollectibles_004a2660; p < &gCollectibles_004a2660[6]; p++) {
                kind = *p & 0xff;
                if (kind >= 0 && kind <= 2)
                    gRemotesGained_004a2420[level_004a2964] |= DAT_004588d0[kind];
            }
            if (gRemotesGained_004a2420[level_004a2964] >> 4 == (gRemotesGained_004a2420[level_004a2964] & 0xf))
                BYTE_ARRAY_004a2540[level_004a2964] |= 2;
        } else if (DAT_004577B0[LEVELID_00456ad8].info & 0x80)
            gGameState_00455c3c = 2;
        else {
            if (LEVELID_00456ad8 == 47 || LEVELID_00456ad8 == 61)
                LEVELID_00456ad8 = level_004a2964;
            gGameState_00455c3c = 3;
        }
        if (level_004a2964 != LEVELID_00456ad8) {
            level_004a2964 = LEVELID_00456ad8;
            M1_IsInMap_004a2a7c = 1;
        } else
            M1_IsInMap_004a2a7c = 3;
    } else {
        gob->gob_xScale -= 0x400;
        gob->gob_yScale -= 0x400;
        gob->gob_work0++;
        DAT_00455be8 = image;
        DAT_00455bec = image;
        DAT_00455bfc += gob->gob_work4;
        DAT_00455c00 += gob->gob_work5;
    }
}
}
