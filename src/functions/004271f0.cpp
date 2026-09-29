typedef unsigned int Word;

extern "C" {
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern void *DAT_004A2990;
extern int DAT_00463ABC;

void __cdecl InitPlayerRunSkidding_00426f60(Word *);
void __cdecl InitPlayerRunSkidStop_00426da0(Word *);
int __cdecl FUN_00424980_CheckGexInputs(Word *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(Word *);
void __cdecl FUN_004213c0(void *, Word *);
int __cdecl FUN_00421560_DrawCharacter(void *, Word *);
void __cdecl InitPlayerFalling_004252b0(Word *);
void __cdecl FUN_00421cc0_Set_Stop_to_1(void);
void __cdecl TILES_CheckOneXPoint_0042cec0(void *, Word *, void (__cdecl *)(void), int);
void __cdecl InitPlayerRunTurnStop_004271a0(Word *);
void __cdecl EFECT_AddPuff_0042e480(int, int, Word, int, Word);
int __cdecl abs(int);
}

extern "C" void __cdecl PlayerRunTurn_004271f0(Word *p)
{
    Word direction = p[0x1b] & 0x80000000U;
    if ((direction == 0 && DAT_004A0280 != 0) ||
        (direction != 0 && DAT_004A0281 != 0)) {
        InitPlayerRunSkidding_00426f60(p);
        return;
    }
    if ((direction != 0 && (int)p[0x20] < 0) ||
        (direction == 0 && (int)p[0x20] > 0)) {
        InitPlayerRunSkidStop_00426da0(p);
        return;
    }
    if (FUN_00424980_CheckGexInputs(p) == 0) {
        FUN_004213f0_GexMovementLeftandRight(p);
        FUN_004213c0(DAT_004A2990, p);
        if (FUN_00421560_DrawCharacter(DAT_004A2990, p) == 0) {
            p[0x1b] ^= 0x80000000U;
            InitPlayerFalling_004252b0(p);
            return;
        }
        DAT_00463ABC = 0;
        TILES_CheckOneXPoint_0042cec0(DAT_004A2990, p, FUN_00421cc0_Set_Stop_to_1, -0x180000);
        if (DAT_00463ABC != 0) {
            InitPlayerRunTurnStop_004271a0(p);
            return;
        }
        EFECT_AddPuff_0042e480((int)p[0x1e], (int)p[0x1f],
                            p[0x1b] & 0x80000000U, (int)p[0x31],
                            p[0x1b] & 0xfU);
        int speed = (int)p[0x20];
        if (abs(speed) < 0x10000 ||
            ((speed > 0) - (speed < 0)) != (int)p[0x27]) {
            InitPlayerRunTurnStop_004271a0(p);
        }
    }
}
