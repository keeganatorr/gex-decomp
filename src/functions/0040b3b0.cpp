// Adapted from pc_decomp_backup/src/functions/FUN_0040B3B0.cpp
// Historical source SHA256: 85061bf31ed7b64d1c3604318346d8f4bedd925bfd2c6d26b51e58a7bc2ebaf1
extern "C" {
extern "C" { extern int DAT_00462720; }
extern "C" { extern int DAT_0046272C; }
extern "C" { extern int DAT_00462738; }

extern "C" void __cdecl GEX_Target(int param_1)
{
    int* puVar1;
    int uVar2;
    int* puVar3;
    int iVar4;

    puVar1 = *(int**)(param_1 + 0x3c);
    uVar2 = puVar1[1];
    puVar3 = (int*)*puVar1;
    if (puVar1[2] == 0) {
        *(int*)*puVar3 = uVar2;
    }
    *(int*)(*(int*)*puVar3 + puVar1[2] * 4) = uVar2;
    iVar4 = puVar3[3];
    puVar3[3] = iVar4 + 1;
    if (iVar4 + 1 == puVar3[4]) {
        *(int*)puVar3[1] = puVar3[4] * 4 + *(int*)*puVar3 + 4;
    }
    puVar1[0x15] = 0;
    while (DAT_0046272C != DAT_00462738 &&
           *(int*)(0x00462740 + DAT_0046272C * 0x58 + 0x54) == 0) {
        DAT_0046272C = DAT_0046272C + 1;
        if (DAT_0046272C == 9) {
            DAT_0046272C = 0;
        }
        DAT_00462720 = DAT_00462720 - 1;
    }
}
}
