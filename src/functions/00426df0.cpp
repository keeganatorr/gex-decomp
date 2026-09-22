extern "C" {
extern char DAT_004A0280;
extern char DAT_004A0281;
extern void *DAT_004A2990;
extern int DAT_00463ABC;
int __cdecl abs(int);
void __cdecl InitPlayerRunSkidStop_00426da0(int *);
int __cdecl FUN_00424980_CheckGexInputs(int *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421560_DrawCharacter(void *, int *);
void __cdecl InitPlayerFalling_004252b0(int *);
void __cdecl FUN_00421cc0_Set_Stop_to_1();
void __cdecl TILES_CheckOneXPoint_0042cec0(void *, int *, void (__cdecl *)(), int);
void __cdecl InitPlayerStand_00424090(int *);
void __cdecl EFECT_AddPuff_0042e480(int, int, unsigned int, int, unsigned int);
void __cdecl InitPlayerRun_00424aa0(int *);
void __cdecl InitPlayerRunTurn_00427340(int *);

void __cdecl GEX_Target(int *p)
{
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0) {
        if (((p[0x1b] & 0x80000000u) != 0 && p[0x20] < 0) ||
            ((p[0x1b] & 0x80000000u) == 0 && p[0x20] > 0)) {
            InitPlayerRunSkidStop_00426da0(p);
            return;
        }
        if (FUN_00424980_CheckGexInputs(p) == 0) {
            FUN_004213f0_GexMovementLeftandRight(p);
            FUN_004213c0(DAT_004A2990, p);
            if (FUN_00421560_DrawCharacter(DAT_004A2990, p) == 0) {
                InitPlayerFalling_004252b0(p);
                return;
            }
            DAT_00463ABC = 0;
            TILES_CheckOneXPoint_0042cec0(DAT_004A2990, p,
                                         FUN_00421cc0_Set_Stop_to_1, -0x180000);
            if (DAT_00463ABC != 0) {
                InitPlayerStand_00424090(p);
                return;
            }
            EFECT_AddPuff_0042e480(p[0x1e], p[0x1f],
                                  p[0x1b] & 0x80000000u,
                                  p[0x31], p[0x1b] & 0x0fu);
            int velocity = p[0x20];
            if (abs(velocity) < 0x10000 ||
                ((velocity > 0) - (velocity < 0)) != p[0x27]) {
                InitPlayerRunSkidStop_00426da0(p);
                return;
            }
        }
    } else {
        if (((p[0x1b] & 0x80000000u) != 0 && DAT_004A0281 != 0) ||
            ((p[0x1b] & 0x80000000u) == 0 && DAT_004A0280 != 0)) {
            InitPlayerRun_00424aa0(p);
            return;
        }
        InitPlayerRunTurn_00427340(p);
    }
}
}
