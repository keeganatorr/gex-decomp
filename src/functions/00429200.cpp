typedef struct passwordStruct {
    unsigned char field0;
    unsigned char field1;
    char text[1];
} passwordStruct;
extern "C" {
extern unsigned char gEnteredPassword_00463af8[10];
extern unsigned char DAT_0045abac_LevelNumberList[];
extern unsigned char DAT_0045abb8_RemoteID[];
extern unsigned char DAT_0045abd0_RemoteID[];
extern unsigned char DAT_0045abcc_HubTVIndex[];
extern unsigned char BYTE_ARRAY_004a2540[];
extern unsigned char BYTE_ARRAY_004a25d0[];
extern int level_004a2964;
extern int DAT_00458c8c;
extern char s_BCDFGHKLPRSTVXYZGot_password__s_0045abd8[];
void *__cdecl memset(void *, int, unsigned int);
void __cdecl FUN_004296d0_ParseLoadPasswords(unsigned char *bits, unsigned int value, unsigned int at, int width);
void __cdecl FUN_00429850_PasswordRelated(char *text, unsigned char *bits, unsigned int count);
void __cdecl FUN_00429690_PasswordString(passwordStruct *password);
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl GEX_Target(passwordStruct *password)
{
    unsigned int i;
    unsigned int bit;
    unsigned int last;
    unsigned int value;
    bit = 0;
    last = 0;
    memset(gEnteredPassword_00463af8, 0, 10);
    for (i = 0; i < 7; i++) {
        if (DAT_0045abac_LevelNumberList[i] == level_004a2964) {
            FUN_004296d0_ParseLoadPasswords(gEnteredPassword_00463af8, i, 0, 3);
            bit = 3;
            break;
        }
    }
    for (i = 0; i < 19; i++)
        if (BYTE_ARRAY_004a2540[DAT_0045abb8_RemoteID[i]] & 1 || BYTE_ARRAY_004a25d0[DAT_0045abb8_RemoteID[i]])
            last = i;
    FUN_004296d0_ParseLoadPasswords(gEnteredPassword_00463af8, last, bit, 5);
    bit += 5;
    for (i = 0; i < 8; i++)
        if (!(BYTE_ARRAY_004a2540[DAT_0045abd0_RemoteID[i]] & 2))
            break;
    FUN_004296d0_ParseLoadPasswords(gEnteredPassword_00463af8, i, bit, 4);
    bit += 4;
    for (i = 0; i < 4; i++) {
        value = BYTE_ARRAY_004a2540[DAT_0045abcc_HubTVIndex[i]] & 2 || BYTE_ARRAY_004a25d0[DAT_0045abac_LevelNumberList[i + 1]] ? 1 : 0;
        FUN_004296d0_ParseLoadPasswords(gEnteredPassword_00463af8, value, bit, 1);
        bit++;
    }
    FUN_004296d0_ParseLoadPasswords(gEnteredPassword_00463af8, DAT_00458c8c, bit, 5);
    bit += 5;
    value = BYTE_ARRAY_004a2540[8] & 2 ? 1 : BYTE_ARRAY_004a25d0[8] || BYTE_ARRAY_004a2540[8] & 1 ? 2 : 0;
    FUN_004296d0_ParseLoadPasswords(gEnteredPassword_00463af8, value, bit, 2);
    bit += 2;
    FUN_00429850_PasswordRelated(password->text, gEnteredPassword_00463af8, bit);
    FUN_00429690_PasswordString(password);
    TracePrintf_Debug_00405390(s_BCDFGHKLPRSTVXYZGot_password__s_0045abd8 + 0x10, password);
}
}
