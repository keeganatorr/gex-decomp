extern "C" {
void __cdecl SND_PlayPreviewSound_00401d00(int, int);
extern int DAT_0048a030;
void __cdecl GEX_Target(int param_1, int param_2)
{
    if (param_1 != 0) {
        int newVol = (param_1 * 5 - 500) * 5;
        if (newVol != DAT_0048a030) {
            DAT_0048a030 = newVol;
            if (param_2 != 0) { SND_PlayPreviewSound_00401d00(0x158, newVol); return; }
        }
    } else { DAT_0048a030 = -10000; }
}
}
