// Adapted from pc_decomp_backup/src/functions/FUN_004097F0.cpp
// Historical source SHA256: 23abcf4fd9f2488930f708701b289dd19658c60a0a386b580fbb710c8d5367f8
extern "C" {
extern "C" { extern unsigned char DAT_00455B38; }
extern char* DAT_00455B40[];
extern "C" { extern char DAT_0047EF30; }
extern "C" { extern char DAT_0047EF6E; }
extern "C" { extern char DAT_0047EF6F; }
extern "C" int __cdecl FUN_00449AE0(int);

extern "C" void __cdecl GEX_Target(char param_1)
{
    char* pcVar4;
    char* pcVar6;
    char* pcVar1;
    int iVar7;
    unsigned int cheatIdx;

    iVar7 = 0x3f;
    do {
        *(&DAT_0047EF6F - (0x3f - iVar7)) = *(&DAT_0047EF6E - (0x3f - iVar7));
        iVar7 = iVar7 - 1;
    } while (iVar7 != 0);
    iVar7 = FUN_00449AE0((int)param_1);
    cheatIdx = 0;
    DAT_00455B38 = 0xb;
    DAT_0047EF30 = (char)iVar7;
    do {
        pcVar4 = &DAT_0047EF30;
        pcVar6 = DAT_00455B40[cheatIdx];
        if (*pcVar6 == '\0') {
            DAT_00455B38 = (unsigned char)cheatIdx;
        } else {
            do {
                if (*pcVar6 != *pcVar4) break;
                pcVar6 = pcVar6 + 1;
                pcVar4 = pcVar4 + 1;
            } while (*pcVar6 != '\0');
            if (*pcVar6 == '\0') {
                DAT_00455B38 = (unsigned char)cheatIdx;
            }
        }
        cheatIdx = cheatIdx + 1;
        if (cheatIdx > 10) return;
    } while (1);
}
}
