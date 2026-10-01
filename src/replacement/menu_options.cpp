// Title menu extension, using the same sprite-font object and wave animation
// as Start/Password/Exit. The extra row does not require editing level assets.
extern "C" {
void *__cdecl GOB_FindWithWork0_0040c110(int, int);
void __cdecl PrintWithFont_0040bc70(int, int, int, int, int, int, char *, void *);
void __cdecl FUN_0040bc50_PrintStringInner(int);
int __cdecl FUN_0040c1a0(int, unsigned int);
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
int __cdecl GEX_WidescreenConfiguredWidth(void);
void __cdecl GEX_WidescreenRequest(int);
void __cdecl GEX_WidescreenPreviewWindow(int);
extern unsigned char GEX_DATA_004a0280[];
extern char GEX_DATA_00487fd4, GEX_DATA_0045633c;
extern int GEX_DATA_004a2964;
extern int GEX_DATA_00455c3c, GEX_DATA_00462c84, GEX_DATA_00456034;
}
static int opened;
static int currentItem;
static volatile int escapeRequested;
static int selection;
static int chosen;
static const int widths[] = {320, 384, 424, 560};
static char *labels[] = {"4:3", "16:10", "16:9", "21:9"};
static int &field(void *p, int offset) { return *(int *)((char *)p + offset); }
static void *button(int id) { return GOB_FindWithWork0_0040c110(0x7b, id); }
static void visibility(int hide)
{
    for (int i = 1; i <= 3; ++i) {
        void *p = button(i);
        if (p) {
            if (hide) field(p, 0xb4) |= 1;
            else field(p, 0xb4) &= ~1;
        }
    }
}
static void sound(void) { SND_PlaySoundNoPosition_0041a360(0x45, 0xff); }
static void text(void *font, int y, char *label, int selected)
{
    int flags = field(font, 0xb4);
    int lastX = field(font, 0x1f8), lastY = field(font, 0x1fc);
    field(font, 0xb4) &= ~1;
    PrintWithFont_0040bc70(field(font, 0x78), y << 16, 0x5b,
        1, 0x7b, selected ? GEX_DATA_00456034 : -1, label, font);
    field(font, 0xb4) = flags;
    field(font, 0x1f8) = lastX;
    field(font, 0x1fc) = lastY;
}
extern "C" void __cdecl GEX_MainMenuReset(void)
{
    opened = escapeRequested = selection = currentItem = 0;
    chosen = GEX_WidescreenConfiguredWidth();
    // Four evenly spaced rows fit above the bottom of the 224-line picture.
    void *p = button(1); if (p) field(p, 0x7c) = 162 << 16;
    p = button(3); if (p) field(p, 0x7c) = 182 << 16;
    p = button(2); if (p) field(p, 0x7c) = 222 << 16;
}
extern "C" void __cdecl GEX_MainMenuClose(void)
{
    opened=escapeRequested=selection=currentItem=0;
    chosen=GEX_WidescreenConfiguredWidth();
}
extern "C" int __cdecl GEX_MainMenuNavigate(int current, int direction)
{
    static const int order[] = {1, 3, 5, 2};
    int at = 0;
    for (int i = 0; i != 4; ++i) if (order[i] == current) at = i;
    if (current != 5) FUN_0040c1a0(current, 4);
    at = (at + (direction == 0x10 ? 3 : 1)) % 4;
    int next = order[at];
    if (next != 5) FUN_0040c1a0(next, 10);
    else GEX_DATA_00456034 = 0;
    return next;
}
extern "C" void __cdecl GEX_MainMenuOpenOptions(void)
{
    opened = 1;
    selection = 0;
    chosen = GEX_WidescreenConfiguredWidth();
    visibility(1);
    sound();
}
extern "C" int __cdecl GEX_MainMenuEscape(void)
{
    if (!opened) return 0;
    escapeRequested = 1;
    return 1;
}
static void closeOptions(void)
{
    opened = escapeRequested = 0;
    visibility(0);
    GEX_DATA_00462c84 = 0;
    if (chosen != GEX_WidescreenConfiguredWidth()) {
        GEX_WidescreenRequest(chosen);
        // Let the ordinary level and graphics teardown finish, then apply
        // before DRAW_Init rebuilds every cache reservation for the new width.
        GEX_DATA_00455c3c = -1;
    }
    sound();
}
extern "C" int __cdecl GEX_MainMenuOptions(void *controller)
{
    void *font = button(1);
    if (!font || !field(controller, 0xb0)) return 0;
    currentItem = field(controller, 0xb0);
    if (!opened) return 0;
    GEX_DATA_00462c84 = 0;
    unsigned char *keys = GEX_DATA_004a0280;
    int confirm = keys[0x14] || GEX_DATA_00487fd4 == 13;
    if (escapeRequested || keys[0x15]) { closeOptions(); return 1; }
    if (keys[0x11] || keys[0x12]) { selection ^= 1; sound(); }
    if (selection == 1 && confirm) { closeOptions(); return 1; }
    if (keys[0x0f] || keys[0x10] || (selection == 0 && confirm)) {
        int at = -1;
        for (int i = 0; i != 4; ++i) if (widths[i] == chosen) at = i;
        at = (at + (keys[0x0f] ? 3 : 1)) & 3;
        chosen = widths[at];
        GEX_WidescreenPreviewWindow(chosen);
        selection = 0;
        sound();
    }
    return 1;
}
// Queue custom text with the original menu buttons at their draw position.
extern "C" int __cdecl GEX_MainMenuDraw(void *gob)
{
    if (GEX_DATA_004a2964 != 63 || GEX_DATA_0045633c) return 0;
    if (field(gob, 0x98) != 1) return opened;
    void *font = gob;
    if (!opened) {
        if (currentItem && !(field(font, 0xb4) & 1)) {
            int active = currentItem == 5;
            text(font, 202, "Options", active);
            if (active) FUN_0040bc50_PrintStringInner(0x10000);
        }
        return 0;
    }
    char custom[12];
    char *label = custom;
    custom[0] = (char)('0' + chosen / 100);
    custom[1] = (char)('0' + chosen / 10 % 10);
    custom[2] = (char)('0' + chosen % 10);
    custom[3] = 'p'; custom[4] = 'x'; custom[5] = 0;
    for (int j = 0; j != 4; ++j) if (widths[j] == chosen) label = labels[j];
    text(font, 162, "Widescreen", selection == 0);
    text(font, 188, label, selection == 0);
    text(font, 222, "Back", selection == 1);
    FUN_0040bc50_PrintStringInner(0x10000);
    return 1;
}
