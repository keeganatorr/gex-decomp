extern "C" void *gSFXTable_0049fb54;
extern "C" __declspec(dllimport) void *__stdcall GlobalFree(void *);

extern "C" void GEX_Target(void)
{
    if (gSFXTable_0049fb54 != (void *)0) {
        GlobalFree(gSFXTable_0049fb54);
        gSFXTable_0049fb54 = (void *)0;
    }
}
