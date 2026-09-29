extern "C" unsigned char DAT_00455B38;
extern "C" char* DAT_00455B40[];
extern "C" char DAT_0047EF30;
extern "C" unsigned char DAT_0047EF6E;
extern "C" unsigned char DAT_0047EF6F;
extern "C" int __cdecl _tolower(int);

extern "C" void __cdecl FUN_004097f0_ProcessCheatInputs(char param_1)
{
    char *pcVar1;
    unsigned char uVar2;
    unsigned char *puVar3;
    char *pcVar4;
    unsigned char *puVar5;
    char *pcVar6;
    int iVar7;
    unsigned int cheatStringToTest;

    puVar5 = &DAT_0047EF6F;
    puVar3 = &DAT_0047EF6E;
    iVar7 = 0x3f;
    do {
        uVar2 = *puVar3;
        puVar3 = puVar3 - 1;
        *puVar5 = uVar2;
        puVar5 = puVar5 - 1;
        iVar7 = iVar7 - 1;
    } while (iVar7 != 0);
    iVar7 = _tolower((int)param_1);
    cheatStringToTest = 0;
    DAT_00455B38 = 0xb;
    DAT_0047EF30 = (char)iVar7;
    do {
        pcVar4 = &DAT_0047EF30;
        pcVar6 = DAT_00455B40[cheatStringToTest];
        if (*pcVar6 == '\0') {
            DAT_00455B38 = (unsigned char)cheatStringToTest;
        } else {
            do {
                uVar2 = *(volatile unsigned char *)pcVar4;
                if (uVar2 != (unsigned char)*pcVar6) break;
                pcVar1 = pcVar6 + 1;
                pcVar6 = pcVar6 + 1;
                pcVar4 = pcVar4 + 1;
            } while (*pcVar1 != '\0');
            if (*pcVar6 == '\0') {
                DAT_00455B38 = (unsigned char)cheatStringToTest;
            }
        }
        cheatStringToTest = cheatStringToTest + 1;
    } while (cheatStringToTest < 11);
}