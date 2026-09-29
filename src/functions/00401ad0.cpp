extern "C" {
extern int gVFXEnabled_00455c0c;
extern int gDemoShowing_004a2a0c;
extern volatile int gVFXToPlay_0049a054;
extern int gVFXTable_0049a078[];
void __cdecl VFX_QueueToLoad_00401ad0(int vfx)
{
    if (gVFXEnabled_00455c0c && !gDemoShowing_004a2a0c && !gVFXToPlay_0049a054)
        gVFXToPlay_0049a054 = gVFXTable_0049a078[vfx];
}
}
