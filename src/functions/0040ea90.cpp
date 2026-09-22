struct DrawState {
    unsigned char unknown00[0x78];
    int x;
    int y;
    unsigned char unknown80[0x1c];
    char* text;
};

extern "C" {
void __cdecl FUN_0040C340(void**);
extern char* DAT_00487ff0;
extern char* DAT_00488000;
extern char* DAT_0048a010;
extern char* DAT_0048a018;
extern char* DAT_0048a01c;
extern char* DAT_00487ffc;
}

static inline char* EnterPasswordText() {
    return DAT_00488000;
}

extern "C" void __cdecl GEX_Target(DrawState* p) {
    char* text = DAT_00487ff0;
    p->x = 0x1e0000;
    p->y = 0x780000;
    p->text = text;
    FUN_0040C340((void**)p);
    text = EnterPasswordText();
    p->x = 0x820000;
    p->text = text;
    p->y = 0x780000;
    FUN_0040C340((void**)p);
    text = DAT_0048a010;
    p->x = 0x1e0000;
    p->text = text;
    p->y = 0x910000;
    FUN_0040C340((void**)p);
    text = DAT_0048a018;
    p->x = 0x820000;
    p->text = text;
    p->y = 0x910000;
    FUN_0040C340((void**)p);
    text = DAT_0048a01c;
    p->x = 0x1e0000;
    p->text = text;
    p->y = 0xaa0000;
    FUN_0040C340((void**)p);
    text = DAT_00487ffc;
    p->x = 0x820000;
    p->text = text;
    p->y = 0xaa0000;
    FUN_0040C340((void**)p);
}
