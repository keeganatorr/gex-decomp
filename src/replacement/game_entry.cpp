// The VC4 CRT expects _WinMain@16. Keep its adapter separate from the
// address-named reconstructed function so both identities remain explicit.
extern "C" int __stdcall WinMain_00405bf0(void *, void *, char *, int);
extern "C" unsigned long __stdcall GetModuleFileNameA(void *, char *, unsigned long);
extern "C" int __stdcall SetCurrentDirectoryA(const char *);

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

    return WinMain_00405bf0(instance, previous, commandLine, show);
}
