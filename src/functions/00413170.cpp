typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x98 - 0x74];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    unsigned char _pada8[0xc4 - 0xa8];
    int gob_angle;              /* 0xc4 */
} GXObject;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;        /* 0x0 */
    BUTTON_RECORD gxir_padJustOnButtons;  /* 0xf */
    unsigned char _pad1e[2];
    unsigned int gxir_dValue;             /* 0x20 */
} GXInputRecord;
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
extern GXInputRecord gInputControllers_004a0280[];
extern unsigned int DAT_00458758[];
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl InitPlayerSideSlap_004135a0(GXObject *gex);
void __cdecl InitPlayerTailWhap_004136d0(GXObject *gex);
void __cdecl PlayerSideSpin_004130a0(GXObject *gex);
void __cdecl InitPlayerSideSpin_00413170(GXObject *gex)
{
    unsigned int pad;
    unsigned int dir;
    unsigned int next;
    unsigned int prev;
    pad = gInputControllers_004a0280[0].gxir_dValue;
    dir = DAT_00458758[(gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21];
    GOB_ResetState_00420bc0(gex);
    next = (dir & 7) + 1;
    prev = (dir - 2 & 7) + 1;
    if (dir == pad || next == pad || prev == pad) {
        InitPlayerSideSlap_004135a0(gex);
        return;
    }
    if (pad)
        pad = (pad + 3 & 7) + 1;
    if (dir == pad || next == pad || prev == pad) {
        InitPlayerTailWhap_004136d0(gex);
        return;
    }
    gex->gob_state = 0x48;
    gex->gob_work0 = 0;
    gex->gob_work1 = 0;
    gex->gob_work3 = 0;
    gex->gob_currentFrameIndex = 0;
    gex->gob_currentFrameGroup = 0x55;
    PlayerSideSpin_004130a0(gex);
}
}
