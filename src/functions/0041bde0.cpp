extern "C" {
extern int DAT_00456B00;
extern int DAT_004A23C4;
extern int DAT_004A2AD4;
extern void** __cdecl FUN_004195D0(int, int, int, int);
extern void __cdecl FUN_00419BE0(void**, void**);

void __cdecl AddVisualScore_0041bde0(int* param_1, int ScoreToAdd, int param_3, int param_4)
{
    void** ppGVar1;

    ppGVar1 = (void**)FUN_004195D0(0xd7, param_1[0x1e] + param_3, param_1[0x1f] + param_4, DAT_004A2AD4);
    if (ppGVar1 != (void**)0x0) {
        ppGVar1[0x1b] = (void*)((unsigned int)ppGVar1[0x1b] | 0x8000);
        ppGVar1[0x24] = (void*)0x7fff0000;
        ppGVar1[0x23] = (void*)0xfffe0000;
        ppGVar1[0x25] = (void*)0x400;
        ppGVar1[0x26] = (void*)ScoreToAdd;
        FUN_00419BE0(ppGVar1, (void**)param_1);
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
