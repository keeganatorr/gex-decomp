typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;   /* 0x54 */
    unsigned char _pad58[0x7c - 0x58];
    int gob_y;                   /* 0x7c */
    int gob_a;                   /* 0x80 */
    unsigned char _pad84[0x8c - 0x84];
    int gob_b;                   /* 0x8c */
    unsigned char _pad90[0x98 - 0x90];
    int gob_state;               /* 0x98 */
    unsigned char _pad9c[0xa8 - 0x9c];
    int gob_c;                   /* 0xa8 */
    int gob_d;                   /* 0xac */
    unsigned char _padb0[0xdc - 0xb0];
    int gob_yVel;                /* 0xdc */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern int DAT_004a025c;
void __cdecl FUN_00423b80_pStateUnk(GXObject *);
void __cdecl InitPlayerFalling_004252b0(GXObject *);
void __cdecl InitPlayerStopFall_00425c10(GXObject *);
void __cdecl GOB_KeepOutOfTiles_00420960(GXObject *);
void __cdecl FUN_004244e0_left_right_move_xpos(GXObject *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(GXObject *);
void __cdecl FUN_004213c0(void *, GXObject *);
int __cdecl FUN_00421a00_AirToSideCrawl(GXObject *);
void __cdecl FUN_004214d0_y_pos_movement(GXObject *);
void __cdecl FUN_004219c0_Velocity(void);
void __cdecl TILES_CheckYTileClid_0042d2c0(void *, GXObject *, void (__cdecl *)(void));
void __cdecl FUN_00421740_pStateUnk_Jump(GXObject *);
int __cdecl FUN_004212d0_pStateUnk_yVel(GXObject *);
int __cdecl FUN_004215d0_pStateUnk_Jump(GXObject *, int);
void __cdecl GEX_Target(GXObject *gob)
{
    gob->gob_a = gob->gob_c;
    gob->gob_b = gob->gob_d;
    FUN_00423b80_pStateUnk(gob);
    if (++gob->gob_state >= 1) {
        if (gob->gob_currentFrameIndex == 2) {
            gob->gob_y += 0x200000;
            gob->gob_yVel = DAT_004a025c = 0xffe00000;
            InitPlayerFalling_004252b0(gob);
            return;
        }
        gob->gob_state = 0;
        gob->gob_currentFrameIndex++;
        GOB_KeepOutOfTiles_00420960(gob);
    }
    FUN_004244e0_left_right_move_xpos(gob, 0x10000);
    FUN_004213f0_GexMovementLeftandRight(gob);
    FUN_004213c0(M1_CurrentLevel_004a2990, gob);
    if (!FUN_00421a00_AirToSideCrawl(gob)) {
        FUN_004214d0_y_pos_movement(gob);
        TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, FUN_004219c0_Velocity);
        FUN_00421740_pStateUnk_Jump(gob);
        if (FUN_004212d0_pStateUnk_yVel(gob)) {
            gob->gob_y += 0x200000;
            return;
        }
        if (FUN_004215d0_pStateUnk_Jump(gob, 0x200000)) {
            gob->gob_y += 0x200000;
            gob->gob_yVel = DAT_004a025c = 0xffe00000;
            InitPlayerStopFall_00425c10(gob);
        }
    }
}
}
