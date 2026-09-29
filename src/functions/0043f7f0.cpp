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
typedef struct Glyph {
    short u, v, w, h;
} Glyph;
typedef struct Font {
    int graphics;
    char *data;
    unsigned char first;
    unsigned char last;
    char pad0a[6];
    int spacing;
} Font;
typedef struct GXObject {
    char pad0[0x78];
    int xpos;
    int ypos;
    char pad80[0x174];
    int stamp;
    int lastX;
    int lastY;
} GXObject;
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
extern char *DAT_004a2adc_Tiles2;
extern char *PTR_004a2ae4;
extern char *DAT_004a2ae0_TilesBack1;
extern void **DAT_004a2b18_Draw1;
extern void **DAT_004a2b14_Draw4;
extern Font *DAT_004a2af4;
extern unsigned short DAT_0046a66c;
extern short DAT_004a2b20;
extern int DAT_0046a664;
extern int DAT_0046a668;
extern GXObject *DAT_00459414_Gex_Object_For_DrawText;
extern int gTimer_004a2ac8;
extern short DAT_004a2a96_CameraX_After;
extern short M1_004a2a94;
extern int gFontX_004a2af0;
extern int gFontY_004a2aec;
extern unsigned char DAT_004a2af8_InitUnk4;
extern unsigned char DAT_004a2af9_InitUnk5;
extern unsigned char DAT_004a2afa_InitUnk6;
int __cdecl abs(int);
unsigned short __cdecl FUN_0043ecf0_SelectTile_Clean1(int graphics);
void __cdecl FUN_00445350_CalculateTileOffset_Clean1(DR_MODE *p, int dfe, int dtd, int tpage, void *tw);
void __cdecl TXT_DrawPrint_0043f7f0(char *s)
{
    unsigned short clut;
    DR_MODE *dm;
    DR_MODE *src;
    SPRT *sp;
    SPRT *ssrc;
    Glyph *ch;
    GXObject *g;
    short dx;
    short dy;
    int c;
    int d;
    if (DAT_004a2adc_Tiles2 < PTR_004a2ae4 + 0x18) {
        PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x18;
        dm = (DR_MODE *)DAT_004a2ae0_TilesBack1;
    } else {
        PTR_004a2ae4 += 0x18;
        dm = (DR_MODE *)(PTR_004a2ae4 - 0x18);
    }
    clut = FUN_0043ecf0_SelectTile_Clean1(DAT_004a2af4->graphics);
    FUN_00445350_CalculateTileOffset_Clean1(dm, 0, 1, DAT_0046a66c, 0);
    DAT_004a2b20 = DAT_0046a66c;
    *DAT_004a2b18_Draw1 = dm;
    DAT_004a2b18_Draw1 = (void **)dm;
    dm++;
    *dm = dm[-1];
    *DAT_004a2b14_Draw4 = dm;
    DAT_004a2b14_Draw4 = (void **)dm;
    g = DAT_00459414_Gex_Object_For_DrawText;
    if (g && g->stamp - gTimer_004a2ac8 == -1) {
        d = g->xpos - g->lastX;
        if (d < 0)
            d += 0x10000;
        dx = (d >> 17) - DAT_004a2a96_CameraX_After;
        d = DAT_00459414_Gex_Object_For_DrawText->ypos - DAT_00459414_Gex_Object_For_DrawText->lastY;
        if (d < 0)
            d += 0x10000;
        dy = (d >> 17) - M1_004a2a94;
        if (abs(dy) + abs(dx) > 100) {
            dx = 0;
            dy = 0;
        }
    } else {
        dy = 0;
        dx = 0;
    }
    while (*s) {
        c = *s++;
        if (c >= 'a' && c <= 'z')
            c -= 0x20;
        if ((unsigned)c >= DAT_004a2af4->first && (unsigned)c <= DAT_004a2af4->last) {
            ch = (Glyph *)(DAT_004a2af4->data + 0x24) + (c - DAT_004a2af4->first);
            if (DAT_004a2adc_Tiles2 < PTR_004a2ae4 + 0x28) {
                PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + 0x28;
                sp = (SPRT *)DAT_004a2ae0_TilesBack1;
            } else {
                PTR_004a2ae4 += 0x28;
                sp = (SPRT *)(PTR_004a2ae4 - 0x28);
            }
            sp->code = 0x64;
            sp->x0 = gFontX_004a2af0;
            sp->y0 = gFontY_004a2aec;
            sp->w = ch->w;
            sp->h = ch->h;
            sp->r0 = DAT_004a2afa_InitUnk6;
            sp->g0 = DAT_004a2af9_InitUnk5;
            sp->b0 = DAT_004a2af8_InitUnk4;
            sp->u0 = ch->u + DAT_0046a664;
            sp->v0 = ch->v + DAT_0046a668;
            sp->clut = clut;
            *DAT_004a2b18_Draw1 = sp;
            DAT_004a2b18_Draw1 = (void **)sp;
            sp++;
            *sp = sp[-1];
            sp->x0 -= dx;
            sp->y0 -= dy;
            *DAT_004a2b14_Draw4 = sp;
            DAT_004a2b14_Draw4 = (void **)sp;
            gFontX_004a2af0 += DAT_004a2af4->spacing + ch->w;
        }
    }
}
}
