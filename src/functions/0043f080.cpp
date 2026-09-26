typedef struct DR_MODE {
    void *tag;
    unsigned int code[2];
} DR_MODE;
typedef struct SPRT {
    void *tag;
    unsigned char r0, g0, b0, code;
    short x0, y0;
    unsigned char u0, v0;
    unsigned short clut;
    short w, h;
} SPRT;
typedef struct RECT {
    short x, y, w, h;
} RECT;
typedef struct IMAGE {
    int f0;
    int f4;
    int f8;
    RECT rect;
} IMAGE;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern int decl_pad_15;
extern char *DAT_004a2adc_Tiles2;
extern char *PTR_004a2ae4;
extern char *DAT_004a2ae0_TilesBack1;
extern void **DAT_004a2b18_Draw1;
extern void **DAT_004a2b14_Draw4;
extern void **PTR_004a2b0c;
extern void **PTR_004a2b10;
extern unsigned int GraphicsModeCurrent;
extern char DAT_00460674_GraphicsUnk2;
extern int DAT_00460258;
extern int DAT_0046a534_StaticGraphics;
extern unsigned char DAT_004a2af8_InitUnk4;
extern unsigned char DAT_004a2af9_InitUnk5;
extern unsigned char DAT_004a2afa_InitUnk6;
extern unsigned char DAT_0046A5A1;
extern unsigned char DAT_0046A5A2;
extern unsigned char DAT_0046A5A3;
extern unsigned char DAT_0046A5FD;
extern unsigned char DAT_0046A5FE;
extern unsigned char DAT_0046A5FF;
IMAGE *__cdecl FUN_0043e580_Image_Clean1(void *image);
unsigned short __cdecl FUN_0043ecf0_SelectTile_Clean1(int graphics);
void __cdecl FUN_00445350_CalculateTileOffset_Clean1(DR_MODE *p, int dfe, int dtd, int tpage, void *tw);
void __cdecl GEX_Target(unsigned int mode)
{
    IMAGE *img;
    unsigned short clut;
    DR_MODE *dm;
    SPRT *sp;
    int x;
    int y;
    if (mode == GraphicsModeCurrent && DAT_00460674_GraphicsUnk2) {
        img = FUN_0043e580_Image_Clean1(&DAT_00460258);
        clut = FUN_0043ecf0_SelectTile_Clean1(DAT_0046a534_StaticGraphics);
        if (PTR_004a2ae4 + 0x18 > DAT_004a2adc_Tiles2) {
            PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x18;
            dm = (DR_MODE *)DAT_004a2ae0_TilesBack1;
        } else {
            PTR_004a2ae4 += 0x18;
            dm = (DR_MODE *)(PTR_004a2ae4 - 0x18);
        }
        FUN_00445350_CalculateTileOffset_Clean1(dm, 0, 1, (*(unsigned int *)&img->rect & 0x1000000) >> 20 | (int)(*(unsigned int *)&img->rect & 0x3c0 | 0x800) >> 6, 0);
        *DAT_004a2b18_Draw1 = dm;
        DAT_004a2b18_Draw1 = (void **)dm;
        dm[1] = dm[0];
        *DAT_004a2b14_Draw4 = &dm[1];
        DAT_004a2b14_Draw4 = (void **)&dm[1];
        for (x = 0; x < 0x140; x += 0x40) {
            for (y = 0; y < 0xf0; y += 0x20) {
                if (PTR_004a2ae4 + 0x28 > DAT_004a2adc_Tiles2) {
                    PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x28;
                    sp = (SPRT *)DAT_004a2ae0_TilesBack1;
                } else {
                    PTR_004a2ae4 += 0x28;
                    sp = (SPRT *)(PTR_004a2ae4 - 0x28);
                }
                sp->code = 0x64;
                sp->x0 = x;
                sp->y0 = y;
                sp->w = 0x40;
                sp->h = 0x20;
                sp->u0 = img->rect.x << 2;
                sp->v0 = img->rect.y;
                sp->clut = clut;
                sp->r0 = DAT_004a2afa_InitUnk6;
                sp->g0 = DAT_004a2af9_InitUnk5;
                sp->b0 = DAT_004a2af8_InitUnk4;
                *DAT_004a2b18_Draw1 = sp;
                DAT_004a2b18_Draw1 = (void **)sp;
                sp[1] = sp[0];
                *DAT_004a2b14_Draw4 = &sp[1];
                DAT_004a2b14_Draw4 = (void **)&sp[1];
            }
        }
    } else if (mode != GraphicsModeCurrent) {
        GraphicsModeCurrent = mode;
        DAT_00460674_GraphicsUnk2 = 0;
        DAT_0046A5A1 = DAT_0046A5FD = (mode >> 7) & 0xf8;
        DAT_0046A5A2 = DAT_0046A5FE = (mode >> 2) & 0xf8;
        DAT_0046A5A3 = DAT_0046A5FF = mode << 3;
    }
    PTR_004a2b0c = DAT_004a2b18_Draw1;
    PTR_004a2b10 = DAT_004a2b14_Draw4;
}
}
