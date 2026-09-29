extern "C" {
extern char DAT_004A0294;
extern void *DAT_004A2990;
extern int DAT_004a01e0;
extern int DAT_00463acc_GexVelocityInAir;
int __cdecl FUN_00420c70_GexWallCollisionInner(int *);
int __cdecl FUN_00423B40(int *);
void __cdecl FUN_00424B80(int *);
void __cdecl FUN_00423b80_pStateUnk(int *);
int __cdecl FUN_00423b00_AirToFace_or_JumpTongueLash(int *);
void __cdecl FUN_00420960(int *);
void __cdecl FUN_004244e0_left_right_move_xpos(int *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421a00_AirToSideCrawl(int *);
void __cdecl FUN_004214d0_y_pos_movement(int *);
int __cdecl FUN_00421900(int *);
void __cdecl FUN_004219c0_Velocity();
void __cdecl FUN_0042D2C0(void *, int *, void (__cdecl *)());
void __cdecl FUN_00421780_pStateUnk_Fall(int *);
void __cdecl FUN_00421740_pStateUnk_Jump(int *);
int __cdecl FUN_004212d0_pStateUnk_yVel(int *);
int __cdecl FUN_004215d0_pStateUnk_Jump(int *, int);
void __cdecl FUN_00425C10(int *);
}

extern "C" void __cdecl PlayerFall_00424e80(int *p)
{
    int continueFall = 1;
    if (FUN_00420c70_GexWallCollisionInner(p) != 0 &&
        FUN_00423B40(p) == 0 && DAT_004A0294 != 0) {
        FUN_00424B80(p);
        return;
    }

    FUN_00423b80_pStateUnk(p);
    if (FUN_00423b00_AirToFace_or_JumpTongueLash(p) != 0)
        return;

    if (p[0x27] != 0 && --p[0x27] == 0) {
        p[0x14] = 0x27;
        p[0x15] = 3;
        FUN_00420960(p);
    }

    if (p[0x26] != 0) {
        if (p[0x23] > 0x20000) {
            p[0x26] = 0;
            p[0x27] = 0;
            p[0x14] = 0x27;
            p[0x15] = 4;
            FUN_00420960(p);
        }
        if (p[0x26] != 0)
            goto fall_motion;
    }
    continueFall = FUN_00423B40(p) == 0;

fall_motion:
    if (continueFall) {
        FUN_004244e0_left_right_move_xpos(p, 0x10000);
        FUN_004213f0_GexMovementLeftandRight(p);
        DAT_004a01e0 = 0;
        FUN_004213c0(DAT_004A2990, p);
        if (FUN_00421a00_AirToSideCrawl(p) == 0) {
            FUN_004214d0_y_pos_movement(p);
            if (p[0x23] < 0 && FUN_00421900(p) != 0)
                p[0x23] = 0;

            DAT_00463acc_GexVelocityInAir = 0;
            FUN_0042D2C0(DAT_004A2990, p, FUN_004219c0_Velocity);
            FUN_00421780_pStateUnk_Fall(p);
            FUN_00421740_pStateUnk_Jump(p);
            if (FUN_004212d0_pStateUnk_yVel(p) == 0 &&
                FUN_004215d0_pStateUnk_Jump(p, 0) != 0)
                FUN_00425C10(p);
        }
    }
}
