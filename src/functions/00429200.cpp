// Adapted from pc_decomp_backup/src/functions/FUN_00429200.cpp
// Historical source SHA256: 2ac9f44989edbddd5c8a7434491d55c36ff94b557555af7adc1e474c004b8a28
extern "C" {
extern unsigned char DAT_0045abac_LevelNumberList[];
extern unsigned char DAT_0045abb8_RemoteID[];
extern unsigned char DAT_0045abd0_RemoteID[];
extern unsigned char DAT_0045abcc_HubTVIndex[];
extern const char FUN_0045ABAD[];
extern int FUN_004A2964;
extern int FUN_00463AF8;
extern int DAT_00463afc;
extern int DAT_00463b00;
extern unsigned char BYTE_ARRAY_004a2540[];
extern unsigned char BYTE_ARRAY_004a25d0[];
extern unsigned char BYTE_ARRAY_004a2540_8_;
extern unsigned char BYTE_ARRAY_004a25d0_8_;
extern int DAT_00458c8c;

extern "C" void __cdecl FUN_004296d0_ParseLoadPasswords(int *, int, int, int);
extern "C" void __cdecl FUN_00429850_PasswordRelated(char *, unsigned char *, int);
extern "C" void __cdecl FUN_00429690_PasswordString(void *);
extern "C" void __cdecl FUN_00405390(char *, ...);

extern "C" void __cdecl GEX_Target(void *password)
{
    unsigned int uVar1;
    int iVar2;
    unsigned int uVar3;
    unsigned int uVar4;

    uVar4 = 0;
    uVar3 = 0;
    FUN_00463AF8 = 0;
    DAT_00463afc = 0;
    DAT_00463b00 = 0;
    uVar1 = 0;
    do {
        if (DAT_0045abac_LevelNumberList[uVar1] == FUN_004A2964) {
            uVar4 = 3;
            FUN_004296d0_ParseLoadPasswords(&FUN_00463AF8, uVar1, 0, 3);
            break;
        }
        uVar1 = uVar1 + 1;
    } while (uVar1 < 7);
    uVar1 = 0;
    do {
        if (((BYTE_ARRAY_004a2540[DAT_0045abb8_RemoteID[uVar1]] & 1) != 0) ||
            (BYTE_ARRAY_004a25d0[DAT_0045abb8_RemoteID[uVar1]] != 0)) {
            uVar3 = uVar1;
        }
        uVar1 = uVar1 + 1;
    } while (uVar1 < 0x13);
    FUN_004296d0_ParseLoadPasswords(&FUN_00463AF8, uVar3, uVar4, 5);
    uVar3 = 0;
    do {
        if ((BYTE_ARRAY_004a2540[DAT_0045abd0_RemoteID[uVar3]] & 2) == 0) break;
        uVar3 = uVar3 + 1;
    } while (uVar3 < 8);
    uVar1 = 0;
    FUN_004296d0_ParseLoadPasswords(&FUN_00463AF8, uVar3, uVar4 + 5, 4);
    uVar3 = uVar4 + 9;
    do {
        uVar4 = uVar3;
        if (((BYTE_ARRAY_004a2540[DAT_0045abcc_HubTVIndex[uVar1]] & 2) != 0) ||
            (iVar2 = 0, BYTE_ARRAY_004a25d0[FUN_0045ABAD[uVar1]] != 0)) {
            iVar2 = 1;
        }
        uVar1 = uVar1 + 1;
        FUN_004296d0_ParseLoadPasswords(&FUN_00463AF8, iVar2, uVar4, 1);
        uVar3 = uVar4 + 1;
    } while (uVar1 < 4);
    FUN_004296d0_ParseLoadPasswords(&FUN_00463AF8, DAT_00458c8c, uVar4 + 1, 5);
    if ((BYTE_ARRAY_004a2540_8_ & 2) == 0) {
        if ((BYTE_ARRAY_004a25d0_8_ != 0) || (iVar2 = 0, (BYTE_ARRAY_004a2540_8_ & 1) != 0)) {
            iVar2 = 2;
        }
    }
    else {
        iVar2 = 1;
    }
    FUN_004296d0_ParseLoadPasswords(&FUN_00463AF8, iVar2, uVar4 + 6, 2);
    FUN_00429850_PasswordRelated((char *)password + 2, (unsigned char *)&FUN_00463AF8, uVar4 + 8);
    FUN_00429690_PasswordString(password);
    FUN_00405390((char *)0x0045abe8, password);
}
}
