typedef struct RezState { volatile int timer; int unk4; volatile int seed; volatile short count; short noise[255]; } RezState;
extern "C" {
extern RezState DAT_004642d8;
extern int gTimer_004a2ac8;
extern unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
void __cdecl GEX_Target(void)
{
    int i;
    short *noise;
    int v;
    if (gTimer_004a2ac8 != DAT_004642d8.timer) {
        DAT_004642d8.timer = gTimer_004a2ac8;
        DAT_004642d8.seed = 0xffffff01;
        DAT_004642d8.count = 0;
        noise = DAT_004642d8.noise;
        for (i = 255; i; i--)
            *noise++ = v = (UTL_ReallyRandom32_00428c60() & 1) ? 0 : 0x7fff;
    }
}
}
