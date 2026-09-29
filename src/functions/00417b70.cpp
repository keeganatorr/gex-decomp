extern "C" {
extern int gIsMapLevel_004a2ac0;
extern int DAT_00462e38;
extern int *gPlayerObject_004a27fc;
extern int gHitpoints_004a281c;
extern int DAT_004a27f4;
extern int gInvincible_00455c28;
extern unsigned int DAT_00457210[];
extern int DAT_004a023c_PowerUp_Invincibility;
extern int DAT_0045a6e0_GexPowerUpHealth;
extern int DAT_004a2840;
extern int gNoProcess_00455c4c;
extern int DAT_004a2878_CollisionType;
extern int DAT_004a2850;
extern int DAT_004a0218_pState;
void __cdecl PlayerKill_00417ca0(int);
int __cdecl FUN_004206b0(int);
void __cdecl FUN_00422390_Reset_Powerups(int *);

void __cdecl PlayerDamage_00417b70(void)
{
    int state;
    int *damageTimer;
    if (gIsMapLevel_004a2ac0 != 0) {
        DAT_00462e38 = 1;
        return;
    }
    if (gPlayerObject_004a27fc != 0 &&
        gHitpoints_004a281c != 0 &&
        DAT_004a27f4 == 0 &&
        gInvincible_00455c28 == 0 &&
        (DAT_00457210[state = gPlayerObject_004a27fc[0x1c]] & 0xf0000000U) != 0x50000000U &&
        DAT_004a023c_PowerUp_Invincibility == 0 &&
        (damageTimer = gPlayerObject_004a27fc + 0x2e, *damageTimer == 0) &&
        state != 2 && state != 1) {
        if (DAT_0045a6e0_GexPowerUpHealth >= 0) {
            DAT_0045a6e0_GexPowerUpHealth = -1;
        } else {
            if (gHitpoints_004a281c == 1) {
                PlayerKill_00417ca0(0);
                return;
            }
            --gHitpoints_004a281c;
        }
        ++DAT_004a2840;
        ++gNoProcess_00455c4c;
        DAT_004a2878_CollisionType = 20;
        DAT_004a2850 = 1;
        *damageTimer = 90;
        if (FUN_004206b0(85) == 0)
            DAT_004a0218_pState = 118;
        FUN_00422390_Reset_Powerups(gPlayerObject_004a27fc);
    }
}
}
