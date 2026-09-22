extern "C" {
extern unsigned char DAT_004A0294;
extern void *DAT_004A2990;
extern int DAT_004a01e0;
extern int DAT_00463acc_GexVelocityInAir;

unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(int *);
void __cdecl InitPlayerStandJumpStart_00424b80(int *);
void __cdecl VFX_Play_0041fa80(int);
void __cdecl FUN_00423b80_pStateUnk(int *);
int __cdecl FUN_00423b00_AirToFace_or_JumpTongueLash(int *);
int __cdecl FUN_00423b40_CollisionIntoBounceFall(int *);
void __cdecl FUN_004244e0_left_right_move_xpos(int *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421a00_AirToSideCrawl(int *);
void __cdecl FUN_004214d0_y_pos_movement(int *);
unsigned int __cdecl PlayerBreakSomething_00421900(int *);
void __cdecl FUN_004219c0_Velocity(void);
void __cdecl TILES_CheckYTileClid_0042d2c0(void *, int *, void (__cdecl *)(void));
void __cdecl FUN_00421780_pStateUnk_Fall(int *);
void __cdecl FUN_00421740_pStateUnk_Jump(int *);
int __cdecl FUN_004212d0_pStateUnk_yVel(int *);
int __cdecl FUN_004215d0_pStateUnk_Jump(int *, int);
void __cdecl InitPlayerStopFall_00425c10(int *);
void __cdecl InitPlayerStopFalling_00425da0(int *);

void __cdecl GEX_Target(int *p)
{
    if (FUN_00420c70_GexWallCollisionInner(p) != 0 && DAT_004A0294 != 0) {
        InitPlayerStandJumpStart_00424b80(p);
        return;
    }
    if ((p[0x27] = ((volatile int *)p)[0x27] - 1) == 0)
        VFX_Play_0041fa80(13);
    FUN_00423b80_pStateUnk(p);
    if (FUN_00423b00_AirToFace_or_JumpTongueLash(p) == 0) {
        int canFall;
        if (FUN_00423b40_CollisionIntoBounceFall(p) != 0)
            canFall = 0;
        else
            canFall = 1;
        if (canFall) {
            p[0x26] += 0x5556;
            if (p[0x26] >= 0x10000) {
                p[0x26] -= 0x10000;
                ++p[0x15];
            }
            FUN_004244e0_left_right_move_xpos(p, 0x10000);
            FUN_004213f0_GexMovementLeftandRight(p);
            DAT_004a01e0 = 0;
            FUN_004213c0(DAT_004A2990, p);
            if (FUN_00421a00_AirToSideCrawl(p) == 0) {
                FUN_004214d0_y_pos_movement(p);
                if (p[0x23] < 0) {
                    if (PlayerBreakSomething_00421900(p) != 0)
                        p[0x23] = 0;
                }
                DAT_00463acc_GexVelocityInAir = 0;
                TILES_CheckYTileClid_0042d2c0(DAT_004A2990, p, FUN_004219c0_Velocity);
                FUN_00421780_pStateUnk_Fall(p);
                FUN_00421740_pStateUnk_Jump(p);
                if (FUN_004212d0_pStateUnk_yVel(p) == 0) {
                    if (FUN_004215d0_pStateUnk_Jump(p, 0) != 0) {
                        if (p[0x27] >= 0) {
                            InitPlayerStopFall_00425c10(p);
                            return;
                        }
                        InitPlayerStopFalling_00425da0(p);
                    }
                }
            }
        }
    }
}
}
