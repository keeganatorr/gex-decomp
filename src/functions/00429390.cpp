typedef unsigned char byte;
typedef unsigned int uint;

extern "C" {
int __cdecl FUN_004295C0(char *);
void __cdecl FUN_004298C0(byte *, char *);
int __cdecl FUN_004297B0(byte *, uint, uint);
int __cdecl FUN_00405390(char *, ...);

extern byte DAT_00463AF8[];
extern byte DAT_0045abac_LevelNumberList[];
extern byte DAT_0045abb8_RemoteID[];
extern byte DAT_0045abcc_HubTVIndex[];
extern byte DAT_0045abd0_RemoteID[];
extern byte FUN_0045ABAD[];
extern byte BYTE_ARRAY_004a2540[];
extern byte BYTE_ARRAY_004a25d0[];
extern uint DAT_00458c8c;
extern byte DAT_004A2548;
extern byte DAT_004A2549;
extern byte DAT_004A2571;
extern uint DAT_004A2964;
extern uint DAT_004A2A74;
extern char s_sizeof_main_map____d_0045ac2c[];
extern char s_Found_level_number__d_0045ac14[];
extern char s_Got_level_number__d_0045abfc[];
}

extern "C" int __cdecl GEX_Target(char *param_1)
{
    byte *pbVar1;
    byte bVar2;
    int levelNumberIndex;
    uint levelNumberFromPassword;
    uint levelNumber;
    uint bitOffset;

    levelNumberIndex = FUN_004295C0(param_1);
    if (levelNumberIndex == 0) {
        return 0;
    }

    FUN_004298C0(DAT_00463AF8, param_1 + 2);
    FUN_00405390(s_sizeof_main_map____d_0045ac2c, 7);

    levelNumberIndex = FUN_004297B0(DAT_00463AF8, 0, 3);
    DAT_004A2964 = (uint)(byte)DAT_0045abac_LevelNumberList[levelNumberIndex];
    FUN_00405390(s_Found_level_number__d_0045ac14, DAT_004A2964);

    levelNumberFromPassword = FUN_004297B0(DAT_00463AF8, 3, 5);
    levelNumber = levelNumberFromPassword & 0xff;
    FUN_00405390(s_Got_level_number__d_0045abfc, levelNumber);

    levelNumberIndex = 0;
    if ((byte)levelNumberFromPassword != 0) {
        do {
            pbVar1 = DAT_0045abb8_RemoteID + levelNumberIndex;
            levelNumberIndex = levelNumberIndex + 1;
            BYTE_ARRAY_004a2540[*pbVar1] = BYTE_ARRAY_004a2540[*pbVar1] | 3;
        } while (levelNumberIndex < (int)levelNumber);
    }

    if ((byte)levelNumberFromPassword < 0x13) {
        BYTE_ARRAY_004a2540[(byte)DAT_0045abb8_RemoteID[levelNumber]] =
            BYTE_ARRAY_004a2540[(byte)DAT_0045abb8_RemoteID[levelNumber]] | 1;
    }

    levelNumberIndex = 0;
    levelNumberFromPassword = FUN_004297B0(DAT_00463AF8, 8, 4);
    if ((char)levelNumberFromPassword != '\0') {
        do {
            pbVar1 = DAT_0045abd0_RemoteID + levelNumberIndex;
            levelNumberIndex = levelNumberIndex + 1;
            BYTE_ARRAY_004a2540[*pbVar1] = BYTE_ARRAY_004a2540[*pbVar1] | 3;
        } while (levelNumberIndex < (int)(levelNumberFromPassword & 0xff));
        levelNumberFromPassword = levelNumberFromPassword & 0xff;
    }

    if ((byte)levelNumberFromPassword < 8) {
        BYTE_ARRAY_004a2540[(byte)DAT_0045abd0_RemoteID[levelNumberFromPassword & 0xff]] =
            BYTE_ARRAY_004a2540[(byte)DAT_0045abd0_RemoteID[levelNumberFromPassword & 0xff]] | 1;
    }

    levelNumber = 0;
    levelNumberFromPassword = 0xc;
    do {
        bitOffset = levelNumberFromPassword;
        levelNumberIndex = FUN_004297B0(DAT_00463AF8, bitOffset, 1);
        if (levelNumberIndex == 0) {
            BYTE_ARRAY_004a2540[(byte)DAT_0045abcc_HubTVIndex[levelNumber]] =
                BYTE_ARRAY_004a2540[(byte)DAT_0045abcc_HubTVIndex[levelNumber]] & 0xfd;
        } else {
            bVar2 = FUN_0045ABAD[levelNumber];
            BYTE_ARRAY_004a2540[bVar2] = BYTE_ARRAY_004a2540[bVar2] | 1;
            if (bVar2 != 0x34) {
                BYTE_ARRAY_004a25d0[bVar2] = 2;
            }
        }
        levelNumber = levelNumber + 1;
        levelNumberFromPassword = bitOffset + 1;
    } while (levelNumber < 4);

    DAT_00458c8c = FUN_004297B0(DAT_00463AF8, bitOffset + 1, 5);
    levelNumberFromPassword = FUN_004297B0(DAT_00463AF8, bitOffset + 6, 2);

    if ((levelNumberFromPassword & 0xff) == 1) {
        DAT_004A2548 = 3;
    } else if ((levelNumberFromPassword & 0xff) == 2) {
        DAT_004A2548 = 1;
    } else {
        DAT_004A2548 = 0;
    }

    if ((DAT_004A2548 & 3) == 0) {
        DAT_004A2549 = DAT_004A2549 & 0xfd;
    }

    DAT_004A2571 = 1;
    if (DAT_004A2964 != 0x37) {
        DAT_004A2A74 = 0x37;
        return 1;
    }

    DAT_004A2A74 = 0x36;
    return 1;
}
