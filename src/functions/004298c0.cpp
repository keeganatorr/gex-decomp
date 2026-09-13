// Adapted from pc_decomp_backup/src/functions/FUN_004298C0.cpp
// Historical source SHA256: ff5fe012371949b162b3e471affd73e81c09f0bcf6a5ca7e11254fbda078e9fc
extern "C" {
extern "C" { extern char DAT_0045ABD9; }
extern "C" { extern char DAT_0045ABD8; }
extern "C" { extern unsigned int DAT_0045ABA8; }

extern "C" int __cdecl GEX_Target(unsigned char* param_1, char* param_2)
{
    char cVar1;
    unsigned int uVar3;
    unsigned int uVar4;
    unsigned int uVar5;

    uVar5 = 0;
    cVar1 = *param_2;
    while (cVar1 != '\0') {
        uVar4 = 0;
        cVar1 = DAT_0045ABD8;
        while (cVar1 != *param_2) {
            uVar4 = uVar4 + 1;
            cVar1 = *(&DAT_0045ABD9 + uVar4);
        }
        cVar1 = *(&DAT_0045ABD8 + (uVar4 >> 4));
        while (cVar1 != param_2[1]) {
            uVar4 = uVar4 + 0x10;
            cVar1 = *(&DAT_0045ABD8 + (uVar4 >> 4));
        }
        param_2 = param_2 + 2;
        uVar3 = uVar5 & 3;
        uVar5 = uVar5 + 1;
        *param_1 = ((unsigned char*)&DAT_0045ABA8)[uVar3] ^ (unsigned char)uVar4;
        param_1 = param_1 + 1;
        cVar1 = *param_2;
    }
    return uVar5 * 8;
}
}
