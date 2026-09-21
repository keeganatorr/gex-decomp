extern "C" {
extern void __cdecl FUN_00401D00(int, int);
extern int DAT_0049FB20;
void __cdecl GEX_Target(int volume, int applyNow)
{
    if (volume != 0) {
        int newVol = (volume * 5 - 500) * 5;
        if (DAT_0049FB20 != newVol) {
            DAT_0049FB20 = newVol;
            if (applyNow != 0) { FUN_00401D00(0xe3, newVol); return; }
        }
    } else { DAT_0049FB20 = (int)0xffffd8f0; }
}
}
