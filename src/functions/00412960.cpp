typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x98 - 0x74];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xa0 - 0x9c];
    int gob_work2;              /* 0xa0 */
    unsigned char _pada4[0xc4 - 0xa4];
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
extern GXInputRecord gInputControllers_004a0280[];
extern unsigned int DAT_00458758[];
void __cdecl GOB_ResetState_00420bc0(GXObject *gob);
void __cdecl InitPlayerSideTongueLash90_00413050(GXObject *gex);
void __cdecl PlayerSideTongueLash_00412880(GXObject *gex);
void __cdecl InitPlayerSideTongueLash_00412960(GXObject *gex)
{
    unsigned int pad;
    unsigned int dir;
    unsigned int next;
    unsigned int prev;
    pad = gInputControllers_004a0280[0].gxir_dValue;
    dir = DAT_00458758[(gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21];
    GOB_ResetState_00420bc0(gex);
    if (pad) {
        next = (dir & 7) + 1;
        prev = (dir - 2 & 7) + 1;
        if (pad)
            pad = (pad + 3 & 7) + 1;
        if (dir == pad || next == pad || prev == pad) {
            InitPlayerSideTongueLash90_00413050(gex);
            return;
        }
    }
    gex->gob_currentFrameIndex = 0;
    gex->gob_work0 = 0;
    gex->gob_state = 0x3a;
    gex->gob_currentFrameGroup = 0x4a;
    gex->gob_work2 = 0;
    PlayerSideTongueLash_00412880(gex);
}
}
