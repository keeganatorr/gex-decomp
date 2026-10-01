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

struct LevelName {
    const char *name;
    int level; // The level-select tables store one-based IDs.
};
extern "C" LevelName *GEX_DATA_0045a580[2];
extern "C" int GEX_DATA_0045a578[2];
extern "C" int GEX_DATA_004a2964, GEX_DATA_00455c3c;
extern "C" int GEX_DATA_004a281c, GEX_DATA_00456afc;
static int startupLevel = -1;

// Called after GEX_Run has initialized resources and the player, before its
// first level load. Consume the request once so later title visits work normally.
extern "C" void __cdecl GEX_StartupLevelApply(void)
{
    if (startupLevel < 0) return;
    GEX_DATA_004a2964 = startupLevel;
    GEX_DATA_00455c3c = 1;
    GEX_DATA_004a281c = GEX_DATA_00456afc = 3;
    startupLevel = -1;
}

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

static void writeError(const char *text, unsigned long length)
{
    unsigned long written;
    void *error = GetStdHandle((unsigned long)-12);
    if (error && error != (void *)-1)
        WriteFile(error, text, length, &written, 0);
}

static int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

static int findLevel(const char *name)
{
    for (int table = 0; table < 2; ++table) {
        for (int i = 0; i < GEX_DATA_0045a578[table] - 1; ++i) {
            LevelName &entry = GEX_DATA_0045a580[table][i];
            const char *a = name, *b = entry.name;
            // Ignore the menu's descriptive suffix, e.g. "grave7 (boss)".
            while (*a && *b && !isSpace(*b) && lower(*a) == lower(*b)) {
                ++a;
                ++b;
            }
            if (!*a && (!*b || isSpace(*b))) return entry.level - 1;
        }
    }
    return -1;
}

static void listLevels()
{
    static const char heading[] = "Available levels (use --level NAME):\r\n";
    writeError(heading, sizeof(heading) - 1);
    for (int table = 0; table < 2; ++table) {
        for (int i = 0; i < GEX_DATA_0045a578[table] - 1; ++i) {
            const char *name = GEX_DATA_0045a580[table][i].name;
            unsigned long length = 0;
            while (name[length]) ++length;
            writeError(name, length);
            writeError("\r\n", 2);
        }
    }
}

static int readLevel(char *&cursor)
{
    skipSpaces(cursor);
    int quoted = *cursor == '"';
    if (quoted) ++cursor;
    char name[96];
    unsigned int length = 0;
    while (*cursor && (quoted ? *cursor != '"' : !isSpace(*cursor))) {
        if (length == sizeof(name) - 1) return -1;
        name[length++] = *cursor++;
    }
    if (quoted) {
        if (*cursor != '"') return -1;
        ++cursor;
        if (*cursor && !isSpace(*cursor)) return -1;
    }
    name[length] = 0;
    return length ? findLevel(name) : -1;
}

static void showUsage()
{
    static const char usage[] =
        "Usage: GEX.exe [--level NAME | --attract 0|1|2] [--play-intro]\r\n"
        "       GEX.exe --list-levels\r\n"
        "Example: GEX.exe --level grave4\r\n"
        "Save states: 0-9 select slot, F5 save, F9 load.\r\n";
    writeError(usage, sizeof(usage) - 1);
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

    char *cursor = commandLine;
    if (cursor) skipSpaces(cursor);
    if (cursor && cursor[0] == '-' && cursor[1] == '-') {
        int demo = -1;
        int level = -1;
        int playIntro = 0;
        while (*cursor) {
            if (consumeOption(cursor, "--attract")) {
                skipSpaces(cursor);
                if (demo >= 0 || level >= 0 || *cursor < '0' || *cursor > '2' ||
                    (cursor[1] && !isSpace(cursor[1]))) {
                    showUsage();
                    return 2;
                }
                demo = *cursor++ - '0';
            } else if (consumeOption(cursor, "--level")) {
                if (level >= 0 || demo >= 0 || (level = readLevel(cursor)) < 0) {
                    static const char error[] =
                        "Invalid --level selection. Use --list-levels for names; "
                        "choose one of --level or --attract.\r\n";
                    writeError(error, sizeof(error) - 1);
                    showUsage();
                    return 2;
                }
            } else if (consumeOption(cursor, "--list-levels")) {
                listLevels();
                return 0;
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
        startupLevel = level;
        if (demo >= 0) GEX_DATA_00455c34 = demo + 4;
        static char skipIntroLine[] = "";
        static char playIntroLine[] = "X";
        commandLine = playIntro ? playIntroLine : skipIntroLine;
    }

    // Parse CLI options before asset selection, so help, listing and invalid
    // arguments work even when this executable is outside the game folder.
    if (!hasGameFiles() && !selectGameFolder()) return 0;

    return WinMain_00405bf0(instance, previous, commandLine, show);
}
