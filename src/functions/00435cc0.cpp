extern "C" {
extern void __cdecl FUN_0041A340(int*, int);
extern void __cdecl FUN_0041FA80(int);
extern int DAT_004593c0;
extern int DAT_004a2808;
extern int DAT_004642b0;
extern int DAT_004642ac;
void __cdecl CollectibleClid_00435cc0(int* param1, int* param2) {
    if (*param2 != 0 && param1[0x27] == 0) {
        FUN_0041A340(param1, 0xe3);
        DAT_004593c0++;
        DAT_004a2808++;
        DAT_004642b0++;
        DAT_004642ac = 0x14;
        param1[0x27] = 1;
        param1[0x14] = 0;
        param1[0x15] = 0;
        param1[0x1b] |= 0x80000;
        if (DAT_004642b0 >= 0x14) {
            FUN_0041FA80(0x54);
        }
        if (DAT_004642b0 >= 0xa) {
            FUN_0041FA80(0x41);
            return;
        }
        FUN_0041FA80(0x50);
        FUN_0041FA80(0x12);
    }
}
}