extern "C" {
extern int level_004a2964;
extern int gIsMapLevel_004a2ac0;
extern unsigned char gCurrentCheatCode_00455b38;
extern int DAT_00455c24_LivesUnk;
extern int gNumLives_00456b00;
extern int gCheatPowerupToSpawn_00459498;
extern int gInvincible_00455c28;
void __cdecl GEX_Target(void)
{
    if (level_004a2964 == 0x44 || gIsMapLevel_004a2ac0)
        return;
    switch (gCurrentCheatCode_00455b38) {
    case 2:
        gCurrentCheatCode_00455b38 = 0xb;
        DAT_00455c24_LivesUnk = 1;
        gNumLives_00456b00 = 99;
        break;
    case 3:
        gCurrentCheatCode_00455b38 = 0xb;
        gCheatPowerupToSpawn_00459498 = 5;
        break;
    case 4:
        gCurrentCheatCode_00455b38 = 0xb;
        gCheatPowerupToSpawn_00459498 = 4;
        break;
    case 5:
        gCurrentCheatCode_00455b38 = 0xb;
        gCheatPowerupToSpawn_00459498 = 6;
        break;
    case 6:
        gCurrentCheatCode_00455b38 = 0xb;
        gCheatPowerupToSpawn_00459498 = 2;
        break;
    case 7:
        gCurrentCheatCode_00455b38 = 0xb;
        gCheatPowerupToSpawn_00459498 = 8;
        break;
    case 8:
        gCurrentCheatCode_00455b38 = 0xb;
        gInvincible_00455c28 = 1;
        break;
    }
}
}
