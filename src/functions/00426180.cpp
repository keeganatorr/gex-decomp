extern "C" {
extern unsigned char DAT_004A0294;
extern void *M1_CurrentLevel_004a2990;
extern int DAT_004a01e0;
extern int DAT_00463acc_GexVelocityInAir;

void __cdecl FUN_00423b80_pStateUnk(int *);
unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(int *);
void __cdecl InitPlayerRunJumpStart_00425ef0(int *);
int __cdecl FUN_00423b00_AirToFace_or_JumpTongueLash(int *);
void __cdecl GOB_KeepOutOfTiles_00420960(int *);
int __cdecl FUN_00423b40_CollisionIntoBounceFall(int *);
void __cdecl FUN_004244e0_left_right_move_xpos(int *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421a00_AirToSideCrawl(int *);
void __cdecl FUN_004214d0_y_pos_movement(int *);
void __cdecl FUN_004219c0_Velocity(void);
void __cdecl TILES_CheckYTileClid_0042d2c0(void *, int *, void (__cdecl *)(void));
void __cdecl FUN_00421780_pStateUnk_Fall(int *);
void __cdecl FUN_00421740_pStateUnk_Jump(int *);
int __cdecl FUN_004212d0_pStateUnk_yVel(int *);
int __cdecl FUN_004215d0_pStateUnk_Jump(int *, int);
void __cdecl InitPlayerRunStopFall_004263b0(int *);
}

extern "C" void __cdecl GEX_Target(int *p)
{
    int continueFall = 1;
    FUN_00423b80_pStateUnk(p);
    if (FUN_00420c70_GexWallCollisionInner(p) != 0 && DAT_004A0294 != 0) {
        InitPlayerRunJumpStart_00425ef0(p);
        return;
    }
    if (FUN_00423b00_AirToFace_or_JumpTongueLash(p) != 0)
        return;

    if (p[0x26] != 0) {
        if (p[0x23] > 0x20000) {
            p[0x26] = 0;
            p[0x15] = 4;
            GOB_KeepOutOfTiles_00420960(p);
        }
        if (p[0x26] != 0)
            goto checkFall;
    }
    continueFall = FUN_00423b40_CollisionIntoBounceFall(p) == 0;

checkFall:
    if (continueFall) {
        FUN_004244e0_left_right_move_xpos(p, 0x10000);
        FUN_004213f0_GexMovementLeftandRight(p);
        DAT_004a01e0 = 0;
        FUN_004213c0(M1_CurrentLevel_004a2990, p);
        if (FUN_00421a00_AirToSideCrawl(p) == 0) {
            FUN_004214d0_y_pos_movement(p);
            DAT_00463acc_GexVelocityInAir = 0;
            TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, p, FUN_004219c0_Velocity);
            FUN_00421780_pStateUnk_Fall(p);
            FUN_00421740_pStateUnk_Jump(p);
            if (FUN_004212d0_pStateUnk_yVel(p) == 0 &&
                FUN_004215d0_pStateUnk_Jump(p, 0) != 0) {
                InitPlayerRunStopFall_004263b0(p);
            }
        }
    }
}
