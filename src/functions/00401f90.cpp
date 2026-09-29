extern "C" void *gSFXTable_0049fb54;
extern "C" __declspec(dllimport) void *__stdcall GlobalFree(void *);

extern "C" void SND_Destroy_00401f90(void)
{
    if (gSFXTable_0049fb54 != (void *)0) {
        GlobalFree(gSFXTable_0049fb54);
        gSFXTable_0049fb54 = (void *)0;
    }
}
