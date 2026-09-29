extern "C" {
extern unsigned char BYTE_ARRAY_004a2540[];
extern unsigned char *PTR_M1_00455b80;
extern void *DAT_00455B7C;
extern char s_Loading_Level___ld_00455eac[];

extern int DAT_00455B70;
extern int DAT_00455B74;
extern int DAT_00455C3C;
extern int DAT_004A2964;
extern int DAT_004A2A3C;
extern int DAT_004A2A74;
extern int DAT_004A2A7C;
extern int DAT_004A2A80;
extern char DAT_004A2A8C;
extern char DAT_004A0293;
extern char DAT_004A0294;
extern char DAT_004A0295;
extern int FUN_004A2970;

void FUN_004099B0(int);
void FUN_00409940(void);
void FUN_0040AA60(void);
void FUN_0043E430(int);
void FUN_00405350(char *, unsigned int);
void FUN_0040A8C0(void);
void FUN_0041EBE0(void *, void *, int);
int FUN_0041ECD0(void *);
void FUN_0041F2D0(void *);
void FUN_0040A940(void);
void FUN_00409A30(void *);
void FUN_00409FE0(void);
int FUN_0040A010(void *);
void FUN_0040A660(void *);
void FUN_00441110(void);
void FUN_00440830(void);
void FUN_00401B40(int);
void FUN_0041F6F0(void *);

void M1_GameLoop_0040ad40(void)
{
    unsigned char *blockAnims;
    unsigned int levelId;
    int playResult;
    int zero;
    char levelDone;
    int levelOffset;

    FUN_004099B0(1);

    if ((BYTE_ARRAY_004a2540[28] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[29] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[30] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[31] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[62] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[136] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[137] & 2) != 0 &&
        (BYTE_ARRAY_004a2540[138] & 2) != 0)
        levelOffset = 0;
    else
        levelOffset = 0x44;

    blockAnims = PTR_M1_00455b80;
    zero = 0;
    levelDone = 0;
    FUN_00409940();
    FUN_0040AA60();
    DAT_004A2A3C = 1;

    while (DAT_004A2A80 == zero && levelDone == 0) {
        DAT_004A2A74 = DAT_004A2964;
        levelId = ((unsigned char *)&DAT_00455C3C)[levelOffset + 0x2c];
        if (levelId == 0)
            break;

        FUN_0043E430(1);
        FUN_00405350(s_Loading_Level___ld_00455eac, levelId);
        DAT_004A2964 = levelId;
        FUN_0040A8C0();
        FUN_0041EBE0(DAT_00455B7C, blockAnims, 1);

        do {
            playResult = FUN_0041ECD0(blockAnims);
        } while (playResult == 0);

        FUN_0041F2D0(blockAnims);
        FUN_0040A940();

        if (DAT_004A2964 == 0x45 ||
            DAT_004A2964 == 0x86 ||
            DAT_004A2964 == 0x8b) {
            DAT_00455B70 = 0x780000;
            DAT_00455B74 = 0x780000;
        } else {
            DAT_00455B74 = 0x3e80000;
            DAT_00455B70 = zero;
        }

        DAT_00455C3C = 4;
        FUN_004A2970 = 6;
        FUN_00409A30(blockAnims);
        DAT_004A2A7C = 1;
        FUN_00409FE0();

        do {
            playResult = FUN_0040A010(blockAnims);
            levelDone = DAT_004A2A8C;
            if (playResult == 0 ||
                DAT_004A0293 != 0 ||
                DAT_004A0294 != 0 ||
                DAT_004A0295 != 0 ||
                DAT_004A2A80 != 0)
                break;
        } while (DAT_004A2A8C == 0);

        FUN_0040A660(blockAnims);
        FUN_00441110();
        FUN_00440830();
        FUN_00401B40(2);
        FUN_0041F6F0(blockAnims);
        levelOffset = levelOffset + 1;
    }

    FUN_004099B0(1);
    DAT_004A2A3C = 0;
    DAT_00455C3C = -1;
    FUN_004A2970 = 2;
}
}
