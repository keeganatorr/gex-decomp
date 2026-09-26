typedef struct Prim Prim;
struct Prim {
    Prim *tag;
    unsigned char r, g, b, code;
};
extern "C" {
extern unsigned char DAT_004a2af8_InitUnk4;
extern unsigned char DAT_004a2af9_InitUnk5;
extern unsigned char DAT_004a2afa_InitUnk6;
extern Prim *DAT_00460038_GraphicsDataPointer;
extern int DAT_004a2b00;
extern char s_PAL_WaitForFade_00460df4[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl FUN_00445140_InnerGraphics(Prim *list);
void __cdecl FUN_0043f310_InitializeGraphicsVariables(void);
void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int flag);
void __cdecl GEX_Target(void)
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    Prim *p;
    r = DAT_004a2afa_InitUnk6;
    g = DAT_004a2af9_InitUnk5;
    b = DAT_004a2af8_InitUnk4;
    TracePrintf_Debug_00405390(s_PAL_WaitForFade_00460df4);
    if (DAT_00460038_GraphicsDataPointer) {
        while (DAT_004a2b00) {
            p = DAT_00460038_GraphicsDataPointer;
            while (((unsigned int)p->tag & 0xffffff) != 0xffffff) {
                p = p->tag;
                if (p->code && p->code != 0xe1) {
                    if (r == p->r)
                        p->r = DAT_004a2afa_InitUnk6;
                    else
                        p->r = DAT_004a2afa_InitUnk6 * p->r / r;
                    if (g == p->g)
                        p->g = DAT_004a2af9_InitUnk5;
                    else
                        p->g = DAT_004a2af9_InitUnk5 * p->g / g;
                    if (b == p->b)
                        p->b = DAT_004a2af8_InitUnk4;
                    else
                        p->b = DAT_004a2af8_InitUnk4 * p->b / b;
                }
            }
            FUN_00445140_InnerGraphics(DAT_00460038_GraphicsDataPointer);
            r = DAT_004a2afa_InitUnk6;
            g = DAT_004a2af9_InitUnk5;
            b = DAT_004a2af8_InitUnk4;
            if (!DAT_004a2afa_InitUnk6)
                r = 1;
            if (!DAT_004a2af9_InitUnk5)
                g = 1;
            if (!DAT_004a2af8_InitUnk4)
                b = 1;
            FUN_0043f310_InitializeGraphicsVariables();
            FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(1);
        }
    }
}
}
