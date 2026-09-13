// Adapted from pc_decomp_backup/src/functions/FUN_00429850.cpp
// Historical source SHA256: 7b768da4d9eb4b617157030891ed48b6cd00114bf6f5ccddcab9b3795633f070
extern "C" {
extern "C" { extern unsigned char DAT_0045ABA8[]; }
extern "C" { extern const char DAT_0045ABD8[]; }

extern "C" void __cdecl GEX_Target(char* param_1, unsigned char* param_2, int param_3)
{
    unsigned int uVar6 = 0;
    char* pcVar3;
    if (0 < param_3) {
        unsigned int uVar5 = (unsigned int)(param_3 + 7) >> 3;
        do {
            unsigned int uVar4 = uVar6 & 3;
            pcVar3 = param_1 + 2;
            uVar6 = uVar6 + 1;
            unsigned char bVar1 = DAT_0045ABA8[uVar4];
            unsigned char bVar2 = *param_2;
            uVar5 = uVar5 - 1;
            *param_1 = DAT_0045ABD8[(bVar1 ^ bVar2) & 0xf];
            param_1[1] = DAT_0045ABD8[(unsigned char)((bVar1 ^ bVar2) >> 4)];
            param_1 = pcVar3;
            param_2 = param_2 + 1;
        } while (uVar5 != 0);
        *pcVar3 = '\0';
        return;
    }
    *param_1 = '\0';
}
}
