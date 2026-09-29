extern "C" {
extern int DAT_004A0230;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int DAT_00463ABC;
extern void *DAT_004A2990;
void __cdecl FUN_00427760(int *);
void __cdecl FUN_00424B80(int *);
void __cdecl FUN_00427B80(int *);
void __cdecl FUN_00424090(int *);
void __cdecl FUN_00424940(int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_00421cc0_Set_Stop_to_1();
void __cdecl FUN_0042CEC0(void *, int *, void (__cdecl *)(), int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421560_DrawCharacter(void *, int *);
}

extern "C" void __cdecl PlayerPush_00424360(int *player)
{
    if (DAT_004A0230 == 0) {
        ++DAT_004A0230;
        if (DAT_004A0295) {
            FUN_00427760(player);
            return;
        }
        if (DAT_004A0294) {
            FUN_00424B80(player);
            return;
        }
        if (!DAT_004A0293) {
            int released;
            if ((unsigned int)player[0x1b] & 0x80000000u)
                released = DAT_004A0281 == 0;
            else
                released = DAT_004A0280 == 0;
            if (released) {
                FUN_00424090(player);
                return;
            }
            player[0x1e] += DAT_004A0281 ? 0x20000 : -0x20000;
            DAT_00463ABC = 0;
            FUN_0042CEC0(DAT_004A2990, player,
                        FUN_00421cc0_Set_Stop_to_1, -0x180000);
            if (DAT_00463ABC == 0) {
                FUN_00424940(player);
                return;
            }
        } else {
            FUN_00427B80(player);
            return;
        }
    }
    ++player[0x26];
    if (player[0x26] >= 4) {
        player[0x26] = 0;
        ++player[0x15];
    }
    FUN_004213f0_GexMovementLeftandRight(player);
    FUN_004213c0(DAT_004A2990, player);
    if (DAT_004A0230 < 2 &&
        FUN_00421560_DrawCharacter(DAT_004A2990, player) == 0) {
        FUN_004250B0(player);
    }
}
