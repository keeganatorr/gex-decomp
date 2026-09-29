struct PlayerState {
    unsigned char unknown00[0x54];
    int state54;
    unsigned char unknown58[0x40];
    int counter98;
};

typedef void (__cdecl *VelocityFunction)(void *);

extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern void *DAT_004A2888;
extern void *DAT_004A2990;
extern int DAT_004a01e0;

unsigned int __cdecl FUN_00420c70_GexWallCollisionInner(PlayerState *);
void __cdecl FUN_00420960(PlayerState *);
int __cdecl FUN_004212d0_pStateUnk_yVel(PlayerState *);
void __cdecl FUN_004213c0(void *, PlayerState *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(PlayerState *);
void __cdecl FUN_004214d0_y_pos_movement(PlayerState *);
int __cdecl FUN_004215d0_pStateUnk_Jump(PlayerState *, int);
void __cdecl FUN_00421740_pStateUnk_Jump(PlayerState *);
void __cdecl FUN_004219c0_Velocity(void *);
void __cdecl FUN_00422360_COLLISION_HEALTHLOSTINHERE(PlayerState *);
void __cdecl FUN_00422410_EatingObject_pState_Call(PlayerState *);
void __cdecl FUN_00422790_pStateUnk_Lash(PlayerState *);
void __cdecl FUN_00423120_Lash_unk(PlayerState *);
void __cdecl FUN_00423130_pStateUnk_Eating(PlayerState *);
int __cdecl FUN_00423190_CollisionIntoJumpTailWhack(PlayerState *);
int __cdecl FUN_00423ab0_AirToFaceCrawl(PlayerState *);
void __cdecl FUN_00423b80_pStateUnk(PlayerState *);
unsigned int __cdecl FUN_00423B40(PlayerState *);
void __cdecl FUN_004244e0_left_right_move_xpos(PlayerState *, int);
void __cdecl FUN_004250B0(PlayerState *);
void __cdecl FUN_00425460(PlayerState *);
void __cdecl FUN_00425AF0(PlayerState *);
void __cdecl FUN_00425C10(PlayerState *);
void __cdecl FUN_0042D2C0(void *, PlayerState *, VelocityFunction);
}

extern "C" void __cdecl PlayerJumpTongueLash_004254b0(PlayerState *param_1)
{
    int iVar2;

    if (((DAT_004A0295 != 0) ||
         ((DAT_004A0294 != 0) &&
          (FUN_00420c70_GexWallCollisionInner(param_1) != 0))) &&
        (DAT_004A0293 == 0)) {
        FUN_00423120_Lash_unk(param_1);
        if (DAT_004A2888 != 0) {
            FUN_00425460(param_1);
            return;
        }
        if (DAT_004A0294 != 0)
            FUN_004250B0(param_1);
        FUN_00425AF0(param_1);
        return;
    }

    FUN_00423b80_pStateUnk(param_1);
    iVar2 = FUN_00423ab0_AirToFaceCrawl(param_1);
    if ((iVar2 == 0) &&
        ((iVar2 = FUN_00423190_CollisionIntoJumpTailWhack(param_1)) == 0)) {
        iVar2 = FUN_00423B40(param_1) == 0;
        if (iVar2 != 0) {
            ++param_1->counter98;
            if (param_1->counter98 >= 2) {
                param_1->counter98 = 0;
                if (param_1->state54 == 4) {
                    FUN_00423120_Lash_unk(param_1);
                    if (DAT_004A2888 != 0)
                        FUN_00425460(param_1);
                    else
                        FUN_004250B0(param_1);
                    return;
                }
                ++param_1->state54;
                FUN_00420960(param_1);
                FUN_00422790_pStateUnk_Lash(param_1);
            }

            FUN_004244e0_left_right_move_xpos(param_1, 0x10000);
            FUN_004213f0_GexMovementLeftandRight(param_1);
            DAT_004a01e0 = 0;
            FUN_004213c0(DAT_004A2990, param_1);
            FUN_004214d0_y_pos_movement(param_1);
            FUN_0042D2C0(DAT_004A2990, param_1, FUN_004219c0_Velocity);
            FUN_00421740_pStateUnk_Jump(param_1);

            iVar2 = FUN_004212d0_pStateUnk_yVel(param_1);
            if (iVar2 != 0) {
                if (DAT_004A2888 != 0) {
                    FUN_00422410_EatingObject_pState_Call(param_1);
                    FUN_00422360_COLLISION_HEALTHLOSTINHERE(param_1);
                    FUN_00423130_pStateUnk_Eating(param_1);
                    return;
                }
            } else {
                iVar2 = FUN_004215d0_pStateUnk_Jump(param_1, 0);
                if (iVar2 != 0) {
                    if (DAT_004A2888 != 0) {
                        FUN_00422410_EatingObject_pState_Call(param_1);
                        FUN_00422360_COLLISION_HEALTHLOSTINHERE(param_1);
                    }
                    FUN_00425C10(param_1);
                }
            }
        }
    }

    FUN_00423130_pStateUnk_Eating(param_1);
}
