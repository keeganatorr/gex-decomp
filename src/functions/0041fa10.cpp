extern "C" {
extern int DAT_004638C0;
extern int DAT_004598B0;
extern int DAT_004638B0;
extern int DAT_004638B8;
extern int DAT_004638bc_VoiceInnerCounter;
extern int DAT_004638C4;
extern int DAT_004A02D0[];
extern int __cdecl FUN_004019C0(void);
extern int __cdecl FUN_0041FBA0(void);
}

extern "C" int __cdecl GEX_Target(void) {
    if (DAT_004638C0 != 0) {
        if (FUN_004019C0() == 0) return 0;
        int v = DAT_004638B0;
        int idx = DAT_004638B8;
        DAT_004638C0 = 0;
        int temp = DAT_004598B0;
        DAT_004A02D0[idx] = v;
        idx ^= 1;
        int sync = DAT_004638C4;
        DAT_004638bc_VoiceInnerCounter = temp;
        DAT_004638B8 = idx;
        if (sync != 0) {
            if (FUN_0041FBA0() != 0) {
                DAT_004638C4 = 0;
            }
        }
    }
    return 1;
}
