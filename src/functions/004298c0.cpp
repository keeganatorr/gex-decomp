extern "C" {
extern "C" { extern char DAT_0045ABD8; }
extern "C" { extern unsigned int DAT_0045ABA8; }

extern "C" int __cdecl FUN_004298c0_ProcessPasswordInput(unsigned char* param_1, char* param_2)
{
    char cVar1;
    char c2;
    unsigned int uVar3;
    unsigned int uVar4;
    unsigned int uVar5;
    unsigned int uVar6;

    uVar5 = 0;
    cVar1 = *param_2;
    while (cVar1 != '\0') {
        uVar4 = 0;
        cVar1 = DAT_0045ABD8;
        while (cVar1 != *param_2) {
            uVar4 = uVar4 + 1;
            cVar1 = *(&DAT_0045ABD8 + uVar4);
        }
        uVar3 = uVar4 >> 4;
        c2 = param_2[1];
        param_2 = param_2 + 1;
        while (*(&DAT_0045ABD8 + uVar3) != c2) {
            uVar4 = uVar4 + 0x10;
            uVar3 = uVar4 >> 4;
        }
        param_2 = param_2 + 1;
        uVar6 = uVar5 & 3;
        param_1 = param_1 + 1;
        uVar5 = uVar5 + 1;
        param_1[-1] = ((unsigned char*)&DAT_0045ABA8)[uVar6] ^ (unsigned char)uVar4;
        cVar1 = *param_2;
    }
    return uVar5 * 8;
}
}