extern "C" {
extern unsigned char DAT_004A0285;
extern unsigned char DAT_004A0294;
extern void *DAT_004A2990;
extern int DAT_004a01e0;

void __cdecl FUN_00423b80_pStateUnk(int *);
int __cdecl FUN_00423b00_AirToFace_or_JumpTongueLash(int *);
int __cdecl FUN_00423B40(int *);
unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(int *);
void __cdecl FUN_00424E50(int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_004244e0_left_right_move_xpos(int *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421a00_AirToSideCrawl(int *);
void __cdecl FUN_004214d0_y_pos_movement(int *);
unsigned int __cdecl FUN_00421900(int *);
void __cdecl FUN_004219c0_Velocity(int *, int);
void __cdecl FUN_00425030(int *);
void __cdecl FUN_0042D2C0(void *, int *, void (__cdecl *)(int *, int));
void __cdecl FUN_00421740_pStateUnk_Jump(int *);
int __cdecl FUN_004212d0_pStateUnk_yVel(int *);
int __cdecl FUN_004215d0_pStateUnk_Jump(int *, int);
void __cdecl FUN_00425C10(int *);

void __cdecl GEX_Target(int *p)
{
    int proceed;
    FUN_00423b80_pStateUnk(p);
    if (DAT_004A0285 == 0 && p[0x28] == 0) {
        p[0x26] = 0;
    } else {
        if (p[0x26] != 0 || p[0x28] != 0) {
            if (p[0x26] != 0)
                --p[0x26];
            p[0x23] = p[0x27];
        }
    }
    if (p[0x28] != 0)
        --p[0x28];

    proceed = !FUN_00423b00_AirToFace_or_JumpTongueLash(p);
    if (proceed) {
        if (p[0x29] != 0)
            proceed = !FUN_00423B40(p);
        else
            --p[0x29];

        if (proceed) {
            if (FUN_00420c70_GexWallCollisionInner(p) != 0 && DAT_004A0294 != 0) {
                FUN_00424E50(p);
                return;
            }
            if ((FUN_00420c70_GexWallCollisionInner(p) ? -0x40000 : -0x20000) < p[0x23]) {
                FUN_004250B0(p);
                return;
            }
            FUN_004244e0_left_right_move_xpos(p, 0x10000);
            FUN_004213f0_GexMovementLeftandRight(p);
            DAT_004a01e0 = 0;
            FUN_004213c0(DAT_004A2990, p);
            if (FUN_00421a00_AirToSideCrawl(p) == 0) {
                FUN_004214d0_y_pos_movement(p);
                if (FUN_00421900(p) != 0) {
                    FUN_004219c0_Velocity(p, 0);
                    FUN_00425030(p);
                    return;
                }
                FUN_0042D2C0(DAT_004A2990, p, FUN_004219c0_Velocity);
                FUN_00421740_pStateUnk_Jump(p);
                if (FUN_004212d0_pStateUnk_yVel(p) == 0 &&
                    FUN_004215d0_pStateUnk_Jump(p, 0) != 0) {
                    FUN_00425C10(p);
                }
            }
        }
    }
}
}
