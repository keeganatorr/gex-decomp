extern "C" {
extern int DAT_00463b5c;
extern int INT_ARRAY_ARRAY_00463b10_4__0_[][2];
extern int DAT_00463b60;
extern unsigned long *DAT_004A27FC;
extern int DAT_004a2960_PausedUnk;
extern int DAT_004a2a04;
extern unsigned char DAT_004a24b0[];
extern int DAT_00458c8c;
extern int INT_ARRAY_ARRAY_00463b10_7__0_[][2];
extern int DAT_004A2964;
extern int FUN_00463B58;
extern int FUN_004A0210;
extern char s_ERROR_Couldn_t_create_bar_object_0045af24[];
extern char *STRING_TOENTERALEVEL_0048a028;

void __cdecl FUN_00419B80(unsigned long *, int);
unsigned long *__cdecl FUN_004195D0(int, int, int, int);
void __cdecl FUN_00405350(const char *);
void __cdecl FUN_00429CE0(void);
void __cdecl FUN_0042A690(void);
unsigned long __cdecl FUN_00429C90(void);
unsigned long __cdecl FUN_00428C60(void);
int __cdecl FUN_0041A590(int);
void __cdecl FUN_0041A630(int);
void __cdecl FUN_0041F8C0(int);
void __cdecl FUN_0041FA80(int);
void __cdecl FUN_0040D5F0(int, int, char *, int);
void __cdecl FUN_0040b950_VoiceInner(void);
}

extern "C" void __cdecl GEX_Target(unsigned long *PlayerClass)
{
    unsigned char bVar1;
    unsigned long *ppGVar2;
    volatile unsigned long *initialPlayer;
    unsigned long initialFlags;
    int iVar3;

    DAT_00463b5c = 4;
    INT_ARRAY_ARRAY_00463b10_4__0_[4][0] = 0;
    DAT_00463b60 = 0;

    initialPlayer = PlayerClass;
    initialPlayer[0x26] = 0;
    initialPlayer[0x2b] = 4;
    initialFlags = initialPlayer[0x2d];
    initialFlags &= 0x00ffffffUL;
    initialPlayer[0x2c] = 4;
    initialPlayer[0x2d] = initialFlags;
    initialPlayer[0x14] = 0x19;
    initialPlayer[0x28] = 8;
    FUN_00419B80(PlayerClass, 4);

    DAT_004A27FC = PlayerClass;
    DAT_004a2960_PausedUnk = 1;
    DAT_004a2a04 = 0;
    ppGVar2 = FUN_004195D0(0, 0, 0, (int)PlayerClass[3]);
    if (ppGVar2 == 0)
        FUN_00405350(s_ERROR_Couldn_t_create_bar_object_0045af24);

    ppGVar2[0x16] = 0;
    ppGVar2[0x17] = (unsigned long)&FUN_00429CE0;
    ppGVar2[0x18] = (unsigned long)&FUN_0042A690;
    FUN_00419B80(ppGVar2, 9);
    ppGVar2[0x26] = 0xffc00000UL;
    ppGVar2[0x29] = 0xffc00000UL;
    ppGVar2[0x2d] = FUN_00429C90();
    ppGVar2[0x2e] = 0xffffffffUL;

    for (iVar3 = 0; iVar3 < 0x90; ++iVar3) {
        bVar1 = (unsigned char)FUN_00428C60();
        DAT_004a24b0[iVar3] = (unsigned char)(bVar1 & 0x1f);
    }

    if (DAT_00458c8c == 0x1f) {
        iVar3 = FUN_0041A590(0x35);
        if (iVar3 == 0)
            FUN_0041A630(0x1003500);
    }

    iVar3 = FUN_0041A590(0x32);
    if (iVar3 != 0) {
        iVar3 = FUN_0041A590(0x31);
        if (iVar3 == 0)
            FUN_0041A630(0x1003100);
    }

    INT_ARRAY_ARRAY_00463b10_7__0_[7][0] = 0;
    PlayerClass[0x2d] &= 0xffff000fUL;
    FUN_0041F8C0(7);

    switch (PlayerClass[0x2d] & 0xfUL) {
    case 1:
        FUN_0041F8C0(8);
        iVar3 = 8;
        break;
    case 2:
        FUN_0041F8C0(0x2e);
        iVar3 = 0x2e;
        break;
    case 3:
        FUN_0041F8C0(0x1e);
        iVar3 = 0x1e;
        break;
    case 4:
    case 7:
        FUN_0041F8C0(0x39);
        iVar3 = 0x39;
        break;
    default:
        goto switch_done;
    case 6:
        FUN_0041F8C0(0x27);
        iVar3 = 0x27;
        break;
    }
    FUN_0041FA80(iVar3);

switch_done:
    if (DAT_004A2964 == 0x37 && FUN_00463B58 == 0 && FUN_004A0210 != 0) {
        FUN_00463B58 = 1;
        FUN_0040D5F0(0xa00000, 0x640000, STRING_TOENTERALEVEL_0048a028, 3);
    }

    FUN_0040b950_VoiceInner();
}
