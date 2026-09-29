extern "C" unsigned char DAT_004A0280;
extern "C" unsigned char DAT_004A0281;
extern "C" int DAT_004A23C8;

struct MoveState {
    unsigned char unknown_00[0x6c];
    unsigned int flags;
    unsigned char unknown_70[0x10];
    int velocity;
    unsigned char unknown_84[4];
    int acceleration;
};

extern "C" void __cdecl FUN_004244e0_left_right_move_xpos(MoveState* p, int amount)
{
    if (DAT_004A0280 != 0) {
        if (p->velocity > 0 && DAT_004A23C8 == 0) {
            p->velocity = 0;
            p->acceleration = 0;
            return;
        }
        p->acceleration = -amount;
        p->flags &= 0x7fffffff;
        return;
    }
    if (DAT_004A0281 != 0) {
        if (p->velocity < 0 && DAT_004A23C8 == 0) {
            p->velocity = 0;
            p->acceleration = 0;
            return;
        }
        p->acceleration = amount;
        p->flags |= 0x80000000;
        return;
    }
    if (p->velocity > 0x10000) {
        p->acceleration = -0x4000;
        return;
    }
    if (p->velocity < -0x10000) {
        p->acceleration = 0x4000;
        return;
    }
    p->acceleration = 0;
}
