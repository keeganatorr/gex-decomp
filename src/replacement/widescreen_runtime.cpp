// Viewport configuration for the source replacement. All image data is
// addressed through linker symbols; no original instruction offsets are used.
typedef unsigned long DWORD;
struct WindowRect { int left, top, right, bottom; };
extern "C" {
__declspec(dllimport) DWORD __stdcall GetEnvironmentVariableA(const char *, char *, DWORD);
__declspec(dllimport) int __stdcall VirtualProtect(void *, DWORD, DWORD, DWORD *);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
__declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char *, const char *, int, const char *);
__declspec(dllimport) int __stdcall WritePrivateProfileStringA(const char *, const char *, const char *, const char *);
__declspec(dllimport) int __stdcall AdjustWindowRect(WindowRect *, DWORD, int);
__declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
__declspec(dllimport) int __stdcall GetClientRect(void *, WindowRect *);
__declspec(dllimport) int __stdcall GetWindowRect(void *, WindowRect *);
__declspec(dllimport) long __stdcall GetWindowLongA(void *, int);
__declspec(dllimport) void * __stdcall GetMenu(void *);
__declspec(dllimport) int __stdcall AdjustWindowRectEx(WindowRect *, DWORD, int, DWORD);
__declspec(dllimport) int __stdcall IsZoomed(void *);
__declspec(dllimport) int __stdcall IsIconic(void *);
__declspec(dllimport) int __stdcall ShowWindow(void *, int);
__declspec(dllimport) int __stdcall SetWindowPos(void *, void *, int, int, int, int, unsigned int);
extern int GEX_DATA_0045103c;
extern int GEX_RDATA_0045000c, GEX_RDATA_00450018;
extern int GEX_DATA_00455b9c, GEX_DATA_00455ba0, GEX_DATA_00455ba4, GEX_DATA_00455ba8;
extern int GEX_DATA_00455bb4, GEX_DATA_00455bb8;
extern int GEX_DATA_00455bc4, GEX_DATA_00455bc8, GEX_DATA_00455bcc, GEX_DATA_00455bd0;
extern int GEX_DATA_00487a08;
extern int GEX_DATA_00487a04, GEX_DATA_00487768, GEX_DATA_00487f80;
extern int GEX_DATA_004a2964;
extern void *GEX_DATA_004875a0;
}
static int width = 320;
static int requested = 320;
static const char settings[] = ".\\gex-source.ini";

static unsigned number(const char *&p)
{
    unsigned n = 0;
    if (*p < '0' || *p > '9') return 0;
    while (*p >= '0' && *p <= '9') {
        if (n > 100000u) return 0;
        n = n * 10 + *p++ - '0';
    }
    return n;
}
static int parse(const char *p)
{
    unsigned n = number(p);
    if (*p == ':' || *p == 'x' || *p == 'X') {
        ++p;
        unsigned d = number(p);
        if (!d) return 0;
        n = (240u * n + d / 2) / d;
    }
    if (*p) return 0;
    return n >= 320 && n <= 672 ? (int)(n & ~3u) : 0;
}
static int setClip(int value)
{
    DWORD old;
    // These two values belong to the source image's read-only clip rectangle.
    if (!VirtualProtect(&GEX_RDATA_0045000c, 16, 4, &old)) return 0;
    GEX_RDATA_0045000c = value;
    GEX_RDATA_00450018 = value;
    DWORD ignored;
    VirtualProtect(&GEX_RDATA_0045000c, 16, old, &ignored);
    return 1;
}
static void cameraDefaults(void)
{
    int shift = (width - 320) << 15;
    GEX_DATA_00455b9c = GEX_DATA_00455bc4 = 0xb80000 + shift;
    GEX_DATA_00455ba0 = GEX_DATA_00455bc8 = 0xe80000 + shift;
    GEX_DATA_00455ba4 = GEX_DATA_00455bcc = 0x580000 + shift;
    GEX_DATA_00455ba8 = GEX_DATA_00455bd0 = 0x880000 + shift;
    GEX_DATA_00455bb4 = 0x880000 + shift;
    GEX_DATA_00455bb8 = 0xb80000 + shift;
}
extern "C" int __cdecl GEX_WidescreenConfiguredWidth(void) { return width; }
extern "C" int __cdecl GEX_WidescreenWidth(void)
{
    // The title is authored as a 320-pixel composition. Present it centered
    // in the wider window, while gameplay sees the full configured viewport.
    return GEX_DATA_004a2964 == 63 ? 320 : width;
}
extern "C" int __cdecl GEX_WidescreenCacheX(void) { return (width + 63) & ~63; }
extern "C" void __cdecl GEX_WidescreenPreviewWindow(int value)
{
    if (value < 320 || value > 672 || (value & 3)) return;
    // The menu runs on the game thread. Resize only on the window's thread.
    if (GEX_DATA_004875a0 &&
        !PostMessageA(GEX_DATA_004875a0, 0x8001, value, 0))
        OutputDebugStringA("Gex: could not queue viewport window resize.\r\n");
}
extern "C" void __cdecl GEX_WidescreenResizeWindow(int value)
{
    void *window = GEX_DATA_004875a0;
    if (!window || GEX_DATA_0045103c || value < 320 || value > 672 || (value & 3)) return;
    // A maximized window must be restored before its normal size can change.
    if (IsZoomed(window) || IsIconic(window)) ShowWindow(window, 9);
    WindowRect client, outer;
    if (!GetClientRect(window, &client) || !GetWindowRect(window, &outer)) return;
    int height = client.bottom - client.top;
    if (height <= 0) return;
    WindowRect desired = {0, 0, (value * height + 112) / 224, height};
    if (!AdjustWindowRectEx(&desired, (DWORD)GetWindowLongA(window, -16),
                           GetMenu(window) != 0, (DWORD)GetWindowLongA(window, -20))) return;
    int newWidth = desired.right - desired.left;
    int newHeight = desired.bottom - desired.top;
    int x = outer.left + (outer.right - outer.left - newWidth) / 2;
    if (!SetWindowPos(window, 0, x, outer.top, newWidth, newHeight, 0x14))
        OutputDebugStringA("Gex: could not resize viewport window.\r\n");
}
extern "C" void __cdecl GEX_WidescreenRequest(int value)
{
    if (value >= 320 && value <= 672 && !(value & 3)) requested = value;
}
extern "C" void __cdecl GEX_WidescreenApplyPending(void)
{
    // Called only after the previous game's objects have been unloaded and
    // before DRAW_Init rebuilds the cache and the font reserves its cells.
    if (requested == width) return;
    if (!setClip(requested)) {
        requested = width;
        GEX_WidescreenPreviewWindow(width);
        OutputDebugStringA("Gex: could not change the viewport clip rectangle.\r\n");
        return;
    }
    width = requested;
    cameraDefaults();
    char text[12];
    int n = width, count = 0;
    do { text[count++] = (char)('0' + n % 10); n /= 10; } while (n);
    text[count] = 0;
    for (int i = 0; i < count / 2; ++i) {
        char c = text[i]; text[i] = text[count - i - 1]; text[count - i - 1] = c;
    }
    WritePrivateProfileStringA("Display", "Width", text, settings);
    GEX_WidescreenPreviewWindow(width);
}
extern "C" void __cdecl GEX_WidescreenInit(void)
{
    int chosen = (int)GetPrivateProfileIntA("Display", "Width", 320, settings);
    if (chosen < 320 || chosen > 672 || (chosen & 3)) chosen = 320;
    char request[64];
    DWORD length = GetEnvironmentVariableA("GEX_WIDESCREEN", request, sizeof(request));
    if (length && length < sizeof(request)) {
        int parsed = parse(request);
        if (parsed) chosen = parsed;
        else OutputDebugStringA("Gex: invalid GEX_WIDESCREEN; using saved viewport.\r\n");
    }
    if (!setClip(chosen)) chosen = 320;
    width = requested = chosen;
    cameraDefaults();
    {
        int border = GEX_DATA_00487768 * 2;
        int oldClient = GEX_DATA_00487a04 - border;
        WindowRect rectangle = {0, 0, 320, 224};
        AdjustWindowRect(&rectangle, 0xcf0000, 1);
        int nonClientHeight = rectangle.bottom - rectangle.top - 224;
        int scale = (GEX_DATA_00487a08 - nonClientHeight) / 224;
        if (scale < 1) scale = 1;
        int newClient = width * scale;
        GEX_DATA_00487a04 = newClient + border;
        GEX_DATA_00487f80 -= (newClient - oldClient) / 2;
    }
}
