// Source-only link milestone. These are reconstructed game functions, compiled
// from src/functions with their Ghidra-based exported names.
extern "C" {
unsigned gNumPlayerBubbles_004a2854 = 4;
unsigned DAT_004639DC = 1;
unsigned DAT_004638C4 = 2;

void __cdecl FUN_00420D30(void);
unsigned __cdecl SCRIPT_UnforceVoiceSituation_00418e20(unsigned value);
}

int main()
{
    FUN_00420D30();
    return SCRIPT_UnforceVoiceSituation_00418e20(7) == 7 &&
           gNumPlayerBubbles_004a2854 == 3 &&
           DAT_004639DC == 0 && DAT_004638C4 == 0 ? 0 : 1;
}
