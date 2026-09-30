// The VC4 CRT expects _WinMain@16. Keep its adapter separate from the
// address-named reconstructed function so both identities remain explicit.
extern "C" int __stdcall WinMain_00405bf0(void *, void *, char *, int);
extern "C" unsigned long __stdcall GetModuleFileNameA(void *, char *, unsigned long);
extern "C" int __stdcall SetCurrentDirectoryA(const char *);
extern "C" unsigned long __stdcall GetFileAttributesA(const char *);
extern "C" int __stdcall MessageBoxA(void *, const char *, const char *, unsigned int);
extern "C" void *__stdcall GetStdHandle(unsigned long);
extern "C" int __stdcall WriteFile(void *, const void *, unsigned long,
                                     unsigned long *, void *);

struct GexBrowseInfo {
    void *owner;
    void *root;
    char *displayName;
    const char *title;
    unsigned int flags;
    void *callback;
    long data;
    int image;
};

extern "C" void *__stdcall SHBrowseForFolderA(GexBrowseInfo *);
extern "C" int __stdcall SHGetPathFromIDListA(const void *, char *);
extern "C" void __stdcall CoTaskMemFree(void *);

// Reconstructed image data; values 4..6 are consumed by the title initializer
// before the normal three-entry recording cursor is used.
extern "C" int GEX_DATA_00455c34;

static int isDirectory(const char *path)
{
    unsigned long attributes = GetFileAttributesA(path);
    return attributes != 0xffffffffUL && (attributes & 0x10) != 0;
}

static int isFile(const char *path)
{
    unsigned long attributes = GetFileAttributesA(path);
    return attributes != 0xffffffffUL && (attributes & 0x10) == 0;
}

static int hasGameFiles()
{
    static const char *folders[] = {"AVI", "IDL", "LEV", "MUS", "SFX", "VFX"};
    for (unsigned int i = 0; i != sizeof(folders) / sizeof(folders[0]); ++i) {
        if (!isDirectory(folders[i])) return 0;
    }
    return isFile("IDL\\GEX000.IDL") && isFile("LOADER.WAV") &&
           isFile("GEX.exe");
}

static int selectGameFolder()
{
    for (;;) {
        char displayName[260];
        char selectedPath[260];
        GexBrowseInfo browse;
        browse.owner = 0;
        browse.root = 0;
        browse.displayName = displayName;
        browse.title = "Select the Gex folder containing the original GEX.exe";
        browse.flags = 0x241; // filesystem folders, modern dialog, no new-folder button
        browse.callback = 0;
        browse.data = 0;
        browse.image = 0;

        void *folder = SHBrowseForFolderA(&browse);
        if (!folder) return 0;
        int resolved = SHGetPathFromIDListA(folder, selectedPath);
        CoTaskMemFree(folder);
        if (!resolved) return 0;
        if (SetCurrentDirectoryA(selectedPath) && hasGameFiles()) return 1;
        MessageBoxA(0,
            "That folder does not contain the original GEX.exe and required game files. Please choose the Gex install folder.",
            "GEX", 0x10);
    }
}

static int isSpace(char value)
{
    return value == ' ' || value == '\t';
}

static void skipSpaces(char *&cursor)
{
    while (isSpace(*cursor)) ++cursor;
}

static int consumeOption(char *&cursor, const char *option)
{
    char *next = cursor;
    while (*option && *next == *option) {
        ++next;
        ++option;
    }
    if (*option || (*next && !isSpace(*next))) return 0;
    cursor = next;
    return 1;
}

static void showUsage()
{
    static const char usage[] =
        "Usage: GEX.exe [--attract 0|1|2] [--play-intro]\r\n";
    unsigned long written;
    void *error = GetStdHandle((unsigned long)-12);
    if (error && error != (void *)-1)
        WriteFile(error, usage, sizeof(usage) - 1, &written, 0);
}

extern "C" int __stdcall WinMain(void *instance, void *previous,
                                   char *commandLine, int show)
{
    // Gex opens its data files relative to the process directory. Direct
    // launches with an absolute EXE path can otherwise look for them beside
    // the caller's shell instead of beside the staged executable.
    char modulePath[1024];
    unsigned long length = GetModuleFileNameA(0, modulePath, sizeof(modulePath));
    if (length != 0 && length < sizeof(modulePath)) {
        while (length != 0) {
            --length;
            if (modulePath[length] == '\\' || modulePath[length] == '/') {
                modulePath[length] = '\0';
                SetCurrentDirectoryA(modulePath);
                break;
            }
        }
    }

    // The original game assets are resolved relative to the install folder.
    // If this executable was copied elsewhere, ask for that folder before the
    // reconstructed startup can show the generic file-read error dialog.
    if (!hasGameFiles() && !selectGameFolder()) return 0;

    char *cursor = commandLine;
    if (cursor) skipSpaces(cursor);
    if (cursor && cursor[0] == '-' && cursor[1] == '-') {
        int demo = -1;
        int playIntro = 0;
        while (*cursor) {
            if (consumeOption(cursor, "--attract")) {
                skipSpaces(cursor);
                if (demo >= 0 || *cursor < '0' || *cursor > '2' ||
                    (cursor[1] && !isSpace(cursor[1]))) {
                    showUsage();
                    return 2;
                }
                demo = *cursor++ - '0';
            } else if (consumeOption(cursor, "--play-intro")) {
                playIntro = 1;
            } else if (consumeOption(cursor, "--help")) {
                showUsage();
                return 0;
            } else {
                showUsage();
                return 2;
            }
            skipSpaces(cursor);
        }
        if (demo >= 0) GEX_DATA_00455c34 = demo + 4;
        static char skipIntroLine[] = "";
        static char playIntroLine[] = "X";
        commandLine = playIntro ? playIntroLine : skipIntroLine;
    }

    return WinMain_00405bf0(instance, previous, commandLine, show);
}
