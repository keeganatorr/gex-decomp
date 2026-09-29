// Registry and window defaults reconstructed from SettingsGetFromRegistry.
// The source uses the checked-in image data through relocation-aware addresses.
typedef unsigned long DWORD;
typedef void *HKEY;
struct RegistryWindowRect { long left, top, right, bottom; };

extern "C" {
__declspec(dllimport) DWORD __stdcall GetVersion(void);
__declspec(dllimport) long __stdcall RegOpenKeyA(HKEY, const char *, HKEY *);
__declspec(dllimport) long __stdcall RegQueryValueExA(HKEY, const char *, DWORD *, DWORD *,
                                                       unsigned char *, DWORD *);
__declspec(dllimport) long __stdcall RegCloseKey(HKEY);
__declspec(dllimport) int __stdcall GetKeyNameTextA(long, char *, int);
__declspec(dllimport) int __stdcall GetSystemMetrics(int);
__declspec(dllimport) int __stdcall AdjustWindowRect(RegistryWindowRect *, DWORD, int);
double __cdecl atof(const char *);
}

static unsigned &registryWord(unsigned long address) { return *(unsigned *)address; }
static char *registryText(unsigned long address) { return (char *)address; }
static void registryRead(HKEY key, unsigned long name, unsigned long destination,
                         DWORD *type, DWORD *size)
{
    RegQueryValueExA(key, registryText(name), 0, type,
                     (unsigned char *)destination, size);
}

extern "C" void __cdecl SettingsGetFromRegistry_00408b60(void)
{
    DWORD typeAndSize[2] = {4, 4};
    HKEY key = 0;
    DWORD version = GetVersion();
    HKEY root = (HKEY)((version & 0x80000000UL) ? 0x80000002UL : 0x80000001UL);
    RegOpenKeyA(root, registryText(0x00455970), &key);

    unsigned char text[64];
    text[0] = 0;
    *(double *)0x004879f8 = 1.0;
    DWORD size = sizeof(text);
    RegQueryValueExA(key, registryText(0x00455968), 0, typeAndSize, text, &size);
    if (text[0]) *(double *)0x004879f8 = atof((char *)text);
    size = 0x18;
    RegQueryValueExA(key, registryText(0x0045595c), 0, typeAndSize,
                     (unsigned char *)0x00487750, &size);

    for (unsigned long entry = 0x004554a4; entry != 0x00455684; entry += 0x3c) {
        RegQueryValueExA(key, (char *)(entry + 8), 0, typeAndSize,
                         (unsigned char *)entry, typeAndSize + 1);
        GetKeyNameTextA(registryWord(entry) & 0xffff0000,
                        (char *)(entry - 20), 15);
    }
    for (unsigned long entry2 = 0x00455684; entry2 != 0x00455774; entry2 += 0x3c)
        RegQueryValueExA(key, (char *)(entry2 + 8), 0, typeAndSize,
                         (unsigned char *)entry2, typeAndSize + 1);

    registryWord(0x00455018) = 0;
    registryRead(key, 0x00455954, 0x00455018, typeAndSize, typeAndSize + 1);
    unsigned joystick = registryWord(0x00455018);
    if (joystick && joystick != 0xffffffffUL) registryWord(0x00455018) = 0xffffffffUL;

    RegistryWindowRect rectangle;
    rectangle.left = (GetSystemMetrics(0) - 320) / 2;
    rectangle.right = rectangle.left + 320;
    rectangle.top = (GetSystemMetrics(1) - 240) / 2;
    rectangle.bottom = rectangle.top + 224;
    AdjustWindowRect(&rectangle, 0xcf0000, 1);
    unsigned width = rectangle.right - rectangle.left;
    unsigned height = rectangle.bottom - rectangle.top;
    unsigned border = (width - 320) / 2;
    registryWord(0x00487a04) = width;
    registryWord(0x00487768) = border;
    registryWord(0x00487f80) = rectangle.left - border;
    registryWord(0x00487f84) = rectangle.top;
    registryWord(0x00487a08) = height;
    registryRead(key, 0x00455944, 0x00487a04, typeAndSize, typeAndSize + 1);
    registryRead(key, 0x00455934, 0x00487a08, typeAndSize, typeAndSize + 1);
    registryRead(key, 0x00455928, 0x00487f80, typeAndSize, typeAndSize + 1);
    registryRead(key, 0x0045591c, 0x00487f84, typeAndSize, typeAndSize + 1);
    int x = registryWord(0x00487f80);
    int y = registryWord(0x00487f84);
    if (x + (int)registryWord(0x00487a04) > GetSystemMetrics(0) ||
        y + (int)registryWord(0x00487a08) > GetSystemMetrics(1)) {
        registryWord(0x00487f80) = rectangle.left - border;
        registryWord(0x00487f84) = rectangle.top;
        registryWord(0x00487a04) = width;
        registryWord(0x00487a08) = height;
    }

    const unsigned long names[] = {0x0045590c, 0x004558fc, 0x004558ec,
                                   0x004558dc, 0x004558cc, 0x004558bc,
                                   0x004558a8};
    const unsigned long destinations[] = {0x0045500c, 0x00455010, 0x00455014,
                                          0x00455000, 0x00455004, 0x00455008,
                                          0x0045501c};
    const unsigned defaults[] = {100, 100, 80, 1, 1, 1, 1};
    for (unsigned index = 0; index != 7; ++index) {
        registryWord(destinations[index]) = defaults[index];
        registryRead(key, names[index], destinations[index], typeAndSize,
                     typeAndSize + 1);
    }
    RegCloseKey(key);
}
