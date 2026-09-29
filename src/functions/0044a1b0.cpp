// Adapted from pc_decomp_backup/src/functions/FUN_0044A1B0.cpp
// Historical source SHA256: 89eaec691a6bc707963e92b5b796b4ff300c377b80c1e735c598d14ece5542c6
extern "C" {
extern "C" { extern char DAT_004613a8; }

extern "C" void __cdecl FUN_0044a1b0_fpMathInnerInner(char* param_1)
{
    char cVar1;
    char* pcVar2;
    char* pcVar3;

    cVar1 = *param_1;
    while (cVar1 != '\0' && *param_1 != DAT_004613a8) {
        param_1++;
        cVar1 = *param_1;
    }
    pcVar2 = param_1 + 1;
    if (*param_1 != '\0') {
        cVar1 = *pcVar2;
        while (cVar1 != '\0' && *pcVar2 != 'e' && *pcVar2 != 'E') {
            pcVar2++;
            cVar1 = *pcVar2;
        }
        pcVar3 = pcVar2 - 1;
        cVar1 = *pcVar3;
        while (cVar1 == '0') {
            pcVar3--;
            cVar1 = *pcVar3;
        }
        if (*pcVar3 == DAT_004613a8) {
            pcVar3--;
        }
        do {
            cVar1 = *pcVar2;
            pcVar3++;
            pcVar2++;
            *pcVar3 = cVar1;
        } while (cVar1 != '\0');
    }
}
}
