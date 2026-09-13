// Adapted from pc_decomp_backup/src/functions/FUN_0041BDE0.cpp
// Historical source SHA256: bb880c0fe18f7d5cdf691037d7c357e083ef158b3930f34dccda2c258f991a23
extern "C" {
extern "C" { extern int DAT_00456B00; }
extern "C" { extern int DAT_004A23C4; }
extern "C" { extern int DAT_004A2AD4; }
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void**, void**);

extern "C" void __cdecl GEX_Target(void** param_1, int ScoreToAdd, int param_3, int param_4)
{
    void** ppGVar1;

    ppGVar1 = (void**)FUN_004195D0(0x5d, (int)param_1[0x1e] + param_3 - 0x1c, (int)param_1[0x1f] + param_4 - 0x1c, DAT_004A2AD4);
    if (ppGVar1 != (void**)0x0) {
        ppGVar1[0x1b] = (void*)((unsigned int)ppGVar1[0x1b] | 0x8000);
        ppGVar1[0x24] = (void*)0x7fff0000;
        ppGVar1[0x23] = (void*)0xfffe0000;
        ppGVar1[0x25] = (void*)0x400;
        ppGVar1[0x26] = (void*)ScoreToAdd;
        FUN_00419BE0(ppGVar1, param_1);
        if (ScoreToAdd >= 0) goto add_score;
        if (DAT_00456B00 < 99) {
            DAT_00456B00 = DAT_00456B00 - ScoreToAdd;
        }
    }
    if (ScoreToAdd >= 0) {
add_score:
        DAT_004A23C4 = DAT_004A23C4 + ScoreToAdd;
    }
}
}
