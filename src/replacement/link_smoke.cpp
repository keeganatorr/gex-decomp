// Source-only link milestone. These are reconstructed game functions, compiled
// from src/functions with unique exported names by build-source-link-smoke.
extern "C" {
unsigned gNumPlayerBubbles_004a2854 = 4;
unsigned DAT_004639DC = 1;
unsigned DAT_004638C4 = 2;

void __cdecl GEX_FN_00420d30(void);
unsigned __cdecl GEX_FN_00418e20(unsigned value);
}

int main()
{
    GEX_FN_00420d30();
    return GEX_FN_00418e20(7) == 7 &&
           gNumPlayerBubbles_004a2854 == 3 &&
           DAT_004639DC == 0 && DAT_004638C4 == 0 ? 0 : 1;
}
