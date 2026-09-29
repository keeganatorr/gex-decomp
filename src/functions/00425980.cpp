extern "C" {
extern char DAT_004A0293;
extern char DAT_004A0294;
extern char DAT_004A0295;
extern int DAT_004A284C;
extern int DAT_004a01e0;
extern void *DAT_004A2990;

void __cdecl FUN_00425690(int *);
unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_00423b80_pStateUnk(int *);
int __cdecl FUN_00423ab0_AirToFaceCrawl(int *);
int __cdecl FUN_004231c0_JumpTongueLash(int *);
int __cdecl FUN_00423B40(int *);
void __cdecl FUN_00420960(int *);
void __cdecl FUN_00421900(int *);
void __cdecl FUN_004244e0_left_right_move_xpos(int *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
void __cdecl FUN_004214d0_y_pos_movement(int *);
void __cdecl FUN_004219c0_Velocity();
void __cdecl FUN_0042D2C0(void *, int *, void (__cdecl *)());
void __cdecl FUN_00421740_pStateUnk_Jump(int *);
int __cdecl FUN_004212d0_pStateUnk_yVel(int *);
int __cdecl FUN_004215d0_pStateUnk_Jump(int *, int);
void __cdecl FUN_004276E0(int *);

void __cdecl PlayerJumpTailWhack_00425980(int *player)
{
    if (DAT_004A0293 && !DAT_004A0295) {
        FUN_00425690(player);
        return;
    }
    if (DAT_004A0294 && !DAT_004A0295 &&
        FUN_00420c70_GexWallCollisionInner(player)) {
        FUN_004250B0(player);
        return;
    }
    DAT_004A284C = 1;
    FUN_00423b80_pStateUnk(player);
    if (!FUN_00423ab0_AirToFaceCrawl(player) &&
        !FUN_004231c0_JumpTongueLash(player)) {
        int canContinue = !FUN_00423B40(player);
        if (canContinue) {
            if (++player[0x26] >= 2) {
                player[0x26] = 0;
                if (player[0x15] == 4) {
                    FUN_004250B0(player);
                    return;
                }
                ++player[0x15];
                FUN_00420960(player);
                FUN_00421900(player);
            }
            FUN_004244e0_left_right_move_xpos(player, 0x10000);
            FUN_004213f0_GexMovementLeftandRight(player);
            DAT_004a01e0 = 0;
            FUN_004213c0(DAT_004A2990, player);
            FUN_004214d0_y_pos_movement(player);
            FUN_0042D2C0(DAT_004A2990, player, FUN_004219c0_Velocity);
            FUN_00421740_pStateUnk_Jump(player);
            if (!FUN_004212d0_pStateUnk_yVel(player) &&
                FUN_004215d0_pStateUnk_Jump(player, 0)) {
                FUN_004276E0(player);
            }
        }
    }
}
}
