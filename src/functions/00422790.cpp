// The lash callback fires its projectile from the player's third hotspot.
// The indexed type and sound tables begin 0x10 and 0x20 bytes after 0045aa30.
extern "C" {
extern int DAT_004A2818;
extern int DAT_004A2838;
extern int DAT_004A0234;
extern int DAT_004a0248;
extern int DAT_004A2AC0;
extern int DAT_0045AA30;
extern int DAT_0045a6e0_GexPowerUpHealth;
extern int DAT_004a0218_pState;
extern int GEX_pGlob_004a2ad4;

int __cdecl FUN_00419C00(int *, int, int, int *, int *);
int *__cdecl GOB_AddObject_004195d0(int, int, int, int);
void __cdecl SND_PlayObSound_0041a250(int *, int, int, int);
void __cdecl FUN_00422580_pStateUnk_Lash_Inner(int *, int *);
void __cdecl CLD_AddObjectCollision_0041e7e0(int *, int *, int *, int *);

void __cdecl FUN_00422790_pStateUnk_Lash(int *player)
{
    int x, y;
    if (DAT_004A2818 == 0) {
        if (DAT_004A2AC0 == 0 && DAT_004a0248 != 0 &&
            FUN_00419C00(player, 3, 0, &x, &y) != 0 && player[0x28] == 0) {
            int count = DAT_004A0234 == 1 ? 3 : 1;
            while (count-- != 0) {
                int kind = DAT_004A0234;
                int *projectile = GOB_AddObject_004195d0(
                    (&DAT_0045AA30)[4 + kind], player[0x1e] + x,
                    player[0x1f] + y, GEX_pGlob_004a2ad4);
                if (projectile != 0) {
                    SND_PlayObSound_0041a250(player, (&DAT_0045AA30)[8 + kind],
                                              0x80, 0x60);
                    FUN_00422580_pStateUnk_Lash_Inner(player, projectile);
                    // Type 1 applies an additional three-way angle spread.
                    // That fixed-point transform remains to be reconstructed.
                    if (kind == 3) {
                        DAT_004a0248 = 0;
                        DAT_0045a6e0_GexPowerUpHealth = -1;
                    }
                }
            }
            ++player[0x28];
        }
    } else if (DAT_004A2838 != 0 &&
               FUN_00419C00(player, 3, 0, &x, &y) != 0) {
        int *projectile = (int *)DAT_004A2838;
        projectile[0x1e] = player[0x1e] + x;
        projectile[0x1f] = player[0x1f] + y;
        FUN_00422580_pStateUnk_Lash_Inner(player, projectile);
        projectile[0x17] = projectile[0x40];
        projectile[0x18] = projectile[0x41];
        projectile[0x19] = projectile[0x42];
        projectile[0x1b] = projectile[0x43];
        CLD_AddObjectCollision_0041e7e0(projectile,
            (int *)projectile[0x5a],
            (int *)((unsigned int)(projectile[0x1b] & 0xf00) >> 8),
            (int *)projectile[0x5b]);
        projectile[0x38] |= 8;
        DAT_004A2838 = 0;
        SND_PlayObSound_0041a250(player, 0x6e, 0x80, 0x60);
    }
    if (FUN_00419C00(player, 3, 0, &x, &y) != 0 && player[0x28] == 0) {
        DAT_004a0218_pState = 0x6c;
        ++player[0x28];
    }
}
}
