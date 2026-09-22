extern "C" {
extern void *DAT_004A2990;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern unsigned char DAT_004A0286;
extern int DAT_004A284C;
extern int DAT_004a0218_pState;

int __cdecl FUN_00421820_pStateUnk_Duck(int *);
int __cdecl FUN_00421560_DrawCharacter(void *, int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_00414A30(int *);
void __cdecl FUN_00424B80(int *);
void __cdecl InitPlayerDuckUnspin_00414f60(int *);
void __cdecl FUN_00421900(int *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);

void __cdecl GEX_Target(int *player)
{
    int duck = FUN_00421820_pStateUnk_Duck(player);
    if (FUN_00421560_DrawCharacter(DAT_004A2990, player) == 0) {
        FUN_004250B0(player);
        return;
    }
    if (DAT_004A0293 != 0 && DAT_004A0295 == 0) {
        player[0x31] = 0;
        FUN_00414A30(player);
        return;
    }
    if (duck == 0 && DAT_004A0294 != 0 && DAT_004A0295 == 0) {
        player[0x31] = 0;
        FUN_00424B80(player);
        return;
    }
    DAT_004A284C = 1;
    if (DAT_004A0286 == 0)
        player[0x29] = 1;

    player[0x26] += 0x10000;
    if (player[0x26] >= 0x10000) {
        player[0x26] -= 0x10000;
        ++player[0x15];
        if (player[0x15] > 8) {
            if (DAT_004A0286 != 0 && player[0x29] != 0) {
                player[0x15] = 3;
                player[0x29] = 0;
                DAT_004a0218_pState = 0x67;
            } else {
                player[0x31] = 0;
                InitPlayerDuckUnspin_00414f60(player);
                return;
            }
        } else {
            FUN_00421900(player);
        }
    }
    FUN_004213f0_GexMovementLeftandRight(player);
    FUN_004213c0(DAT_004A2990, player);
}
}
