extern "C" {
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0288;
extern int DAT_00456018_gex_Init_unk;
extern int DAT_004A2990;
extern int DAT_004A021C;
extern int DAT_00463ABC;

void __cdecl InitPlayerRunSkid_004270b0(int *);
void __cdecl InitPlayerSkid_00426d00(int *);
void __cdecl FUN_00424940(int *);
void __cdecl FUN_00424AA0(int *);
void __cdecl InitPlayerTurn_00427550(int *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(int, int *);
int __cdecl FUN_00421560_DrawCharacter(int, int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_00421cc0_Set_Stop_to_1();
void __cdecl FUN_0042CEC0(int, int *, void (__cdecl *)(), int);
void __cdecl InitPlayerPush_004244a0(int *);
}

extern "C" int __cdecl FUN_004245b0_Walk_Apply_Speed(int *param_1, int velocity)
{
    int iVar1;
    int animationType;

    if (DAT_004A0281 == 0 && DAT_004A0280 == 0 &&
        DAT_00456018_gex_Init_unk == 0) {
        if (param_1[28] == 22) {
            InitPlayerRunSkid_004270b0(param_1);
            return 0;
        }
        InitPlayerSkid_00426d00(param_1);
        return 0;
    }

    animationType = param_1[28];
    if (animationType == 22 && DAT_004A0288 == 0 &&
        DAT_00456018_gex_Init_unk == 0) {
        FUN_00424940(param_1);
        return 0;
    }

    if (animationType == 21 && DAT_004A0288 != 0) {
        FUN_00424AA0(param_1);
        return 0;
    }

    if (DAT_004A0281 == 0 && DAT_00456018_gex_Init_unk == 0) {
        if (DAT_004A0280 != 0) {
            if (param_1[34] > 0) {
                if (animationType == 22) {
                    InitPlayerRunSkid_004270b0(param_1);
                    return 0;
                }
                InitPlayerTurn_00427550(param_1);
                return 0;
            }
            param_1[27] = (int)((unsigned int)param_1[27] & 0x7fffffffU);
            param_1[34] = -velocity;
        } else {
            param_1[38] = param_1[38] - 1;
            animationType = param_1[27];
            if (param_1[40] == 0) {
                param_1[27] = (int)((unsigned int)animationType & 0x7fffffffU);
                param_1[34] = -velocity;
            } else {
                param_1[27] = (int)((unsigned int)animationType | 0x80000000U);
                param_1[34] = velocity;
            }
        }
    } else {
        if (param_1[34] < 0) {
            if (animationType == 22) {
                InitPlayerRunSkid_004270b0(param_1);
                return 0;
            }
            InitPlayerTurn_00427550(param_1);
            return 0;
        }
        animationType = param_1[27];
        param_1[27] = (int)((unsigned int)animationType | 0x80000000U);
        param_1[34] = velocity;
    }

    FUN_004213f0_GexMovementLeftandRight(param_1);
    if (DAT_00456018_gex_Init_unk != 0)
        return 1;

    FUN_004213c0(DAT_004A2990, param_1);
    if (DAT_004A021C == 0) {
        iVar1 = FUN_00421560_DrawCharacter(DAT_004A2990, param_1);
        if (iVar1 == 0) {
            DAT_004A021C = 1;
            FUN_004250B0(param_1);
            return 0;
        }
    }

    DAT_004A021C = 1;
    DAT_00463ABC = 0;
    FUN_0042CEC0(DAT_004A2990, param_1,
                 FUN_00421cc0_Set_Stop_to_1, -0x180000);
    if (DAT_00463ABC != 0) {
        InitPlayerPush_004244a0(param_1);
        return 0;
    }
    return 1;
}
