extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int DAT_004a01e0;
extern void *DAT_004A2990;

unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(int *);
void __cdecl FUN_00422360_COLLISION_HEALTHLOSTINHERE(int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_00425AF0(int *);
void __cdecl FUN_00423b80_pStateUnk(int *);
int __cdecl FUN_00423ab0_AirToFaceCrawl(int *);
int __cdecl FUN_00423190_CollisionIntoJumpTailWhack(int *);
int __cdecl FUN_00423B40(int *);
void __cdecl FUN_00420960(int *);
void __cdecl FUN_004244e0_left_right_move_xpos(int *, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
void __cdecl FUN_004214d0_y_pos_movement(int *);
void __cdecl FUN_004219c0_Velocity();
void __cdecl FUN_0042D2C0(void *, int *, void (__cdecl *)());
void __cdecl FUN_00421740_pStateUnk_Jump(int *);
int __cdecl FUN_004212d0_pStateUnk_yVel(int *);
int __cdecl FUN_004215d0_pStateUnk_Jump(int *, int);
void __cdecl FUN_00425C10(int *);

void __cdecl GEX_Target(int *state)
{
    int bounceClear;
    if ((DAT_004A0295 != 0 ||
         (DAT_004A0294 != 0 && FUN_00420c70_GexWallCollisionInner(state) != 0)) &&
        DAT_004A0293 == 0) {
        FUN_00422360_COLLISION_HEALTHLOSTINHERE(state);
        if (DAT_004A0294 != 0) {
            FUN_004250B0(state);
            return;
        }
        FUN_00425AF0(state);
        return;
    }

    FUN_00423b80_pStateUnk(state);
    if (FUN_00423ab0_AirToFaceCrawl(state) == 0 &&
        FUN_00423190_CollisionIntoJumpTailWhack(state) == 0 &&
        (bounceClear = !FUN_00423B40(state))) {
        ++state[0x26];
        if (state[0x26] >= 4) {
            state[0x26] = 0;
            if (state[0x15] == 0) {
                FUN_00422360_COLLISION_HEALTHLOSTINHERE(state);
                FUN_004250B0(state);
                return;
            }
            ++state[0x15];
            FUN_00420960(state);
        }
        FUN_004244e0_left_right_move_xpos(state, 0x10000);
        FUN_004213f0_GexMovementLeftandRight(state);
        DAT_004a01e0 = 0;
        FUN_004213c0(DAT_004A2990, state);
        FUN_004214d0_y_pos_movement(state);
        FUN_0042D2C0(DAT_004A2990, state, FUN_004219c0_Velocity);
        FUN_00421740_pStateUnk_Jump(state);
        if (FUN_004212d0_pStateUnk_yVel(state) != 0) {
            FUN_00422360_COLLISION_HEALTHLOSTINHERE(state);
            return;
        }
        if (FUN_004215d0_pStateUnk_Jump(state, 0) != 0) {
            FUN_00422360_COLLISION_HEALTHLOSTINHERE(state);
            FUN_00425C10(state);
        }
    }
}
}
