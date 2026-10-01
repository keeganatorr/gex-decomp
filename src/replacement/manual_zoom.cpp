// Replacement-only scene zoom. Commands are rasterized with the original
// renderers in viewport-sized tiles, then sampled into the visible frame.
// Texture/cache storage, simulation coordinates and HUD resolution are retained.
typedef unsigned int uint;
extern "C" {
int __cdecl GEX_WidescreenWidth(void);
void __cdecl FUN_00444dc0_InnerGraphics_Tiles(void *);
void __cdecl HUDDraw_0041b770(int);
void __cdecl HelpBoxDraw_0040d980(void *);
void __cdecl OBI_IntroduceObjects_0040f910(int *, int, int, int);
extern int GEX_DATA_004a2964, GEX_DATA_004a2a7c;
extern int GEX_DATA_004a2a38, GEX_DATA_004a2a1c;
extern int GEX_DATA_004a2974, GEX_DATA_004a2988;
extern int GEX_DATA_004a293c, GEX_DATA_004a2978;
extern uint *GEX_DATA_004a2b18, *GEX_DATA_004a2b14;
extern uint *GEX_DATA_004a2adc, *GEX_DATA_004a2ae0, *GEX_DATA_004a2ae4;
extern int *GEX_DATA_004a27fc;
extern unsigned short *GEX_DATA_004a33ac;
}
static volatile int requested = 0x10000;
static int factor = 0x10000;
static int drawing, ui, ready;
static int viewWidth, viewHeight, original[6], view[6];
static uint *start[2], *uiStart[2];
// At most 100 objects plus tile commands. Open addressing preserves command
// identity independently of the linked low/high-priority draw order.
static uint keys[32768];
static unsigned char kinds[32768];
static unsigned short scene[672 * 224];
// The original 70 KiB command ring wraps on a wide, zoomed-out tile field.
// Use frame-local storage while generating world commands; restore the original
// pool roots before overlays, state capture and the next simulation tick.
static uint commands[262144];
static uint *originalPool[3];

static int enabled(void)
{
    return GEX_DATA_004a2964 < 63 && !GEX_DATA_004a2a7c;
}
extern "C" int __cdecl GEX_ZoomFactor(void) { return factor; }
extern "C" int __cdecl GEX_ZoomRequested(void) { return requested; }
extern "C" int __cdecl GEX_ZoomKey(uint key, long flags)
{
    if (key != 0x6b && key != 0x6d && key != 0x60) return 0;
    if (!enabled()) return 0;
    // Consume repeats/key-up without applying another step.
    if (!(flags & 0x40000000)) {
        int value = GEX_ZoomRequested();
        if (key == 0x60) value = 0x10000;
        else value += key == 0x6b ? 0x2000 : -0x2000;
        if (value < 0x8000) value = 0x8000;
        if (value > 0x20000) value = 0x20000;
        requested = value;
    }
    return 1;
}
extern "C" void __cdecl GEX_ZoomBeginFrame(void)
{
    int delta = requested - factor;
    if (delta > -16 && delta < 16) factor = requested;
    else factor += delta / 4;
    ready = drawing = ui = 0;
    for (int i = 0; i < 32768; ++i) keys[i] = 0;
}
static int extent(int size)
{
    int scale = GEX_ZoomFactor();
    return (size * 0x10000 + scale - 1) / scale;
}
static int viewShift(int camera, int size, int virtualSize, int axis)
{
    int anchor = size / 2;
    // Regular cameras can place Gex near an edge, especially in widescreen.
    // Zoom around his screen position to keep him visible. Rez retains the
    // centre selected by its multi-target automatic camera.
    if (GEX_DATA_004a27fc && GEX_DATA_004a2964 != 27) {
        int player = (GEX_DATA_004a27fc[30 + axis] - camera) >> 16;
        if (player >= 0 && player < size) anchor = player;
    }
    return (anchor * 0x10000 / size) * (size - virtualSize);
}
extern "C" int __cdecl GEX_ZoomViewWidth(void)
{
    return drawing && !ui ? viewWidth : GEX_WidescreenWidth();
}
extern "C" int __cdecl GEX_ZoomViewHeight(void)
{
    return drawing && !ui ? viewHeight : 240;
}
extern "C" int __cdecl GEX_ZoomCullWidth(void)
{
    int width = GEX_WidescreenWidth();
    return enabled() && factor < 0x10000 ? extent(width) : width;
}
extern "C" int __cdecl GEX_ZoomCullHeight(void)
{
    return enabled() && factor < 0x10000 ? extent(240) : 240;
}
extern "C" int __cdecl GEX_ZoomCullX(void)
{
    int width = GEX_WidescreenWidth();
    int x = GEX_DATA_004a2a38 + viewShift(GEX_DATA_004a2a38, width, GEX_ZoomCullWidth(), 0);
    return x < 0 ? 0 : x;
}
extern "C" int __cdecl GEX_ZoomCullY(void)
{
    int y = GEX_DATA_004a2a1c + viewShift(GEX_DATA_004a2a1c, 240, GEX_ZoomCullHeight(), 1);
    return y < 0 ? 0 : y;
}
extern "C" void __cdecl GEX_ZoomIntroduce(int *tracker, int x, int y, int initialize)
{
    if (!enabled() || factor >= 0x10000) {
        OBI_IntroduceObjects_0040f910(tracker, x, y, initialize); return;
    }
    int width = tracker[11], height = tracker[12];
    tracker[11] = GEX_ZoomCullWidth() << 16;
    tracker[12] = GEX_ZoomCullHeight() << 16;
    // Rebuild the cursor bounds when zoom reveals stationary offscreen entries.
    OBI_IntroduceObjects_0040f910(tracker, GEX_ZoomCullX(), GEX_ZoomCullY(), 1);
    tracker[11] = width; tracker[12] = height;
}
static void cameras(int *values)
{
    GEX_DATA_004a2a38 = values[0]; GEX_DATA_004a2a1c = values[1];
    GEX_DATA_004a2974 = values[2]; GEX_DATA_004a2988 = values[3];
    GEX_DATA_004a293c = values[4]; GEX_DATA_004a2978 = values[5];
}
extern "C" void __cdecl GEX_ZoomBeginDraw(int *map)
{
    if (!enabled() || factor == 0x10000) return;
    viewWidth = extent(GEX_WidescreenWidth()); viewHeight = extent(240);
    original[0] = GEX_DATA_004a2a38; original[1] = GEX_DATA_004a2a1c;
    original[2] = GEX_DATA_004a2974; original[3] = GEX_DATA_004a2988;
    original[4] = GEX_DATA_004a293c; original[5] = GEX_DATA_004a2978;
    int x = original[2] + viewShift(original[2], GEX_WidescreenWidth(), viewWidth, 0);
    int y = original[3] + viewShift(original[3], 240, viewHeight, 1);
    int right = map[1] - (viewWidth << 16), bottom = map[2] - (viewHeight << 16);
    if (x > right) x = right; if (x < 0) x = 0;
    if (y > bottom) y = bottom; if (y < 0) y = 0;
    int dx = x - original[2], dy = y - original[3];
    for (int i = 0; i < 6; ++i) view[i] = original[i] + ((i & 1) ? dy : dx);
    cameras(view);
    start[0] = GEX_DATA_004a2b18; start[1] = GEX_DATA_004a2b14;
    originalPool[0] = GEX_DATA_004a2adc;
    originalPool[1] = GEX_DATA_004a2ae0;
    originalPool[2] = GEX_DATA_004a2ae4;
    GEX_DATA_004a2ae0 = GEX_DATA_004a2ae4 = commands;
    GEX_DATA_004a2adc = commands + 262144;
    drawing = 1;
}
static unsigned slot(uint address)
{
    unsigned i = (address >> 2) & 32767;
    while (keys[i] && keys[i] != address) i = (i + 1) & 32767;
    return i;
}
static void mark(uint *from, uint *to, unsigned char kind)
{
    uint *p = from;
    for (int n = 0; p != to && n < 16000; ++n) {
        uint next = *p;
        if ((next & 0xffffff) == 0xffffff || !next) break;
        p = (uint *)next;
        unsigned i = slot(next);
        if (kind == 2 || !keys[i]) kinds[i] = kind;
        keys[i] = next;
    }
}
extern "C" void __cdecl GEX_ZoomUIBegin(void)
{
    if (!drawing || ui) return;
    uiStart[0] = GEX_DATA_004a2b18; uiStart[1] = GEX_DATA_004a2b14;
    cameras(original); ui = 1;
}
extern "C" void __cdecl GEX_ZoomUIEnd(void)
{
    if (!drawing || !ui) return;
    mark(uiStart[0], GEX_DATA_004a2b18, 2);
    mark(uiStart[1], GEX_DATA_004a2b14, 2);
    cameras(view); ui = 0;
}
extern "C" void __cdecl GEX_ZoomObjectBegin(void *callback)
{
    if (callback == (void *)HUDDraw_0041b770 || callback == (void *)HelpBoxDraw_0040d980)
        GEX_ZoomUIBegin();
}
extern "C" void __cdecl GEX_ZoomObjectEnd(void) { GEX_ZoomUIEnd(); }
extern "C" void __cdecl GEX_ZoomEndDraw(void)
{
    if (!drawing) return;
    GEX_ZoomUIEnd();
    mark(start[0], GEX_DATA_004a2b18, 1);
    mark(start[1], GEX_DATA_004a2b14, 1);
    GEX_DATA_004a2adc = originalPool[0];
    GEX_DATA_004a2ae0 = originalPool[1];
    GEX_DATA_004a2ae4 = originalPool[2];
    cameras(original); drawing = 0; ready = 1;
}
static void dispatch(uint *command, int dx, int dy)
{
    unsigned char *data = (unsigned char *)command;
    int type = data[7];
    if (type == 0xe1) { FUN_00444dc0_InnerGraphics_Tiles(command); return; }
    uint copy[10];
    int words = (type == 0x2c || type == 0x2e) ? 10 :
                (type == 0x64 || type == 0x66) ? 5 :
                (type == 0x60 || type == 0x62) ? 4 : 3;
    for (int i = 0; i < words; ++i) copy[i] = command[i];
    short *xy = (short *)((unsigned char *)copy + 8);
    *xy -= (short)dx; xy[1] -= (short)dy;
    if (type == 0x2c || type == 0x2e) {
        for (int vertex = 1; vertex < 4; ++vertex) {
            xy = (short *)((unsigned char *)copy + 8 + vertex * 8);
            *xy -= (short)dx; xy[1] -= (short)dy;
        }
    }
    FUN_00444dc0_InnerGraphics_Tiles(copy);
}
static void drawList(uint *first, int dx, int dy, int hud)
{
    uint *command = first;
    while (((uint)command & 0xffffff) != 0xffffff) {
        unsigned i = slot((uint)command);
        int world = keys[i] && kinds[i] == 1;
        if (((unsigned char *)command)[7] == 0xe1 || (hud ? !world : world))
            dispatch(command, dx, dy);
        command = (uint *)*command;
    }
}
extern "C" int __cdecl GEX_ZoomRender(void *first)
{
    if (!ready || !enabled() || factor == 0x10000) return 0;
    int width = GEX_WidescreenWidth();
    unsigned short *pixels = GEX_DATA_004a33ac;
    // Render each world tile once; object callbacks/simulation are never replayed.
    for (int ty = 0; ty < viewHeight; ty += 224) {
        for (int tx = 0; tx < viewWidth; tx += width) {
            for (int row = 8; row < 232; ++row)
                for (int col = 0; col < width; ++col) pixels[row * 1024 + col] = 0;
            drawList((uint *)first, tx, ty - 8, 0);
            for (int y = 0; y < 224; ++y) {
                int sy = (y + 8) * 0x10000 / factor - ty;
                if (sy < 0 || sy >= 224) continue;
                for (int x = 0; x < width; ++x) {
                    int sx = x * 0x10000 / factor - tx;
                    if (sx >= 0 && sx < width)
                        scene[y * width + x] = pixels[(sy + 8) * 1024 + sx];
                }
            }
        }
    }
    for (int row2 = 0; row2 < 224; ++row2)
        for (int col2 = 0; col2 < width; ++col2)
            pixels[(row2 + 8) * 1024 + col2] = scene[row2 * width + col2];
    drawList((uint *)first, 0, 0, 1);
    return 1;
}
