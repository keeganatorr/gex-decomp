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
void __cdecl FUN_00405350(const char *, ...);
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

extern "C" void __cdecl GEX_Target(unsigned long *p)
{
    unsigned long *bar;
    int i;
    DAT_00463b5c = 4;
    INT_ARRAY_ARRAY_00463b10_4__0_[4][0] = 0;
    DAT_00463b60 = 0;
    p[0x26] = 0;
    p[0x2b] = 4;
    p[0x14] = 0x19;
    p[0x28] = 8;
    p[0x2c] = 4;
    p[0x2d] &= 0xffffff;
    FUN_00419B80(p, 4);
    DAT_004A27FC = p;
    DAT_004a2960_PausedUnk = 1;
    DAT_004a2a04 = 0;
    bar = FUN_004195D0(0, 0, 0, (int)p[3]);
    if (!bar)
        FUN_00405350(s_ERROR_Couldn_t_create_bar_object_0045af24);
    bar[0x16] = 0;
    bar[0x17] = (unsigned long)&FUN_00429CE0;
    bar[0x18] = (unsigned long)&FUN_0042A690;
    FUN_00419B80(bar, 9);
    bar[0x26] = 0xffc00000;
    bar[0x29] = 0xffc00000;
    bar[0x2d] = FUN_00429C90();
    bar[0x2e] = 0xffffffff;
    for (i = 0; i < 0x90; i++)
        DAT_004a24b0[i] = FUN_00428C60() & 0x1f;
    if (DAT_00458c8c == 0x1f && !FUN_0041A590(0x35))
        FUN_0041A630(0x1003500);
    if (FUN_0041A590(0x32) && !FUN_0041A590(0x31))
        FUN_0041A630(0x1003100);
    INT_ARRAY_ARRAY_00463b10_7__0_[7][0] = 0;
    p[0x2d] &= 0xffff000f;
    FUN_0041F8C0(7);
    switch (p[0x2d] & 0xf) {
    case 1:
        FUN_0041F8C0(8);
        FUN_0041FA80(8);
        break;
    case 2:
        FUN_0041F8C0(0x2e);
        FUN_0041FA80(0x2e);
        break;
    case 3:
        FUN_0041F8C0(0x1e);
        FUN_0041FA80(0x1e);
        break;
    case 4:
        FUN_0041F8C0(0x39);
        FUN_0041FA80(0x39);
        break;
    case 6:
        FUN_0041F8C0(0x27);
        FUN_0041FA80(0x27);
        break;
    case 7:
        FUN_0041F8C0(0x39);
        FUN_0041FA80(0x39);
        break;
    }
    if (DAT_004A2964 == 0x37 && !FUN_00463B58 && FUN_004A0210) {
        FUN_00463B58 = 1;
        FUN_0040D5F0(0xa00000, 0x640000, STRING_TOENTERALEVEL_0048a028, 3);
    }
    FUN_0040b950_VoiceInner();
}
