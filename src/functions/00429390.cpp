typedef unsigned char byte;
typedef unsigned int uint;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
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

extern "C" int __cdecl FUN_00429390_EnterPasswordSelectLevel(char *pw)
{
    unsigned char c;
    int k;
    int i;
    uint j;
    uint bit;
    byte t;
    if (FUN_004295C0(pw)) {
    FUN_004298C0(DAT_00463AF8, pw + 2);
    FUN_00405390(s_sizeof_main_map____d_0045ac2c, 7);
    DAT_004A2964 = DAT_0045abac_LevelNumberList[FUN_004297B0(DAT_00463AF8, 0, 3)];
    FUN_00405390(s_Found_level_number__d_0045ac14, DAT_004A2964);
    c = FUN_004297B0(DAT_00463AF8, 3, 5);
    FUN_00405390(s_Got_level_number__d_0045abfc, c);
    for (k = 0; k < c; k++)
        BYTE_ARRAY_004a2540[DAT_0045abb8_RemoteID[k]] |= 3;
    if (c < 0x13)
        BYTE_ARRAY_004a2540[DAT_0045abb8_RemoteID[c]] |= 1;
    bit = 8;
    c = FUN_004297B0(DAT_00463AF8, bit, 4);
    bit += 4;
    for (i = 0; i < c; i++)
        BYTE_ARRAY_004a2540[DAT_0045abd0_RemoteID[i]] |= 3;
    if (c < 8)
        BYTE_ARRAY_004a2540[DAT_0045abd0_RemoteID[c]] |= 1;
    for (j = 0; j < 4; j++, bit++) {
        if (FUN_004297B0(DAT_00463AF8, bit, 1)) {
            t = FUN_0045ABAD[j];
            BYTE_ARRAY_004a2540[t] |= 1;
            if (t != 0x34)
                BYTE_ARRAY_004a25d0[t] = 2;
        } else {
            BYTE_ARRAY_004a2540[DAT_0045abcc_HubTVIndex[j]] &= 0xfd;
        }
    }
    DAT_00458c8c = FUN_004297B0(DAT_00463AF8, bit, 5);
    bit += 5;
    switch ((byte)FUN_004297B0(DAT_00463AF8, bit, 2)) {
    case 1:
        BYTE_ARRAY_004a2540[8] = 3;
        break;
    case 2:
        BYTE_ARRAY_004a2540[8] = 1;
        break;
    default:
        BYTE_ARRAY_004a2540[8] = 0;
        break;
    }
    if (!(BYTE_ARRAY_004a2540[8] & 3))
        BYTE_ARRAY_004a2540[9] &= 0xfd;
    BYTE_ARRAY_004a2540[49] = 1;
    if (DAT_004A2964 == 0x37) {
        DAT_004A2A74 = 0x36;
        return 1;
    }
    DAT_004A2A74 = 0x37;
    return 1;
    }
    return 0;
}
