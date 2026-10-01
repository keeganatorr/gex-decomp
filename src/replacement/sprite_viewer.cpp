// Source-replacement inspection UI. Uses resolved level assets and the ordinary
// cel/cache/raster path; never instantiates scripts or changes animation data.
struct LoadObject { void ***anims; void *scripts; int version, count; int *last; };
struct Entry { LoadObject *object; int group, slot; };
extern "C" {
__declspec(dllimport) int __stdcall IsBadReadPtr(const void *, unsigned int);
__declspec(dllimport) unsigned long __stdcall GetTickCount(void);
int __cdecl GEX_WidescreenWidth(void);
void __cdecl FUN_0043f080_ResetGraphics_Clean1(int);
void __cdecl GOB_DisplayObject_00444590(void *);
void __cdecl FUN_004432c0_Graphics(void *);
void __cdecl GFX_DrawRectHelper_00428cc0(int, int, int, int, unsigned int, unsigned int);
void __cdecl TXT_DrawPrintP_0043fa70(int, int, char *, int);
int __cdecl _vsnprintf(char *, unsigned int, const char *, char *);
int __cdecl UpdateTimer_00405120(void);
void __cdecl CEL_DrawCels_0043db70(int);
void __cdecl GEX_StateDraw(void);
void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);
void __cdecl FUN_0040b2d0_InputProcessing(void);
void __cdecl FUN_0043db50_UpdateGraphicsState(void);
extern int GEX_DATA_004a2964, GEX_DATA_004a2974, GEX_DATA_004a2988;
extern int GEX_DATA_004a294c;
extern int GEX_DATA_004a2afc;
extern unsigned char GEX_DATA_004a2af8, GEX_DATA_004a2af9, GEX_DATA_004a2afa;
extern LoadObject *GEX_DATA_004a2ad4;
extern LoadObject *GEX_DATA_004a2a10;
extern void *GEX_DATA_004a2b18;
}
static Entry entries[512];
static int objectCount, objectIndex, animation, frame, totalFrames;
static int catalogErrors, playing, nativeSize, background;
static volatile int enabled, viewing;
// WndProc produces, the game thread consumes. Do not edit game assets or UI
// selection from the window thread. Ignore keyboard repeat for discrete steps.
static volatile unsigned readKey, writeKey;
static unsigned keys[32];
static unsigned long lastStep;
static void *catalogLevel;
extern "C" int __cdecl GEX_SpriteViewerActive(void) { return enabled || viewing; }
static int good(const void *p, unsigned bytes)
{
    return p && !((unsigned)p & 1) && !IsBadReadPtr(p, bytes);
}
extern "C" int __cdecl GEX_SpriteViewerKey(unsigned key, long flags)
{
    if (key != 0x77 && (!viewing || (key != 0x1b && key != 0x20 &&
        key != 0x25 && key != 0x27 && key != 0x26 && key != 0x28 &&
        key != 0x21 && key != 0x22 && key != 0x24 && key != 'B' && key != 'N')))
        return 0;
    if (!(flags & 0x40000000) && writeKey - readKey < 32) {
        keys[writeKey & 31] = key;
        ++writeKey;
    }
    return 1;
}
static int takeKey(void)
{
    if (readKey == writeKey) return 0;
    int key = keys[readKey & 31];
    ++readKey;
    return key;
}
extern "C" void __cdecl GEX_SpriteViewerReset(void)
{
    viewing = 0;
    catalogLevel = 0;
    objectCount = 0;
    playing = 0;
}
extern "C" void __cdecl GEX_SpriteViewerClose(void)
{
    enabled=0;
    readKey=writeKey;
    GEX_SpriteViewerReset();
}
static int animations(LoadObject *o)
{
    if (!good(o, sizeof(*o))) return 0;
    if (o->version) {
        if (o->count < 0 || o->count > 4096 ||
            !good(o->anims, o->count * 4) || !good(o->last, o->count * 4)) return 0;
        return o->count;
    }
    for (int n = 0; n < 4096; ++n) {
        if (!good(o->anims + n, 4)) return 0;
        if (!o->anims[n]) return n;
        if (!good(o->anims[n], 4)) return 0;
    }
    return 0;
}
static int frames(LoadObject *o, int a)
{
    if (a < 0 || a >= animations(o)) return 0;
    if (o->version) {
        if (o->last[a] < 0 || o->last[a] >= 16384) return 0;
        int n = o->last[a] + 1; // GetCurrentFrame accepts indices <= last[a].
        return n > 0 && n <= 16384 && good(o->anims[a], n * 4) ? n : 0;
    }
    for (int n = 0; n < 16384; ++n) {
        if (!good(o->anims[a] + n, 4)) return 0;
        if (!o->anims[a][n]) return n;
        if (!good(o->anims[a][n], 28)) return 0;
    }
    return 0;
}
static void add(LoadObject *o, int group, int slot)
{
    for (int n = 0; n < objectCount; ++n) if (entries[n].object == o) return;
    if (objectCount == 512 || !good(o, sizeof(*o))) { ++catalogErrors; return; }
    entries[objectCount].object = o;
    entries[objectCount].group = group;
    entries[objectCount++].slot = slot;
    int count = animations(o);
    if (!count) ++catalogErrors;
    for (int a = 0; a < count; ++a) {
        int nframes = frames(o, a);
        totalFrames += nframes;
        if (!nframes) ++catalogErrors;
    }
}
static void collect(void *level)
{
    objectCount = objectIndex = animation = frame = totalFrames = catalogErrors = 0;
    catalogLevel = level;
    // M1_ResolveMap resolves root+0x20 into groups of (load object, scripts).
    void *map = ((void **)level)[1];
    if (good(map, 0x24)) {
        LoadObject ***groups = *(LoadObject ****)((char *)map + 0x20);
        int g;
        for (g = 0; g < 512; ++g) {
            if (!good(groups + g, 4)) { ++catalogErrors; break; }
            if (!groups[g]) break;
            LoadObject **rows = (LoadObject **)groups[g];
            int s;
            for (s = 0; s < 512; ++s) {
                if (!good(rows + s * 2, 8)) { ++catalogErrors; break; }
                if (!rows[s * 2]) break;
                add(rows[s * 2], g, s);
            }
            if (s == 512) ++catalogErrors;
        }
        if (g == 512) ++catalogErrors;
    } else ++catalogErrors;
    // The player is loaded separately from the level's object groups.
    if (GEX_DATA_004a2ad4) add(GEX_DATA_004a2ad4, -1, 0);
    if (GEX_DATA_004a2a10) add(GEX_DATA_004a2a10, -2, 0);
}
static int wrap(int n, int count) { return count ? (n % count + count) % count : 0; }
static void step(int direction)
{
    if (!objectCount) return;
    LoadObject *o = entries[objectIndex].object;
    frame += direction;
    int count = frames(o, animation);
    if (frame < 0 || frame >= count) {
        animation += direction;
        if (animation < 0 || animation >= animations(o)) {
            objectIndex = wrap(objectIndex + direction, objectCount);
            o = entries[objectIndex].object;
            animation = direction > 0 ? 0 : animations(o) - 1;
        }
        if (animation < 0) animation = 0;
        frame = direction > 0 ? 0 : frames(o, animation) - 1;
        if (frame < 0) frame = 0;
    }
}
static void input(void)
{
    int key;
    while ((key = takeKey()) != 0) {
        if (key == 0x77) { enabled = !enabled; playing = 0; }
        else if (key == 0x1b) { enabled = 0; playing = 0; }
        else if (key == 0x20) { playing = !playing; lastStep = GetTickCount(); }
        else if (key == 'B') background = !background;
        else if (key == 'N') nativeSize = !nativeSize;
        else if (objectCount) {
            playing = 0;
            if (key == 0x25 || key == 0x27) step(key == 0x25 ? -1 : 1);
            else if (key == 0x21 || key == 0x22) {
                objectIndex = wrap(objectIndex + (key == 0x21 ? -1 : 1), objectCount);
                animation = frame = 0;
            } else if (key == 0x26 || key == 0x28) {
                animation = wrap(animation + (key == 0x26 ? -1 : 1), animations(entries[objectIndex].object));
                frame = 0;
            } else if (key == 0x24) objectIndex = animation = frame = 0;
        }
    }
}
// Keep formatting in the CRT: the reconstructed game formatter currently
// corrupts multi-digit debug labels. The glyph renderer itself is unchanged.
static void text(int y, const char *format, ...)
{
    char line[96];
    _vsnprintf(line, sizeof(line) - 1, format, (char *)(&format + 1));
    line[sizeof(line) - 1] = 0;
    TXT_DrawPrintP_0043fa70(8 * 65536, y * 65536, line, 0);
}
static void rect(int x, int y, int w, int h, unsigned colour)
{
    GFX_DrawRectHelper_00428cc0(x * 65536, y * 65536, w * 65536, h * 65536, colour, 0);
}
static char *drawFrame(int width, int *sizeX, int *sizeY)
{
    if (!objectCount) return "NO LOADED OBJECTS";
    LoadObject *o = entries[objectIndex].object;
    int na = animations(o);
    if (!na || animation >= na) return "INVALID ANIMATION TABLE";
    int nf = frames(o, animation);
    if (!nf || frame >= nf) return "INVALID FRAME TABLE";
    void *f = o->anims[animation][frame];
    if (!f) return "EMPTY FRAME SLOT";
    if (!good(f, 28)) return "INVALID FRAME";
    int **cels = *(int ***)((char *)f + 24);
    if (!cels) return "EMPTY FRAME - NO CEL LIST";
    int minX = 32767, minY = 32767, maxX = -32768, maxY = -32768, visible = 0;
    int c;
    for (c = 0; c < 1024; ++c) {
        if (!good(cels + c, 4)) return "INVALID CEL LIST";
        int *cel = cels[c];
        if (!cel) break;
        if (!good(cel, 20) || !good((void *)cel[2], 28)) return "INVALID IMAGE";
        int *img = (int *)cel[2];
        if (!*(short *)(img + 5)) continue;
        int w = img[0] >> 16, h = img[1] >> 16;
        if (w <= 0 || h <= 0 || w > 4096 || h > 4096) return "INVALID IMAGE SIZE";
        int x = (cel[0] >> 16) + ((cel[1] & 0x80000000) ? -(img[2] >> 16) : img[2] >> 16);
        int y = (short)cel[0] + ((cel[1] & 0x40000000) ? -(img[3] >> 16) : img[3] >> 16);
        if (x < minX) minX = x; if (y < minY) minY = y;
        if (x + w > maxX) maxX = x + w; if (y + h > maxY) maxY = y + h;
        ++visible;
    }
    if (c == 1024) return "CEL LIST LIMIT REACHED";
    if (!visible) return "EMPTY FRAME - NO IMAGE CELS";
    *sizeX = maxX - minX; *sizeY = maxY - minY;
    int scale = 65536;
    if (!nativeSize) {
        if (*sizeX > width - 16) scale = (width - 16) * 65536 / *sizeX;
        if (*sizeY * scale / 65536 > 120) scale = 120 * 65536 / *sizeY;
    }
    int object[0x204 / 4];
    for (int i = 0; i < sizeof(object) / 4; ++i) object[i] = 0;
    object[3] = (int)o;
    object[0x50 / 4] = animation; object[0x54 / 4] = frame;
    object[0x78 / 4] = GEX_DATA_004a2974 + width / 2 * 65536 - (minX + maxX) * scale / 2;
    object[0x7c / 4] = GEX_DATA_004a2988 + 112 * 65536 - (minY + maxY) * scale / 2;
    object[0xc8 / 4] = object[0xcc / 4] = scale;
    object[0xe0 / 4] = 0x1000000;
    void *before = GEX_DATA_004a2b18;
    if (scale == 65536) GOB_DisplayObject_00444590(object);
    else FUN_004432c0_Graphics(object);
    if (before == GEX_DATA_004a2b18) return "NO DRAW COMMANDS";
    return nativeSize && (*sizeX > width - 16 || *sizeY > 120) ? "NATIVE SIZE - MAY CLIP" : "";
}
extern "C" void __cdecl GEX_SpriteViewerMenu(void)
{
    input();
    text(64, "F8 SPRITE VIEWER: %s", enabled ? "ON" : "OFF");
}
extern "C" int __cdecl GEX_SpriteViewerTick(void *level)
{
    input();
    viewing = enabled;
    if (!enabled) {
        // Gameplay may replace a separately streamed idle object while closed.
        // Never reuse those pointers on the next opening, even in the same level.
        catalogLevel = 0;
        objectCount = 0;
        return 0;
    }
    if (catalogLevel != level) collect(level);
    if (playing && GetTickCount() - lastStep >= 160) { step(1); lastStep = GetTickCount(); }
    int width = GEX_WidescreenWidth();
    FUN_0043f080_ResetGraphics_Clean1(0);
    rect(0, 0, width, 240, 0x1084);
    rect(0, 48, width, 128, background ? 0x7fff : 0);
    // Inspection is full brightness, independent of a level's entry fade.
    int fade = GEX_DATA_004a2afc;
    unsigned char r = GEX_DATA_004a2af8, g = GEX_DATA_004a2af9, b = GEX_DATA_004a2afa;
    GEX_DATA_004a2afc = 0xffffff;
    GEX_DATA_004a2af8 = GEX_DATA_004a2af9 = GEX_DATA_004a2afa = 255;
    int sx = 0, sy = 0;
    char *status = drawFrame(width, &sx, &sy);
    // Cover overflow from native-size frames before drawing the labels.
    rect(0, 0, width, 48, 0x1084); rect(0, 176, width, 64, 0x1084);
    text(20, "SPRITES LEVEL %d  %s", GEX_DATA_004a2964, playing ? "PLAY" : "PAUSED");
    if (objectCount) {
        Entry e = entries[objectIndex];
        text(29, "OBJ %d/%d %s A%d/%d F%d/%d", objectIndex + 1, objectCount,
            e.group == -2 ? "IDLE" : e.group == -1 ? "GEX" : "LEVEL",
            animation, animations(e.object), frame, frames(e.object, animation));
    }
    text(38, "%d FRAMES  %dx%d %s  ERR %d", totalFrames, sx, sy, nativeSize ? "1:1" : "FIT", catalogErrors);
    text(180, "%s", status);
    text(189, "LEFT/RIGHT FRAME  UP/DOWN ANIM");
    text(198, "PGUP/DN OBJECT  SPACE PLAY  HOME FIRST");
    text(207, "B BACKGROUND  N FIT/1:1  F8/ESC CLOSE");
    text(216, "` LEVEL SELECT (VIEWER STAYS ON)");
    // F3's paused framebuffer must not cover the viewer or stall its input.
    int frozen = GEX_DATA_004a294c;
    GEX_DATA_004a294c = 0;
    GEX_StateDraw();
    int running = UpdateTimer_00405120();
    CEL_DrawCels_0043db70(running);
    FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(running);
    FUN_0040b2d0_InputProcessing();
    FUN_0043db50_UpdateGraphicsState();
    GEX_DATA_004a294c = frozen;
    GEX_DATA_004a2afc = fade;
    GEX_DATA_004a2af8 = r; GEX_DATA_004a2af9 = g; GEX_DATA_004a2afa = b;
    return 1;
}
