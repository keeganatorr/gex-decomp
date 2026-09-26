extern "C" void __cdecl GOB_ResetState_00420bc0(unsigned long *);
extern "C" void __cdecl PlayerAirToSideCrawl_004140f0(unsigned long *);
extern "C" void __cdecl TracePrintf_Debug_00405390(const char *, ...);
extern "C" void *gPlayerPlatform_004a2864;
extern "C" char s_Bad_Initial_Side_Stick_Angle_00458be4[];

extern "C" void __cdecl GEX_Target(unsigned long *param_1)
{
    GOB_ResetState_00420bc0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = 0x37;
    param_1[0x14] = 0x59;

    switch (((param_1[0x1b] & 0x80000000) ? 8 : 0) |
            ((long)param_1[0x31] >> 0x15)) {
    case 0:
    case 0xc:
        param_1[0x1f] -= 0x200000UL;
        if (gPlayerPlatform_004a2864 == 0) {
            param_1[0x1e] = param_1[0x61] | 0x1f0000UL;
            PlayerAirToSideCrawl_004140f0(param_1);
            return;
        }
        break;

    case 2:
    case 0xe:
        if (gPlayerPlatform_004a2864 == 0) {
            param_1[0x1f] = param_1[0x62] | 0x1f0000UL;
            PlayerAirToSideCrawl_004140f0(param_1);
            return;
        }
        break;

    case 4:
    case 8:
        param_1[0x1f] -= 0x200000UL;
        if (gPlayerPlatform_004a2864 == 0)
            param_1[0x1e] = param_1[0x61] & 0xffe00000UL;
        break;

    default:
        TracePrintf_Debug_00405390(s_Bad_Initial_Side_Stick_Angle_00458be4);
        PlayerAirToSideCrawl_004140f0(param_1);
        return;
    }

    PlayerAirToSideCrawl_004140f0(param_1);
}