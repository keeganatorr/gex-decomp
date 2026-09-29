// The VC4 CRT expects _WinMain@16. Keep its adapter separate from the
// address-named reconstructed function so both identities remain explicit.
extern "C" int __stdcall WinMain_00405bf0(void *, void *, char *, int);

extern "C" int __stdcall WinMain(void *instance, void *previous,
                                   char *commandLine, int show)
{
    return WinMain_00405bf0(instance, previous, commandLine, show);
}
